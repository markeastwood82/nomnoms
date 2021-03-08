#include "noms/fruit/apple.h"

namespace noms {

Apple::Apple(const std::string &colour) : m_colour(colour) {}

std::string Apple::getColour() const { return m_colour; }

} // namespace noms
