#ifndef VECT2_HPP
#define VECT2_HPP

#include <ostream>

class vect2 
{
	private:
		int x;
		int y;
	public:
		vect2( void ) ;
		~vect2( void ) ;
		vect2( vect2 const & other ) ;
		vect2 & operator=( vect2 const & other ) ;
		vect2( int a, int b);

		int get_x( void );
		int get_y( void );

		vect2 & operator++( void ); 
		vect2 operator++( int ); 
		vect2 & operator--( void ); 
		vect2 operator--( int ); 

		vect2 & operator+=( vect2 const & rhs) ;
		vect2 operator+( vect2 const & rhs) const ;
		vect2 & operator-=( vect2 const & rhs) ;
		vect2 operator-( vect2 const & rhs) const ;
		vect2 & operator*=( vect2 const & rhs) ;
		vect2 operator*( vect2 const & rhs) const ;
		vect2 & operator/=( vect2 const & rhs) ;
		vect2 operator/( vect2 const & rhs) const ;
		vect2 operator-( void ) const;

		vect2 & operator+=( int n) ;
		vect2 & operator-=( int n) ;
		vect2 & operator*=( int n) ;
		vect2 operator*( int n) const ;
		vect2 & operator/=( int n) ;

		int operator[](size_t const idx) const;
		int & operator[](size_t const idx) ;

		bool operator==(vect2 const & rhs) const;
		bool operator!=(vect2 const & rhs) const;

};

vect2 operator*(int const n, vect2 const & rhs) ;
std::ostream & operator<<(std::ostream & o, vect2 const & obj);
#endif
