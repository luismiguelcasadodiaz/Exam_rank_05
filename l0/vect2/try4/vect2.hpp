#ifndef VECT2_HPP
#define VECT2_HPP

#include <ostream>
#include <cstddef>
#include <stdexcept>
#include <sstream>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2(void);
		vect2(int const a, int const b);
		~vect2(void);
		vect2(vect2 const & other);
		vect2 & operator=(vect2 const & other);

		int get_x(void) const;
		int get_y(void) const;
		vect2 & operator++();
		vect2 operator++(int);
		vect2 & operator--();
		vect2 operator--(int);

		vect2 operator-(void) const;

		vect2 & operator+=(vect2 const & rhs);
		vect2 & operator-=(vect2 const & rhs);
		vect2 & operator*=(vect2 const & rhs);
		vect2 operator+(vect2 const & rhs) const;
		vect2 operator-(vect2 const & rhs) const;
		vect2 operator*(vect2 const & rhs) const;
		vect2 & operator*=(int const rhs);
		vect2 operator*(int const rhs) const;

		

		int & operator[](size_t const idx);
		int operator[](size_t const idx) const;
		bool operator==(vect2 const & other) const;
		bool operator!=(vect2 const & other) const;
};
vect2 operator*(int const scalar, vect2 const & rhs);
std::ostream & operator<<(std::ostream & o, vect2 const & obj);

#endif
