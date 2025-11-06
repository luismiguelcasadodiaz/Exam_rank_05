#ifndef VECT2_HPP
#define VECT2_HPP

#include <ostream>

class Vect2
{
	private:
		int x;
		int y;
	public:
		Vect2( void ) ;
		~Vect2( void ) ;
		Vect2( Vect2 const & other ) ;
		Vect2 & operator=( Vect2 const & other ) ;
		Vect2(int a, int b);


		//getters
		int get_x( void ) const;
		int get_y( void ) const;
		//setters
		void set_x( int a ) ;
		void set_y( int b ) ;

		Vect2 & operator++( void ) ; // ++obj
		Vect2 & operator--( void ) ; //--obj
		Vect2 operator++( int ) ; // obj++
		Vect2 operator--( int ) ; // obj--

   		Vect2 & operator-=(Vect2 const & other ) ;
		Vect2 & operator+=(Vect2 const & other ) ;
		Vect2 & operator*=(Vect2 const & other ) ;
		Vect2 & operator/=(Vect2 const & other ) ;
		Vect2  operator+(Vect2 const & a) const ;
		Vect2  operator-(Vect2 const & a) const ;
		Vect2  operator*(Vect2 const & a) const ;
		Vect2  operator/(Vect2 const & a) const ;


		Vect2 & operator-=( int dec ) ; 
		Vect2 & operator+=( int inc ) ; 
		Vect2 & operator*=( int mul ) ; 
		Vect2 & operator/=( int div ) ; 
		Vect2  operator+(int n) const ;
		Vect2  operator-(int n) const ;
		Vect2  operator*(int n) const ;
		Vect2  operator/(int n) const ;


		Vect2  operator-( void ) const ;

		bool   operator==(Vect2 const & other) const ;
		bool   operator!=(Vect2 const & other) const ;
		int    operator[](int i) const ;
		int &    operator[](int i) ;
};
Vect2 operator*(int n, Vect2 const & v) ;
std::ostream & operator<<(std::ostream & o, Vect2 const & v);
#endif
