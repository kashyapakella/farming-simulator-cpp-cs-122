#pragma once
#include "plot.hpp"
#include <string>

class Bunny : public Plot
{

private:
    int row;
    int column;
    bool hasEaten;

public:
    Bunny(int startR, int startC);
    std::string symbol() override;
    void move();
    void eatVegetable();
    void runAway(int playerR, int playerC);
    void setPosition(int newR, int newC);
    int getRow();
    int getColumn();
};