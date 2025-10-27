#include <iostream>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farmprinter.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"

int main()
{
  Player player;
  Farm farm(10, 10, &player);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  std::string player_input;

  while (game_in_progress)
  {
    ansi_clear();
    std::cout << "Day: " << farm.get_day() << std::endl;
    std::cout << printer.pp() << std::endl;
    std::cout << "Controls: w - up, a - left, s - down, d - right, c - plant carrot, h - harvest, e - end day, q - quit" << std::endl;
    std::cin >> player_input;

    if (player_input == "q")
    {
      game_in_progress = false;
    }
    else if (player_input == "d")
    {
      player.move_right();
    }
    else if (player_input == "w")
    {
      player.move_up();
    }
    else if (player_input == "a")
    {
      player.move_left();
    }
    else if (player_input == "s")
    {
      player.move_down();
    }
    else if (player_input == "c")
    {
      Carrot *carrot = new Carrot();
      farm.plant(player.row(), player.column(), carrot);
    }
    else if (player_input == "e")
    {
      farm.end_day();
    }
    else if (player_input == "h")
    {

      farm.harvest(player.row(), player.column());
    }
    else
    {
      std::cout << "Invalid input. Please use the specified controls." << std::endl;
    }
  }
}