#include "set.hpp"

set::set( void ) {}
set::~set(void ) {}
set::set( searchable_bag & other): bag(&other)
{
}
 
set & set::operator=( searchable_bag & other) 
{
    if (this->bag != &other)
    {
        *this->bag = other;
    }
    return *this ;
} 

bool set::has( int n) const
{
    return this->bag->has( n )  ;
}

void set::insert( int n )
{
    if (!this->bag->has( n ))
    {
        this->bag->insert( n ) ;
    }
}
void set::insert( int * a, int n )
{
    if (!this->bag->has( n ))
    {
        this->bag->insert(a,  n ) ;
    }
}

void set::print() const
{
    this->bag->print() ;
}

void set::clear() 
{
    this->bag->clear() ;
}
searchable_bag & set::get_bag( void ) const
{
	return *this->bag ;
}
