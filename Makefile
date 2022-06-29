all: compile link run

compile:
	g++ -c main.cpp game.cpp -I"C:\SFML-2.5.1\include" -DSFML_STATIC
 
link:
	g++ main.o game.o -o main -L"C:\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	rm -f main *.o 

run: compile
	./main
