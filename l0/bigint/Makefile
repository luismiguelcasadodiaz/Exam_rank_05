all : main

main: main.cpp bigint.cpp bigint.hpp
	c++ -std=c++98 -Werror -Wextra -Wall main.cpp bigint.cpp -o $@

clean:
	rm main

re: clean main
