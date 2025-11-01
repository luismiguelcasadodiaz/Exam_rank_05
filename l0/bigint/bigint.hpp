#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <string>
#include <ostream>
#include <sstream>
class bigint
{
	private:
		std::string s;
		std::string reverse( void ) const;
		std::string reverse( std::string str ) const;
		std::string addition( bigint const & other ) const;
	public:
		bigint( void );
		~bigint( void );
		bigint( bigint const & other );
		bigint & operator=( bigint const & other );
		bigint( unsigned int n ); // Subject request
		std::string get_s( void ) const;
		std::string get_r( void ) const;

		bigint & operator+=(bigint const & rhs );
		bigint operator+(bigint const& rhs ) const;

		bigint & operator++( void );
		bigint operator++( int );
};

std::ostream & operator<<( std::ostream & o, bigint const & obj);
#endif
