
//example 1

# include <iostream>

 int add ( int a , int b ) {
     return a + b ;
 }
int subtract ( int a , int b ) {
     return a - b ;
 }

int main () {
     int (* operation ) ( int , int ) ;

     operation = &add ;
     std :: cout << "3 + 5 = " << operation (3 , 5) << "\n";

     operation = & subtract ;
     std :: cout << "8 - 2 = " << operation (8 , 2) << "\n";
     // Display the memory addresses of the add and subtract functions
         std::cout << "Address of add function:       " << reinterpret_cast<void*>(add) << std::endl;
        std::cout << "Address of subtract function:  " << reinterpret_cast<void*>(subtract) << std::endl;

     return 0;
 }


