all: compile link

compile:
	g++ -Isrc/include -c *.cpp

link:
	g++ *.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -static -static-libgcc -static-libstdc++