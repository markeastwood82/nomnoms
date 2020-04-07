#include "noms/fruit/apple.h"
#include "noms/veg/asparagus.h"

#include <iostream>

int main()
{
    noms::Apple apple{"red"};
    std::cout << "The apple is " << apple.getColour() << "\n";

    noms::Asparagus asparagus{"green"};
    std::cout << "The asparagus is " << asparagus.getColour() << "\n";

    return 0;
}
