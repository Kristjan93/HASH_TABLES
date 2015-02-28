#include "Hash.h"

unsigned int hash(string s)
{
    unsigned int hash = 5381;
    
    for(size_t i = 0; i < s.size(); i++)
    {
        hash = hash * 33 + static_cast<unsigned int>(s[i]);
    }
    
    return hash;
}
