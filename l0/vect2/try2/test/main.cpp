#include <iostream>
#include <vector>
//#include <stdexcept>

int main ( void )
{
	std::vector<int>  a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
/*
	try
	{
	std::cout << a.at(0) << std::endl;
	std::cout << a.at(1) << std::endl;
	std::cout << a.at(2) << std::endl;
	std::cout << a.at(3) << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
*/	std::cout << a.at(0) << std::endl;
	std::cout << a.at(1) << std::endl;
	std::cout << a.at(2) << std::endl;
	std::cout << a.at(3) << std::endl;
	return 0 ;
}

