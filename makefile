output: main.c
	gcc main.c -g -o output

run: output
	./output

clean:
	rm output
	rm *~

