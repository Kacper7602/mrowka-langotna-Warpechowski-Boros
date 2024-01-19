main: main.c ant.c
	clear
	cc main.c ant.c -lm -o out
clean:
	rm out
