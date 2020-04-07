#ifndef _ASPARAGUS_H
#define _ASPARAGUS_H

#include <string>

namespace noms
{
    class Asparagus
    {
    public:
        Asparagus(std::string colour);
        std::string getColour() const;

    private:
        std::string colour;
    };
} // namespace noms

#endif /* _ASPARAGUS_H */
