OBJECTS = main.o conjunto.o
CPPFLAGS = -c -g -ansi -Wall

all: principal clean

principal: $(OBJECTS)
	g++ $(OBJECTS) -o ejecutable.out

main.o: main.cpp  
	g++ $(CPPFLAGS) main.cpp 

vector.o: conjunto.cpp conjunto.hpp
	g++ $(CPPFLAGS) conjunto.cpp


clean:
	rm -f *.o