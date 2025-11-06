all: main

main: main.cpp bigint.cpp
	c++ -g -std=c++98 -Werror -Wextra -Wall bigint.cpp main.cpp -o $@

clean:
	rm main
re: clean main
