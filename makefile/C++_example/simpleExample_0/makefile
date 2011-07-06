CC= g++
CFLAGS= -g -Wall


default : cpp_simple

cpp_simple : cpp_simple.o midpoint.o f.o
	$(CC) $(CFLAGS) -o cpp_simple cpp_simple.o midpoint.o f.o

cpp_simple.o : cpp_simple.C cpp_simple.H
	$(CC) $(CFLAGS) -c cpp_simple.C

midpoint.o : midpoint.C
	$(CC) $(CFLAGS) -c midpoint.C

f.o : f.C
	$(CC) $(CFLAGS) -c f.C

clean :
	rm -f *.o ~*

