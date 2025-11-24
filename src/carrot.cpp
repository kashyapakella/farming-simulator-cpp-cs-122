#include <string>

#include "carrot.hpp"

Carrot::Carrot() : Vegetable(1, 2)
{
}

std::string Carrot::adult_symbol()
{

    return "V";
}
