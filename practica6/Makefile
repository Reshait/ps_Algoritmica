OBJECTS = main.o cabecera.o funcionesGenerales.o 
CPPFLAGS = -c -g -ansi -Wall

all: principal clean
#all: principal	

principal: $(OBJECTS)
	g++ $(OBJECTS) -o ejecutable.out

main.o: main.cpp cabecera.hpp funcionesGenerales.hpp
	g++ $(CPPFLAGS) main.cpp 

cabecera.o: cabecera.cpp cabecera.hpp
	g++ $(CPPFLAGS) cabecera.cpp 

funcionesGenerales.o: funcionesGenerales.cpp funcionesGenerales.hpp
	g++ $(CPPFLAGS) funcionesGenerales.cpp 

clean:
	rm -f *.o