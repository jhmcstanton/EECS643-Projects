Memory.o: Memory.c
	gcc -c Memory.c

test_mem: test_memory.c Memory.o
	gcc test_memory.c Memory.o -o test_mem

run_test: test_mem
	./test_mem

clean:
	rm -rf ./*~ ./*.o
