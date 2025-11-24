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

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player), day_count(1)
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
  else
  {
    return plots.at(row).at(column)->symbol();
  }
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
