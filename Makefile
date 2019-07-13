output: Main.o SplitsHappen.o SplitsHappenTester.o
	g++ Main.o SplitsHappen.o SplitsHappenTester.o -o splitshappen

Main.o: Main.cpp
	g++ -c Main.cpp

SplitsHappen.o: SplitsHappen.cpp SplitsHappen.hpp
	g++ -c SplitsHappen.cpp

SplitsHappenTester.o: SplitsHappenTester.cpp SplitsHappenTester.hpp
	g++ -c SplitsHappenTester.cpp