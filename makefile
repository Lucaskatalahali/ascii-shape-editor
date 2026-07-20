All: compile run

compile:
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./lib/MainList.o -c ./src/MainList.cpp
	g++ -I ./include/ -o ./lib/MainNode.o -c ./src/MainNode.cpp
	g++ -I ./include/ -o ./lib/Rectangle.o -c ./src/Rectangle.cpp
	g++ -I ./include/ -o ./lib/Screen.o -c ./src/Screen.cpp
	g++ -I ./include/ -o ./lib/Shape.o -c ./src/Shape.cpp
	g++ -I ./include/ -o ./lib/ShapeList.o -c ./src/ShapeList.cpp
	g++ -I ./include/ -o ./lib/ShapeNode.o -c ./src/ShapeNode.cpp
	g++ -I ./include/ -o ./lib/Star.o -c ./src/Star.cpp
	g++ -I ./include/ -o ./lib/Triangle.o -c ./src/Triangle.cpp
	g++ -I ./include/ -o ./bin/main ./lib/MainList.o ./lib/MainNode.o ./lib/Rectangle.o ./lib/Screen.o ./lib/Shape.o ./lib/ShapeList.o ./lib/ShapeNode.o ./lib/Star.o ./lib/Triangle.o ./src/main.cpp

run:
	./bin/main