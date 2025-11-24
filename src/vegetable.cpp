#include "vegetable.hpp"

Vegetable::Vegetable(int s, int m)
{

    days_grown = 0;
    days_to_sprout = s;
    days_to_mature = m;
    watered = false;
}

void Vegetable::grow(int passed_days)
{

    days_grown += passed_days;
    watered = false;
}

void Vegetable::water()
{
    watered = true;
}

bool Vegetable::isSprout()
{
    bool output = days_grown >= days_to_sprout && days_grown < days_to_mature;

    return output;
}

bool Vegetable::isAdult()
{
    bool output = days_grown >= days_to_mature;
    return output;
}

std::string Vegetable::symbol()
{

    if (isAdult())
    {
        return adult_symbol();
    }
    if (isSprout())
    {
        return "'";
    }

    return "-";
}

bool Vegetable::isWatered()
{
    return watered;
}
