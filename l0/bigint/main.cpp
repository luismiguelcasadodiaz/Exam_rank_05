#include "bigint.hpp"
#include <iostream>

int main()
{
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);
    bigint n21(21), n22(22), n23(23);
    bigint n210(210), n220(220), n230(23);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "ra = " << a.get_r() << std::endl;
    std::cout << "rb = " << b.get_r() << std::endl;
    std::cout << "rc = " << c.get_r() << std::endl;
    std::cout << "rd = " << d.get_r() << std::endl;
    std::cout << "re = " << e.get_r() << std::endl;
  
    std::cout << "d + b = " << d + b << std::endl;
    std::cout << "(c += b) = " << (c += b) << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "(c += a) = " << (c += a) << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "++b = " << ++b << std::endl;
    std::cout << "b++ = " << b++ << std::endl;
  
    std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl;
    std::cout << "(d >>= 2) = " << (d >>= 2) << std::endl;

    std::cout << "a =" << a << std::endl;
    std::cout << "d =" << d << std::endl;

    std::cout << "(d < a) = " << (d < a) << std::endl;
    std::cout << "(d <= a) = " << (d <= a) << std::endl;
    std::cout << "(d > a) = " << (d > a) << std::endl;
    std::cout << "(d >= a) = " << (d >= a) << std::endl;
    
	std::cout << "(d == a) = " << (d == a) << std::endl;
    std::cout << "(d != a) = " << (d != a) << std::endl;
	std::cout << "(a == a) = " << (a == a) << std::endl;
    std::cout << "(d != d) = " << (d != d) << std::endl;


    std::cout << "(n21 <  n210) = " << (n21 <  n210) << std::endl;
    std::cout << "(n21 <= n210) = " << (n21 <= n210) << std::endl;
    std::cout << "(n21 >  n210) = " << (n21 >  n210) << std::endl;
    std::cout << "(n21 >= n210) = " << (n21 >= n210) << std::endl;
    std::cout << "(n21 <   n21) = " << (n21 <  n21) << std::endl;
    std::cout << "(n21 <=  n21) = " << (n21 <= n21) << std::endl;
    std::cout << "(n21 >   n21) = " << (n21 >  n21) << std::endl;
    std::cout << "(n21 >=  n21) = " << (n21 >= n21) << std::endl;
    std::cout << "(n23 <   n21) = " << (n23 <  n21) << std::endl;
    std::cout << "(n23 <=  n21) = " << (n23 <= n21) << std::endl;
    std::cout << "(n23 >   n21) = " << (n23 >  n21) << std::endl;
    std::cout << "(n23 >=  n21) = " << (n23 >= n21) << std::endl;

	return 0;
}
