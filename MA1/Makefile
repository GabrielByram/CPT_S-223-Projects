prog: main.o testQueue.hpp testQueue.o
	g++ -Wall main.o testQueue.o -o runPA

main.o: main.cpp testQueue.hpp
	g++ -c -Wall main.cpp

testQueue.o: testQueue.cpp testQueue.hpp
	g++ -c -Wall testQueue.cpp

clean:
	-rm *.o

run:
	@./runPA
