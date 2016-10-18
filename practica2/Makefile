OBJECTS = main.o 
CPPFLAGS = -c -g -ansi -Wall

all: principal clean

principal: $(OBJECTS)
	g++ $(OBJECTS) -o ejecutable.out

main.o: main.cpp cabecera.hpp funcionesGenerales.hpp tiempo.hpp cramer.hpp combinatorio.hpp
	g++ $(CPPFLAGS) main.cpp 

clean:
	rm -f *.o

