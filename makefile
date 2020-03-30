.PHONY: run

GCC_FLAGS = -Wall -Wextra -std=c11 -O2

forests: forests.o bst.o commands.o input_commands.o
	gcc $(GCC_FLAGS) -o forests forests.o bst.o commands.o input_commands.o

run: forests
	./forests

test: forests
	./test.sh ./forests test/examples

docker: clean
	docker run -it --rm --workdir $(HOME) --entrypoint make -eUSE_VALGRIND=1 -eVERBOSE=1 -v $(PWD):$(HOME) mooreryan/valgrind test

clean:
	rm -f forests *.o mr421537_male_zadanie.tar.gz
	rm -rf result

bst.o: bst.c bst.h
	gcc $(GCC_FLAGS) -c bst.c

input_commands.o: input_commands.c input_commands.h commands.h bst.h
	gcc $(GCC_FLAGS) -c input_commands.c	

commands.o: commands.c commands.h bst.h
	gcc $(GCC_FLAGS) -c commands.c

forests.o: forests.c input_commands.h commands.h bst.h
	gcc $(GCC_FLAGS) -c forests.c

tar:
	COPYFILE_DISABLE=1 tar -czvf mr421537_male_zadanie.tar.gz makefile test.sh *.c *.h