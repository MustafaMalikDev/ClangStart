all:
	gcc -std=gnu11 ./src/main.c -o cstart

clean:
	rm cstart

run:
	./cstart

copy:
	sudo cp cstart /usr/local/bin

.PHONY: all