#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <string>
#include <sstream>
#include <ostream>
#include <cstddef>

class bigint
{
	private:
		std::string n;
	public:
		bigint(void);
		bigint(unsigned int n);
		~bigint(void);
		bigint(bigint const & other);
		bigint & operator=(bigint const & other);

		std::string get_n(void) const;

		bigint & operator+=(bigint const & rhs);
		bigint operator+(bigint const & rhs) const;

		bigint & operator<<=(size_t const d);
		bigint operator<<(size_t const d) const;
		bigint & operator>>=(size_t const d);
		bigint operator>>(size_t const d) const;

		bigint & operator>>=(bigint const & d);

		bool operator>(bigint const & rhs) const;
		bool operator>=(bigint const & rhs) const;
		bool operator<(bigint const & rhs) const;
		bool operator<=(bigint const & rhs) const;

		bool operator==(bigint const & rhs) const;
		bool operator!=(bigint const & rhs) const;

		bigint & operator++();
		bigint operator++(int);
} ;
std::ostream & operator<<(std::ostream & o, bigint const & obj);

#endif
