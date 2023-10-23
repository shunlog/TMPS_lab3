main: *.cpp
	g++ -Wall -fdiagnostics-color -g *.cpp **/*.cpp -o main

run: main
	./main
