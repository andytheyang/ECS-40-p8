all : p8.out p8b.out

p8.out : main.cpp SVector.h SVector.cpp
	g++ -ansi -Wall -DNDEBUG -g -o p8.out main.cpp

p8b.out : main.cpp SVector.h SVector.cpp
	g++ -ansi -Wall -g -o p8b.out main.cpp

clean :
	rm -f p8.out p8b.out
