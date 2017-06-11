main: t3.cpp bibutil.cpp
	g++ t3.cpp bibutil.cpp -std=c++11 -lglut -lGLU -lGL -lm -o main

run: main
	./main

clean:
	rm -rf main
