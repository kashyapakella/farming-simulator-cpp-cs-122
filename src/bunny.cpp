#include "bunny.hpp"

#include <ctime>

Bunny::Bunny(int startR, int startC)
{
    row = startR;
    column = startC;
    hasEaten = false;
    srand(time(0));
}

std::string Bunny::symbol()
{

    return "U";
}

void Bunny::move()
{
    int direction = rand() % 4;
    if (direction == 0)
    {
        row--;
        return;
    }
    else if (direction == 1)
    {
        row++;
        return;
    }
    else if (direction == 2)
    {
        column--;
        return;
    }
    else if (direction == 3)
    {
        column++;
        return;
    }
}

void Bunny::eatVegetable()
{
    hasEaten = true;
}

void Bunny::runAway(int playerR, int playerC)
{
    if (row > playerR)
    {
        row += 4;
    }
    else if (row < playerR)
    {
        row -= 4;
    }

    if (column > playerC)
    {
        column += 4;
    }
    else if (column < playerC)
    {
        column -= 4;
    }
}

void Bunny::setPosition(int newR, int newC)
{
    row = newR;
    column = newC;
}

int Bunny::getColumn()
{
    return column;
}

int Bunny::getRow()
{
    return row;
}