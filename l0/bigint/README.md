# Consideration about BigInt

# String version

My implementation uses strings

```c++
std::string a = "42";
std::string b = "21";

std::cout << a + b  //imprimira "43"
```


## Key method
Key method is `bigint % operator +=(bigint const & rhs)

### First Approach Zero Padding + helper functin reverse()

```c++
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

```

### Second approach Zero padding + reversing

```c++
bigint & bigint::operator+=(bigint const & rhs)
{
	int carry = 0;
	size_t slhs = this->n.size();
	size_t srhs = rhs.n.size();
	size_t sadd = slhs;
	std::string rlhs = "" ;
	std::string rrhs = "" ;
	std::string radd = "" ;
    // reversing
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
    //REVERSING
	for (int i = (sadd - 1) ; 0 <= i; i--) { this->n.push_back(radd[i]); }
	return *this ;

}
```


### Third approoach no padding no reversing
 
```c++
bigint & bigint::operator+=(bigint const & rhs)
{
	int carry = 0;
	int slhs = this->n.size() - 1 ;
	int srhs = rhs.n.size() - 1 ;
	std::string radd = "" ;

	while ( slhs >= 0 || srhs >= 0 || carry )
	{
		int dlhs = ( slhs >= 0 ? this->n[slhs] - '0' : 0 );
		int drhs = ( srhs >= 0 ? rhs.n[srhs] - '0' : 0 );
		int suma = dlhs + drhs + carry;

		carry = suma / 10 ;
		int digito = suma % 10 ;
		radd.push_back( '0' + digito ) ;
		slhs--;
		srhs--;
	}
	this->n.clear();
	for (int i = ( radd.size() - 1) ; 0 <= i; i--) { this->n.push_back(radd[i]); }
	return *this ;

}
```


## Boolean operators

Use string boolean operators

```c++

		return (this->n > rhs.n);
        return (this->n < rhs.n);
        return !(*this > rhs);
        return !(*this < rhs);
        return (this->n == rhs.n);
        return !(*this == rhs);
```