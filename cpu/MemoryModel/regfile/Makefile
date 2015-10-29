regfile.o: regfile.c
	gcc -c regfile.c 

test_regfile: test_regfile.c regfile.o
	gcc test_regfile.c regfile.o -o test_regfile

run_test: test_regfile
	./test_regfile

clean:
	rm -rf ./*~ ./*.o 
