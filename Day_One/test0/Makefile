target := 

test0.o : test0.c
	-gcc -o test0.o test0.c

run : test0.o
ifdef target
	@echo "Has target $(target) "
	-rm -f $(target).o
	-gcc -o $(target).o $(target).c
else
	@echo "Not have target $(target) "
endif
	-./$(target).o

clean :
	-rm -f *.o
