#include <string>
#include <vector>
#include <iostream>

#include "farm.hpp"
#include "soil.hpp"
#include "carrot.hpp"

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

  Carrot *carrot = dynamic_cast<Carrot *>(plots[row][column]);

  std::cout << carrot->isMature() << std::endl;
  if (carrot && carrot->isMature())
  {
    delete carrot;
    plots[row][column] = new Soil();
  }
  else
  {
    std::cout << "The carrot is not ready to harvest." << std::endl;
  }
}

void Farm::end_day()
{

  day_count++;

  for (int i = 0; i < rows; i++)
  {

    for (int j = 0; j < columns; j++)
    {

      Plot *current_plot = plots[i][j];

      if (current_plot && dynamic_cast<Carrot *>(current_plot))
      {

        Carrot *carrot = dynamic_cast<Carrot *>(current_plot);
        carrot->grow();
      }
    }
  }
}

int Farm::get_day()
{

  return day_count;
}
