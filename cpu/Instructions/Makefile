IDIR =../include
FLAGS = -I$(IDIR)
_DEPS = commontypes.h Instructions.h
DEPS  = $(patsubst %, $(IDIR)/%, $(_DEPS))
JUNKFILE = junk_data.bin

Instructions.o: Instructions.c 
	gcc -c Instructions.c $(FLAGS)

run_test: test_instr
	./test_instr
	rm $(JUNKFILE)

run_w_valgrind: test_instr
	valgrind ./test_instr
	rm $(JUNKFILE)

test_instr: test_instructions.c Instructions.o
	gcc test_instructions.c -o test_instr $(FLAGS) Instructions.o

clean:
	rm -rf ./*~ ./*.o
