OBJECTS = main.o 
CPPFLAGS = -c -g -ansi -Wall

all: principal clean

principal: $(OBJECTS)
	g++ $(OBJECTS) -o ejecutable.out

main.o: main.cpp conjunto.hpp otrasFunciones.hpp cabecera.hpp
	g++ $(CPPFLAGS) main.cpp 

clean:
	rm -f *.o