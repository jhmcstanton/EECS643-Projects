IDIR =../../include
FLAGS = -I$(IDIR)
_DEPS = commontypes.h
DEPS  = $(patsubst %, $(IDIR)/%, $(_DEPS))

Memory.o: Memory.c $(DEPS)
	gcc -c Memory.c $(FLAGS)

test_mem: test_memory.c Memory.o $(DEPS)
	gcc test_memory.c Memory.o $(FLAGS) -o test_mem

run_test: test_mem
	./test_mem

clean:
	rm -rf ./*~ ./*.o
