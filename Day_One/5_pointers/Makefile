target := 

$(target).o : $(target).c
	-gcc -o $(target).o  $(target).c

run : $(target).o
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
