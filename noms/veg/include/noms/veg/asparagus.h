#ifndef _ASPARAGUS_H
#define _ASPARAGUS_H

#include <string>

namespace noms {
class Asparagus
{
public:
    Asparagus(const std::string &colour) : m_colour(colour) {}
    std::string getColour() const { return m_colour; }

private:
    const std::string m_colour;
};

} // namespace noms

#endif /* _ASPARAGUS_H */
