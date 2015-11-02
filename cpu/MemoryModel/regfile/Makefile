IDIR =../../include
FLAGS = -I$(IDIR)
_DEPS = commontypes.h
DEPS  = $(patsubst %, $(IDIR)/%, $(_DEPS))

regfile.o: regfile.c $(DEPS)
	gcc -c regfile.c $(FLAGS)

test_regfile: test_regfile.c regfile.o 
	gcc test_regfile.c regfile.o $(FLAGS) -o test_regfile

run_test: test_regfile
	./test_regfile

test_w_valgrind: test_regfile
	valgrind ./test_regfile

clean:
	rm -rf ./*~ ./*.o 
