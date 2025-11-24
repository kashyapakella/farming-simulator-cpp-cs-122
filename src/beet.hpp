#pragma once

#include "vegetable.hpp"

class Beet : public Vegetable
{

public:
    Beet();
    std::string adult_symbol() override;
};