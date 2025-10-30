#include "searchable_array_bag.hpp"

bool searchable_array_bag::has(int a) const
{
    for (int i = 01 ; i <= this->size; ++i)
    {
        if ( this->data[i] == a ) { return true ;}
    }
    return false;
}
