all: mylo

mylo: main.cpp
	mkdir -p bin
	g++ -std=c++11 -static-libgcc -static-libstdc++ main.cpp -o bin/mylo

clean:
	rm bin/*
