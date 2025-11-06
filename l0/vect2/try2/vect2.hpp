#ifndef VECT2_HPP
#define VECT2_HPP

#include <ostream>
#include <cstddef>

class vect2
{
	private:
		int x;
		int y;
	public:
		vect2( void );
		~vect2( void );
		vect2( vect2 const & other );
		vect2 & operator=( vect2 const & other );
		vect2( int const a, int const b);

		int get_x( void ) const ;
		int get_y( void ) const ;

		vect2 & operator+=( vect2 const & rhs ) ;
		vect2 & operator-=( vect2 const & rhs ) ;
		vect2 & operator*=( vect2 const & rhs ) ;
		vect2 operator+( vect2 const & rhs ) const ;
		vect2 operator-( vect2 const & rhs ) const ;
		vect2 operator*( vect2 const & rhs ) const ;
		vect2 & operator+=( int rhs ) ;
		vect2 & operator-=( int rhs ) ;
		vect2 & operator*=( int rhs ) ;
		vect2 operator+( int rhs ) const ;
		vect2 operator-( int rhs ) const ;
		vect2 operator*( int rhs ) const ;
		vect2 & operator++() ;
		vect2 operator++( int ) ;
		vect2 & operator--() ;
		vect2 operator--( int ) ;
		int operator[]( size_t idx ) const ;
		int & operator[]( size_t idx ) ;
		bool operator==( vect2 const & rhs ) const;
		bool operator!=( vect2 const & rhs ) const;
		vect2 & operator-( void ) ;

};

std::ostream & operator<<(std::ostream & o, vect2 const & obj );

vect2 operator*( int scalar, vect2 const & rhs);
#endif
