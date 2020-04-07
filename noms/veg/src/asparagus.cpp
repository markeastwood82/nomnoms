#include "noms/veg/asparagus.h"

namespace noms
{
    Asparagus::Asparagus(std::string colour)
        : colour(std::move(colour))
    {
    }

    std::string Asparagus::getColour() const
    {
        return colour;
    }
} // namespace noms
