#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"
#include "bunny.hpp"

class Farm
{
private:
    int rows;
    int columns;
    int day_count;
    Player *player;
    std::vector<std::vector<Plot *>> plots;
    std::vector<Bunny *> bunnies;
    int bunny_chance;

public:
    Farm(int rows, int columns, Player *player, int bunnyChance = 10);
    int number_of_rows();
    int number_of_columns();
    std::string get_symbol(int row, int column);
    void plant(int row, int column, Plot *plot);
    void end_day();
    int get_day();
    void harvest(int row, int column);
    void water(int row, int column);
    void spawnBunnies();
    void moveBunnies();
    void checkBunny();
};
