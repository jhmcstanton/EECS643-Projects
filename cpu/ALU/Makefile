IDIR =../include
FLAGS = -I$(IDIR)
_DEPS = commontypes.h
DEPS  = $(patsubst %, $(IDIR)/%, $(_DEPS))

ALU.o : ALU.c $(DEPS)
	gcc -c ALU.c $(FLAGS)

clean:
	rm -rf ./*~ ./*.o
