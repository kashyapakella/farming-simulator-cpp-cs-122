#include <string>

#include "carrot.hpp"

Carrot::Carrot()
{

    is_mature = false;
}

std::string Carrot::symbol()
{
    if (is_mature)
    {

        return "V";
    }
    else
    {
        return "v";
    }
}

void Carrot::grow()
{

    if (!is_mature)
    {
        is_mature = true;
    }
}

bool Carrot::isMature() const
{

    return is_mature;
}