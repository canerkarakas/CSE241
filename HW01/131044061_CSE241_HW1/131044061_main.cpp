#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
#include "header.h"

using namespace std;

int main() {
    
    int contRectWidth, contRectHeight, contCircRadius, contTriEdge,
        smallRectWidth, smallRectHeight, smallCircRadius, smallTriEdge;
        
    Shapes containerShape, smallShape;
    
    inputs_control_for_return_result(contRectWidth, contRectHeight, contCircRadius, contTriEdge,
                                    smallRectWidth, smallRectHeight, smallCircRadius, smallTriEdge,
                                    containerShape, smallShape);
                                    
    draw(contRectWidth, contRectHeight, contCircRadius, contTriEdge,
         smallRectWidth, smallRectHeight, smallCircRadius, smallTriEdge,
         containerShape, smallShape);
    
	return 0;
}
