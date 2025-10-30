#include "vect2.hpp"
#include <iostream>
#include <exception>
#include <sstream>

Vect2::Vect2( void ): x(0), y(0) {}
Vect2::~Vect2( void ) {}
Vect2::Vect2( Vect2 const & other ): x(other.x), y(other.y) {}
Vect2 &Vect2::operator=( Vect2 const & other ) {
	if (this != &other)
	{
		this->x = other.x ;
		this->y = other.y ;
	}
	return *this ;
}
//getters
int Vect2::get_x( void ) const {return this->x;}
int Vect2::get_y( void ) const {return this->y;}
//setters
void Vect2::set_x( int a ){this->x = a;} 
void Vect2::set_y( int b ){this->y = b;} 
Vect2::Vect2(int a, int b) : x(a), y(b) {}
		

Vect2 & Vect2::operator++( void )
{
	this->x += 1 ;
	this->y += 1 ;
	return *this;
} // ++obj
Vect2 & Vect2::operator--( void ) //--obj
{
	this->x -= 1 ;
	this->y -= 1 ;
	return *this;
} // --obj
Vect2 Vect2::operator++( int ) 
{
	Vect2 temp(*this);
	++(*this) ;
	return temp;
} // obj++
Vect2 Vect2::operator--( int ) // obj--
{
	Vect2 temp(*this);
	--(*this) ;
	return temp;
} // obj++

Vect2 & Vect2::operator-=( int dec ) 
{
	this->x -= dec ;
	this->y -= dec ;
	return *this ;
}
Vect2 & Vect2::operator+=( int inc )
{
	this->x += inc ;
	this->y += inc ;
	return *this ;
}
Vect2 & Vect2::operator*=( int mul ) 
{
	this->x *= mul ;
	this->y *= mul ;
	return *this ;
}

Vect2 & Vect2::operator/=( int div )  
{
	try
	{
		this->x /= div ;
		this->y /= div ;
		return *this ;
	} catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
}
Vect2 & Vect2::operator-=(Vect2 const & other )
{
	this->x -= other.x ;
	this->y -= other.y ;
	return *this ;
}
Vect2 & Vect2::operator+=(Vect2 const & other )
{
	this->x += other.x ;
	this->y += other.y ;
	return *this ;
}
Vect2 & Vect2::operator*=(Vect2 const & other )
{
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}
Vect2 & Vect2::operator/=(Vect2 const & other ) 
{
	try {
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	} catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
}
Vect2 Vect2::operator+(Vect2 const & a) const 
{
	Vect2 suma(a);
	suma += *this ;
	return suma;
}
Vect2 Vect2::operator-(Vect2 const & a) const  
{
	Vect2 resta(a);
	resta -= *this ;
	return resta;
}
Vect2 Vect2::operator*(Vect2 const & a) const 
{
	Vect2 mult(a);
	mult *= *this ;
	return mult ;
}
Vect2 Vect2::operator/(Vect2 const & a) const  
{
	Vect2 divi(a);
	divi /= *this ;
	return divi ;
}

Vect2  Vect2::operator+(int n) const 
{
	Vect2 suma(*this);
	suma += n ;
	return suma;
}
Vect2  Vect2::operator-(int n) const 
{
	Vect2 suma(*this);
	suma -= n ;
	return suma;
}
Vect2  Vect2::operator*(int n) const 
{
	Vect2 suma(*this);
	suma *= n ;
	return suma;
}
Vect2  Vect2::operator/(int n) const 
{
	Vect2 suma(*this);
	suma /= n ;
	return suma;
}
Vect2  Vect2::operator-( void ) const 
{
	Vect2 suma;
	suma -= *this ;
	return suma;
}
bool  Vect2::operator==(Vect2 const & other) const
{
return ( ( this->x == other.x ) && ( this->x == other.y ) );
}
bool  Vect2::operator!=(Vect2 const & other) const
{
	return !( *this == other) ;
}
int   Vect2::operator[](int i) const
{
	if (i == 0) {
		return this->x ;
	} else if (i == 1) {
		return this->y ;
	} else {
		std::stringstream ss;
		ss << "Index " << i << " out of range " ;
		throw std::out_of_range(ss.str());
	}
}
int  &  Vect2::operator[](int i)
{
	if (i == 0) {
		return this->x ;
	} else if (i == 1) {
		return this->y ;
	} else {
		std::stringstream ss;
		ss << "Index " << i << " out of range " ;
		throw std::out_of_range(ss.str());
	}
}
Vect2 operator*(int n, Vect2 const & v)
{
	Vect2 result(v) ;
	result *= n ;
	return result;
}
std::ostream & operator<<(std::ostream & o, Vect2 const & v)
{
        o << "{" << v.get_x() << ", " << v.get_y() << "}" ;
		return o;
}
