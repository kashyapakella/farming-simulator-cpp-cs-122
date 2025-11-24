#pragma once

#include "vegetable.hpp"

class Brussels : public Vegetable
{

public:
    Brussels();
    std::string adult_symbol() override;
};