IDIR =../include
FLAGS = -I$(IDIR)
_DEPS = commontypes.h  
DEPS  = $(patsubst %, $(IDIR)/%, $(_DEPS))

ALU.o : ALU.c $(DEPS)
	gcc -c ALU.c $(FLAGS)

test_alu: ALU.o test_ALU.c
	gcc test_ALU.c ALU.o $(FLAGS) -o test_alu

run_test: test_alu 
	./test_alu

test_w_valgrind: test_ALU
	valgrind ./test_alu

clean:
	rm -rf ./*~ ./*.o
