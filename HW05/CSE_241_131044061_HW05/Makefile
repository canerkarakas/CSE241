exe : Shape.o Rectangle.o Circle.o Triangle.o ComposedShape.o Polygon.o PolygonVect.o PolygonDyn.o 131044061_main.o
	g++ -o exe 131044061_main.o Shape.o Rectangle.o Circle.o Triangle.o ComposedShape.o Polygon.o PolygonVect.o PolygonDyn.o

Shape.o : Shape.cpp
	g++ -c -std=c++11 -Wall Shape.cpp

Rectangle.o : Rectangle.cpp
	g++ -c -std=c++11 -Wall Rectangle.cpp
	
Circle.o : Circle.cpp
	g++ -c -std=c++11 -Wall Circle.cpp
	
Triangle.o : Triangle.cpp
	g++ -c -std=c++11 -Wall Triangle.cpp
	
ComposedShape.o : ComposedShape.cpp
    g++ -c -std=c++11 -Wall ComposedShape.cpp
    
Polygon.o : Polygon.cpp
    g++ -c -std=c++11 -Wall Polygon.cpp
    
PolygonVect.o : PolygonVect.cpp
    g++ -c -std=c++11 -Wall PolygonVect.cpp
    
PolygonDyn.o : PolygonDyn.cpp
    g++ -c -std=c++11 -Wall PolygonDyn.cpp

main.o : 131044061_main.cpp
	g++ -c -std=c++11 -Wall 131044061_main.cpp

clean:
	rm *.o exe


