#pragma once

#include "vegetable.hpp"

class Lettuce : public Vegetable
{

public:
    Lettuce();
    std::string adult_symbol() override;
};