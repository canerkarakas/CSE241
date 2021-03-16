exe : header.o 131044061_main.o 
	g++ -o exe 131044061_main.o header.o

header.o : header.cpp
	g++ -c -std=c++11 -Wall header.cpp

main.o : 131044061_main.cpp
	g++ -c -std=c++11 -Wall 131044061_main.cpp

clean:
	rm *.o exe


