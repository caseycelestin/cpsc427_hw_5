CXX = g++
CXXFLAGS = -g -Wall -pedantic -std=c++17

Yahtzee: game.o yahtzee.o factory.o diceroll.o
	${CXX} ${CXXFLAGS} -o Yahtzee game.o yahtzee.o factory.o diceroll.o

game.o: game.cpp yahtzee.hpp factory.hpp diceroll.hpp 

yahtzee.o: yahtzee.cpp diceroll.hpp 

factory.o: factory.cpp

diceroll.o: diceroll.cpp



