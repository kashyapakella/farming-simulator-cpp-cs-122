#pragma once

#include <string>

#include "plot.hpp"

class Carrot : public Plot
{

private:
    bool is_mature;

public:
    Carrot();
    std::string symbol() override;
    void grow();
    bool isMature() const;
};