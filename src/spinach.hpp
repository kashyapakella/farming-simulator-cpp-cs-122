#pragma once

#include "vegetable.hpp"

class Spinach : public Vegetable
{

public:
    Spinach();
    std::string adult_symbol() override;
};