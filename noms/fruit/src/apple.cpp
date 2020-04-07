#include "noms/fruit/apple.h"

namespace noms
{
    Apple::Apple(std::string colour)
        : colour(std::move(colour))
    {
    }

    std::string Apple::getColour() const
    {
        return colour;
    }
} // namespace noms
