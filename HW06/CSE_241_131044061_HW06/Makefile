exe : Collection.o Set.o List.o Queue.o LinkedList.o ArrayList.o HashSet.o Iterator.o 131044061_main.o
	g++ -o exe 131044061_main.o Collection.o Set.o List.o Queue.o LinkedList.o ArrayList.o HashSet.o Iterator.o

Collection.o : Collection.cpp Collection.h
	g++ -c -std=c++11 -Wall Collection.cpp

Set.o : Set.cpp Set.h
	g++ -c -std=c++11 -Wall Set.cpp
	
List.o : List.cpp List.h
	g++ -c -std=c++11 -Wall List.cpp
	
Queue.o : Queue.cpp Queue.h
	g++ -c -std=c++11 -Wall Queue.cpp
	
LinkedList.o : LinkedList.cpp LinkedList.h
    g++ -c -std=c++11 -Wall LinkedList.cpp
    
ArrayList.o : ArrayList.cpp ArrayList.h
    g++ -c -std=c++11 -Wall ArrayList.cpp
    
HashSet.o : HashSet.cpp HashSet.h
    g++ -c -std=c++11 -Wall HashSet.cpp
    
Iterator.o : Iterator.cpp Iterator.h
    g++ -c -std=c++11 -Wall Iterator.cpp

main.o : 131044061_main.cpp
	g++ -c -std=c++11 -Wall 131044061_main.cpp

clean:
	rm *.o exe


