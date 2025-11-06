#include "bigint.hpp"

bigint::bigint( void ): s("0"){}
bigint::~bigint( void ){}
bigint::bigint( bigint const & other ): s(other.s){}
bigint & bigint::operator=( bigint const & other )
{
	if (this != &other)
	{
		this->s = other.s ;
	}
	return *this ;
}
bigint::bigint( unsigned int n ) // Subject request
{
	std::stringstream ss;
	ss << n ;
	this->s = ss.str();
}
std::string bigint::get_s( void) const {return this->s;}
std::string bigint::get_r( void) const {return this->reverse();}

std::string bigint::reverse( void ) const
{
	std::string r;
	for (int i = this->s.size() - 1 ; 0 <= i; i--)
		r.push_back(this->s[i]);
	return r;
}
std::string bigint::reverse( std::string s ) const
{
	std::string r;
	for (int i = s.size() - 1 ; 0 <= i; i--)
		r.push_back(s[i]);
	return r;
}
std::string bigint::addition( bigint const & other ) const
{
	std::string suma = "";
	std::string lhr=this->reverse();
 	std::string rhr=other.reverse();
	int lhsize = lhr.size();
	int rhsize = rhr.size();
	int thesize = lhsize ;
	if (lhsize > rhsize)
	{
		thesize = lhsize;
		for (int i = (lhsize - rhsize); 0 < i; i--)
			rhr.push_back('0');
	}if (lhsize < rhsize)
	{
		thesize = rhsize;
		for (int i = (rhsize - lhsize); 0 < i; i--)
			lhr.push_back('0');
	}
	int carry = 0;
	for (int i = 0; i < thesize; i++)
	{
		int ld = lhr[i] - '0';
		int rd = rhr[i] - '0';
		int aux = carry  + ld + rd ;
		if (aux <= 9)
		{
			carry = 0;
			suma.push_back( '0' + aux );
		} else {
			carry = 1;
			suma.push_back( '0' + ( aux % 10 ) );
		}
	}
	if (carry == 1) { suma.push_back('1');}
	return this->reverse(suma);
}
bigint & bigint::operator+=(bigint const & rhs )
{
	this->s = this->addition(rhs);
	return *this ;
}
bigint bigint::operator+(bigint const & rhs ) const
{
	bigint result(*this); //copy left hand operator
	result += rhs;        //add right hand operator
	return result;        //return result
}
bigint & bigint::operator++( void )
{
	const bigint one(1);
	*this += one;
	return *this;
}
bigint bigint::operator++( int ) 
{
	bigint result(*this);
	++(*this);
	return result;
}
bigint & bigint::operator<<=(int n)
{
	for (int i = n; 0 < i; i--) {this->s.push_back('0'); }
	return *this;
}
bigint & bigint::operator>>=(int n)
{
	this->s.erase(this->s.size() - n);
	return *this;
}
bigint & bigint::operator>>=(bigint const & n)
{
	std::stringstream ss(n.get_s());
	int n_num;
	ss >> n_num ;
	this->s.erase(this->s.size() - n_num);
	return *this;
}
bigint bigint::operator<<(int n) const
{
	bigint result(*this);
	result <<= n;
	return result;
}
bigint bigint::operator>>(int n) const
{
	bigint result(*this);
	result >>= n;
	return result;
}
bool bigint::operator>(bigint const & rhs) const
{
	if ( this->s.size() > rhs.s.size() )
	{
		return true;
	} else if ( this->s.size() < rhs.s.size() )
	{
		return false;
	} else {
		for (size_t i = 0; i < this->s.size() ; i++)
		{
			if ( this->s[i] < rhs.s[i] )
			{
				return false;
			} else if ( this->s[i] > rhs.s[i] ) 
			{
				return true;
			}
		}
		return false;
	}
}
bool bigint::operator>=(bigint const & rhs) const
{
	return !( *this < rhs );
}
bool bigint::operator<(bigint const & rhs) const
{
	if ( this->s.size() < rhs.s.size() )
	{
		return true;
	} else if ( this->s.size() > rhs.s.size() )
	{
		return false;
	} else {
		for (size_t i = 0; i < this->s.size() ; i++)
		{
			if ( this->s[i] > rhs.s[i] )
			{
				return false;
			} else if ( this->s[i] < rhs.s[i] ) 
			{
				return true;
			}
		}
		return false;
	}
}
bool bigint::operator<=(bigint const & rhs) const
{
	return !( *this > rhs );
}
bool bigint::operator==(bigint const & rhs) const
{
	if (this->s.size() != rhs.s.size())
	{
		return false;
	} else {
		for (size_t i = 0; i < this->s.size(); i++)
			if ( this->s[i] != rhs.s[i] ) { return false ; }
		return true;
	}
}
bool bigint::operator!=(bigint const & rhs) const
{
	return ( !(*this == rhs)  );
}
std::ostream & operator<<( std::ostream & o, bigint const & obj)
{
	o << obj.get_s();
	return o;
}
