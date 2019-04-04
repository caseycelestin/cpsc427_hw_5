CXX = g++
CXXFLAGS = -g -Wall -pedantic -std=c++17

Yahtzee: game.o yahtzee.o factory.o diceroll.o ruletypes.o rule.o
	${CXX} ${CXXFLAGS} -o Yahtzee game.o yahtzee.o factory.o diceroll.o ruletypes.o rule.o

game.o:  yahtzee.hpp factory.hpp diceroll.hpp 

yahtzee.o: diceroll.hpp scoresheet.hpp ruletypes.hpp rule.hpp

factory.o: factory.cpp yahtzee.hpp ruletypes.hpp rule.hpp

diceroll.o: diceroll.cpp

ruletypes.o:

rule.o:


