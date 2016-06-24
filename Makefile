CFLAGS = -Wall -Wextra -ggdb3 -std=c++11 -fno-exceptions -fno-rtti -fvisibility=hidden -march=native -pipe
main: main.cpp
	clang++ $(CFLAGS) -o $@ $^
clean:
	rm -f main; rm -rf *.dSYM
