#ifndef _APPLE_H
#define _APPLE_H

#include <string>

namespace noms {

class Apple
{
public:
    Apple(std::string colour);
    std::string getColour();
private:
    std::string colour;
};

}

#endif /* _APPLE_H */
