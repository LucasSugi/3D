main: t3.cpp
	gcc t3.cpp -lglut -lGLU -lGL -lm -o main

run: main
	./main

clean:
	rm -rf main
