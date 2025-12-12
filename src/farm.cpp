#include <string>
#include <vector>
#include <iostream>

#include "farm.hpp"
#include "soil.hpp"
#include "carrot.hpp"
#include "lettuce.hpp"
#include "spinach.hpp"
#include "brussels.hpp"
#include "beet.hpp"
#include "vegetable.hpp"
#include "bunny.hpp"

Farm::Farm(int rows, int columns, Player *player, int bunnyChance) : rows(rows), columns(columns), player(player), day_count(1), bunny_chance(bunnyChance)
{
  for (int i = 0; i < rows; i++)
  {
    std::vector<Plot *> row;
    for (int j = 0; j < columns; j++)
    {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
  }
}

int Farm::number_of_rows()
{
  return rows;
}

int Farm::number_of_columns()
{
  return columns;
}

std::string Farm::get_symbol(int row, int column)
{
  if (player->row() == row && player->column() == column)
  {
    return "@";
  }
  for (int i = 0; i < bunnies.size(); i++)
  {
    if (bunnies[i]->getRow() == row && bunnies[i]->getColumn() == column)
    {
      if (abs(bunnies[i]->getRow() - player->row()) <= 1 && abs(bunnies[i]->getColumn() - player->column()) <= 1)
      {
        bunnies[i]->runAway(player->row(), player->column());
        return ".";
      }

      return bunnies[i]->symbol();
    }
  }

  return plots[row][column]->symbol();
}

void Farm::plant(int row, int column, Plot *plot)
{

  if (plots[row][column]->symbol() != ".")
  {

    std::cout << "This plot is occupied!" << std::endl;
    return;
  }
  Plot *current_plot = plots.at(row).at(column);
  plots.at(row).at(column) = plot;
  delete current_plot;
}

void Farm::harvest(int row, int column)
{

  Vegetable *veg = dynamic_cast<Vegetable *>(plots[row][column]);

  if (!veg)
  {
    std::cout << "There is nothing to harvest here!" << std::endl;
    return;
  }

  if (veg->isAdult())
  {
    std::cout << "Harvested." << std::endl;
    delete veg;
    plots[row][column] = new Soil();
  }
  else
  {
    std::cout << "Not mature yet." << std::endl;
  }
}

void Farm::end_day()
{

  day_count++;
  spawnBunnies();
  moveBunnies();
  checkBunny();

  for (int i = 0; i < rows; i++)
  {

    for (int j = 0; j < columns; j++)
    {

      Vegetable *v = dynamic_cast<Vegetable *>(plots[i][j]);

      int amount;

      if (v)
      {
        int amount = 1;

        if (v->isWatered())
        {
          amount = 2;
        }
        v->grow(amount);
      }
    }
  }
}

int Farm::get_day()
{

  return day_count;
}

void Farm::water(int row, int column)
{

  Vegetable *veg = dynamic_cast<Vegetable *>(plots[row][column]);

  if (!veg)
  {
    std::cout << "There is nothing here to water.";
    return;
  }

  veg->water();
}

void Farm::spawnBunnies()
{

  if (rand() % 100 < bunny_chance)
  {
    int edge = rand() % 4;
    int spawnR = 0;
    int spawnC = 0;

    if (edge == 0)
    {
      spawnR = 0;
      spawnC = rand() % columns;
    }
    else if (edge == 1)
    {
      spawnR = rows - 1;
      spawnC = rand() % columns;
    }
    else if (edge == 2)
    {
      spawnR = rand() % rows;
      spawnC = 0;
    }
    else if (edge == 3)
    {
      spawnR = rand() % rows;
      spawnC = columns - 1;
    }

    Bunny *newBunny = new Bunny(spawnR, spawnC);
    bunnies.push_back(newBunny);
  }
}

void Farm::moveBunnies()
{
  for (int i = 0; i < bunnies.size(); i++)
  {

    bunnies[i]->move();

    int c = bunnies[i]->getColumn();
    int r = bunnies[i]->getRow();

    if (r < 0 || r >= rows || c < 0 || c >= columns)
    {
      delete bunnies[i];
      bunnies.erase(bunnies.begin() + i);
    }
    else
    {

      i++;
    }
  }
}

void Farm::checkBunny()
{
  for (int i = 0; i < bunnies.size(); i++)
  {
    int bunnyR = bunnies[i]->getRow();
    int bunnyC = bunnies[i]->getColumn();

    if (bunnyR < 0 || bunnyR >= rows || bunnyC < 0 || bunnyC >= columns)
    {
      continue;
    }

    if (abs(bunnyR - player->row()) <= 1 && abs(bunnyC - player->column()) <= 1)
    {

      bunnies[i]->runAway(player->row(), player->column());
      continue;
    }

    Vegetable *v = dynamic_cast<Vegetable *>(plots[bunnyR][bunnyC]);
    if (v)
    {
      bunnies[i]->eatVegetable();
      plots[bunnyR][bunnyC] = new Soil();
    }
  }
}
