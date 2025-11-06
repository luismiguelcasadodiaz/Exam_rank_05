#include "vect2.hpp"


vect2::vect2(void): x(0), y(0)
{

}

vect2::vect2(int const a, int const b): x(a), y(b)
{

}

vect2::~vect2(void)
{

}

vect2::vect2(vect2 const & other)
{
	this->x=other.x;
	this->y=other.y;
}

vect2 & vect2::operator=(vect2 const & other)
{
	if (this != &other)
	{
		this->x = other.x ;
		this->y = other.y ;
	}
	return *this;
}


int vect2::get_x(void) const 
{
	return this->x;
}

int vect2::get_y(void) const
{

	return this->y;
}

vect2 & vect2::operator++()
{
	this->x +=1;
	this->y +=1;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 result(*this);
	++(*this);
	return result;
}

vect2 & vect2::operator--()
{
	this->x -=1;
	this->y -=1;
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 result(*this);
	--(*this);
	return result;

}


vect2 vect2::operator-(void) const
{
	vect2 result(*this);
	result.x *= -1;
	result.y *= -1;
	return result;
}


vect2 & vect2::operator+=(vect2 const & rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

vect2 & vect2::operator-=(vect2 const & rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;

}

vect2 & vect2::operator*=(vect2 const & rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	return *this;

}

vect2 vect2::operator+(vect2 const & rhs) const
{
	vect2 result(*this);
	result += rhs;
	return result;
}

vect2 vect2::operator-(vect2 const & rhs) const
{
	vect2 result(*this);
	result -= rhs;
	return result;

}

vect2 vect2::operator*(vect2 const & rhs) const
{
	vect2 result(*this);
	result *= rhs;
	return result;

}

vect2 & vect2::operator*=(int const rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	return *this;

}

vect2 vect2::operator*(int const rhs) const
{

	vect2 result(*this);
	result *= rhs;
	return result;
}




int & vect2::operator[](size_t const idx)
{
	if (idx > 1)
	{
		std::stringstream  msg;
		msg << "Index "<< idx << "out of range in vect2 of size 2";
		throw std::out_of_range(msg.str());
	}
	if (idx == 0)
	{
		return this->x;
	}
	return this->y;
}

int vect2::operator[](size_t const idx) const
{
	if (idx > 1)
	{
		std::stringstream  msg;
		msg << "Index "<< idx << "out of range in vect2 of size 2";
		throw std::out_of_range(msg.str());
	}
	if (idx == 0)
	{
		return this->x;
	}
	return this->y;

}

bool vect2::operator==(vect2 const & other) const
{
	return ( (this->x == other.x) && (this->y == other.y) );
}

bool vect2::operator!=(vect2 const & other) const
{
	return !(this == &other);
}

vect2 operator*(int const scalar, vect2 const & rhs)
{
	return rhs * scalar;
}

std::ostream & operator<<(std::ostream & o, vect2 const & obj)
{
	o << "{" << obj.get_x() << ", " << obj.get_y() << "}" ;
	return o;
}

