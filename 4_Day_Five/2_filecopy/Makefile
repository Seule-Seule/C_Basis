target := 

$(target).o : $(target).c
	-gcc -g -o $(target).o  $(target).c fcopy.c

run : $(target).o
ifdef target
	@echo "Has target $(target) "
	-rm -f $(target).o
	-gcc -g -o $(target).o $(target).c fcopy.c
else
	@echo "Not have target $(target) "
endif
	-./$(target).o

clean :
	-rm -f *.o
	-rm -f *.txt
	-rm -f *.cif
