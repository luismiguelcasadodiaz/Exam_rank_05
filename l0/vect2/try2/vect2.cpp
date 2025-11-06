#include "vect2.hpp"
#include <string>
#include <sstream>
#include <stdexcept>


vect2::vect2( void ) : x(0), y(0)
{
}

vect2::~vect2( void )
{
}

vect2::vect2( vect2 const & other )
{
	this->x = other.get_x() ;
	this->y = other.get_y() ;
}

vect2 & vect2::operator=( vect2 const & other )
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this ;
}

vect2::vect2( int const a, int const b): x(a), y(b)
{
}

int vect2::get_x( void ) const 
{
	return this->x;
}

int vect2::get_y( void ) const 
{
	return this->y;
}


vect2 & vect2::operator+=( vect2 const & rhs )
{
	this->x += rhs.x ; 
	this->y += rhs.y ; 
	return *this;
}

vect2 & vect2::operator-=( vect2 const & rhs )
{
	this->x -= rhs.x ; 
	this->y -= rhs.y ; 
	return *this;
}

vect2 & vect2::operator*=( vect2 const & rhs )
{
	this->x *= rhs.x ; 
	this->y *= rhs.y ; 
	return *this;
}

vect2 vect2::operator+( vect2 const & rhs ) const
{
	vect2 result(*this) ;
	result += rhs ;
	return result ;
}

vect2 vect2::operator-( vect2 const & rhs ) const
{
	vect2 result(*this) ;
	result -= rhs ;
	return result ;
}

vect2 vect2::operator*( vect2 const & rhs ) const 
{
	vect2 result(*this) ;
	result *= rhs ;
	return result ;
}

vect2 & vect2::operator+=( int rhs )
{
	this->x += rhs ; 
	this->y += rhs ; 
	return *this;
}

vect2 & vect2::operator-=( int rhs )
{
	this->x -= rhs ; 
	this->y -= rhs ; 
	return *this;
}

vect2 & vect2::operator*=( int rhs )
{
	this->x *= rhs ; 
	this->y *= rhs ; 
	return *this;
}

vect2 vect2::operator+( int rhs ) const
{
	vect2 result(*this);
	result += rhs ;
	return result ;
}

vect2 vect2::operator-( int rhs ) const
{
	vect2 result(*this);
	result -= rhs ;
	return result ;
}

vect2 vect2::operator*( int rhs ) const
{
	vect2 result(*this);
	result *= rhs ;
	return result ;
}

vect2 & vect2::operator++()
{
	++(this->x) ;
	++(this->y) ;
	return *this ;
}

vect2 vect2::operator++( int )
{
	vect2 result(*this) ;
	++(*this) ;
	return result ;
}

vect2 & vect2::operator--()
{
	--(this->x) ;
	--(this->y) ;
	return *this ;
}

vect2 vect2::operator--( int )
{
	vect2 result(*this) ;
	--(*this) ;
	return result ;
}

int vect2::operator[]( size_t idx ) const
{
	if (idx > 1)
	{
		std::stringstream ss;
		ss << idx ;
		std::string msg = "Index " + ss.str() + " out of range " +
			"in vector of size 2" ;
		throw std::out_of_range(msg);
	}
	if ( idx == 0 )
	{
		return this->x ;
	}
		return this->y ;
}

int & vect2::operator[]( size_t idx )
{
	if (idx > 1)
	{
		std::stringstream ss;
		ss << idx ;
		std::string msg = "Index " + ss.str() + " out of range " +
			"in vector of size 2" ;
		throw std::out_of_range(msg);
	}
	if ( idx == 0 )
	{
		return this->x ;
	}
		return this->y ;
}

bool vect2::operator==( vect2 const & rhs ) const
{
	return ( ( this->x == rhs.x ) && ( this->y == rhs.y ) ) ;
}

bool vect2::operator!=( vect2 const & rhs ) const
{
	return ! ( *this == rhs) ;
}

vect2 & vect2::operator-( void ) 
{
	this->x *= -1 ;
	this->y *= -1 ;
	return *this ;
}



std::ostream & operator<<(std::ostream & o, vect2 const & obj )
{
	o << "{" << obj.get_x() << ", " << obj.get_y() << "}" ;
	return o;
}


vect2 operator*( int scalar, vect2 const & rhs)
{
	vect2 result( rhs );
	result *= scalar ;
	return result ;
}

