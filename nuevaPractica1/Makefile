#OBJECTS = main.o moneda.o funciones_cambio.o ajustes.o
OBJECTS = main.o 
CPPFLAGS = -c -g -ansi -Wall

principal: $(OBJECTS)
	g++ $(OBJECTS) -o ejecutable.out

#main.o: main.cpp matriz.hpp funciones_cambio.hpp moneda.hpp
main.o: main.cpp cabecera.hpp funcionesGenerales.hpp tiempo.hpp
	g++ $(CPPFLAGS) main.cpp 

#moneda.o: moneda.cpp
#	g++ $(CPPFLAGS) moneda.cpp
#
#funciones_cambio.o: funciones_cambio.cpp moneda.hpp matriz.hpp
#	g++ $(CPPFLAGS) funciones_cambio.cpp
#
#ajustes.o: ajustes.cpp
#	g++ $(CPPFLAGS) ajustes.cpp

clean:
	rm -f *.o

