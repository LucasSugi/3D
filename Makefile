all:
	gcc t3.cpp -lglut -lGLU -lGL -lm -o main
run:
	./main

clean:
	rm -rf main
