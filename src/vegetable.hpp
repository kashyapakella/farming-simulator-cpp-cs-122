#pragma once

#include <string>
#include "plot.hpp"

class Vegetable : public Plot
{

protected:
    int days_grown;
    int days_to_sprout;
    int days_to_mature;
    bool watered;

public:
    Vegetable(int s, int m);
    virtual std::string adult_symbol() = 0;
    void grow(int passed_days = 1);
    void water();
    bool isSprout();
    bool isAdult();
    std::string symbol() override;
    bool isWatered();
};