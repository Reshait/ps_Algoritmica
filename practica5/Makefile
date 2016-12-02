OBJECTS = main.o cabecera.o funcionesGenerales.o moneda.o matriz.o
CPPFLAGS = -c -g -ansi -Wall

all: principal clean

principal: $(OBJECTS)
	g++ $(OBJECTS) -o ejecutable.out

main.o: main.cpp cabecera.hpp funcionesGenerales.hpp
	g++ $(CPPFLAGS) main.cpp 

cabecera.o: cabecera.cpp cabecera.hpp
	g++ $(CPPFLAGS) cabecera.cpp 

funcionesGenerales.o: funcionesGenerales.cpp funcionesGenerales.hpp moneda.hpp
	g++ $(CPPFLAGS) funcionesGenerales.cpp 

moneda.o: moneda.cpp moneda.hpp
	g++ $(CPPFLAGS) moneda.cpp 

matriz.o: matriz.cpp matriz.hpp
	g++ $(CPPFLAGS) matriz.cpp 

clean:
	rm -f *.o
