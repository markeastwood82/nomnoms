#include "noms/fruit/apple.h"

namespace noms {

Apple::Apple(std::string colour) {
    this->colour = colour;
}

std::string Apple::getColour() {
    return colour;
}

}
