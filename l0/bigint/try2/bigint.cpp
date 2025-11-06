#include "bigint.hpp"
bigint::bigint(void) :n("0")
{

}

bigint::bigint(unsigned int n)
{
	std::stringstream ss;
	ss << n;
	this->n = ss.str();
}

bigint::~bigint(void)
{

}

bigint::bigint(bigint const & other)
{
	for(size_t i = 0; i < other.n.size(); i++)
	{
		this->n.push_back(other.n[i]);
	}
}

bigint & bigint::operator=(bigint const & other)
{
	if (this != & other)
	{
		for(size_t i = 0; i < other.n.size(); i++)
		{
			this->n.push_back(other.n[i]);
		}
	}
	return *this;
}


std::string bigint::get_n(void) const
{
	return this->n ;
}


bigint & bigint::operator+=(bigint const & rhs)
{
	int carry = 0;
	size_t slhs = this->n.size();
	size_t srhs = rhs.n.size();
	size_t sadd = slhs;
	std::string rlhs = "" ;
	std::string rrhs = "" ;
	std::string radd = "" ;

	for (int i =  ( slhs - 1 ) ; 0 <= i ; i--) { rlhs.push_back(this->n[i]); }
	for (int i =  ( srhs - 1 ) ; 0 <= i ; i--) { rrhs.push_back(rhs.n[i]); }
	if (slhs < srhs)
	{
		sadd = srhs;
		for (size_t i = (srhs - slhs) ; i > 0 ; i--) {rlhs.push_back('0') ; }
	} else if ( slhs > srhs )
	{
		for (size_t i = (slhs - srhs) ; i > 0 ; i--) {rrhs.push_back('0') ; }
	}
	for (size_t i = 0; i < sadd; i++)
	{
		int dlhs = rlhs[i] - '0';
		int drhs = rrhs[i] - '0';
		int dadd = dlhs + drhs ;
		if ( dadd > 9 )
		{
			radd.push_back( '0' + (dadd % 10 ));
			carry = 1;
		} else {
			radd.push_back( '0' + dadd ) ;
			carry = 0;
		}
	}
	if (carry == 1)
	{ 
		radd.push_back('1');
	}
	this->n.clear();
	for (int i = (sadd - 1) ; 0 <= i; i--) { this->n.push_back(radd[i]); }
	return *this ;

}

bigint bigint::operator+(bigint const & rhs) const
{
	bigint result(*this);
	result+= rhs ;
	return result;
}


bigint & bigint::operator<<=(size_t const d)
{
	for (size_t i = 1; i <= d ; i++) { this->n.push_back('0');}
	return *this;
}

bigint bigint::operator<<(size_t const d) const
{
	bigint result(*this);
	result <<= d;
	return result;
}

bigint & bigint::operator>>=(size_t const d)
{
	size_t numremove = d;
	size_t maxremove = this->n.size();

	if ( numremove > maxremove)
	{		
		numremove = maxremove ;
	}

	bigint aux(*this);
	this->n.erase( ( maxremove - numremove ), numremove );
	return *this;
}

bigint bigint::operator>>(size_t const d) const
{
	bigint result(*this);
	result <<= d;
	return result;
}


bigint & bigint::operator>>=(bigint const & d)
{
	std::stringstream ss;
	ss << d;
	size_t numshift;
	ss >> numshift;
	return *this >>= numshift;

}


bool bigint::operator>(bigint const & rhs) const
{
	if ( this->n.size() > rhs.n.size() )
	{
		return true;
	} else if ( this->n.size() < rhs.n.size()) 
	{
		return false;
	} else {
		return (this->n > rhs.n);
	}
}

bool bigint::operator>=(bigint const & rhs) const
{
 return !(*this < rhs);
}

bool bigint::operator<(bigint const & rhs) const
{
	if ( this->n.size() < rhs.n.size() )
	{
		return true;
	} else if ( this->n.size() > rhs.n.size()) 
	{
		return false;
	} else {
		return (this->n < rhs.n);
	}

}

bool bigint::operator<=(bigint const & rhs) const
{
 return !(*this > rhs);
}


bool bigint::operator==(bigint const & rhs) const
{
	return (this->n == rhs.n);
}

bool bigint::operator!=(bigint const & rhs) const
{
	return !(*this == rhs);
}


bigint & bigint::operator++()
{
	*this += 1;
	return *this;
}

bigint bigint::operator++(int)
{
	bigint result(*this);
	++(*this);
	return result;

}

std::ostream & operator<<(std::ostream & o, bigint const & obj)
{

	o << obj.get_n();
	return o;
}

