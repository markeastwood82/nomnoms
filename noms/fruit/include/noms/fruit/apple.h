#ifndef _APPLE_H
#define _APPLE_H

#include <string>

namespace noms {

class Apple
{
public:
    Apple(const std::string &colour);
    std::string getColour() const;

private:
    const std::string m_colour;
};

} // namespace noms

#endif /* _APPLE_H */
