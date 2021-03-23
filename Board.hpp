#include <string>
using namespace std;
#include <iostream>
#include "Direction.hpp"
#define mat 400
 namespace ariel{
     class Board {
     char array [mat][mat] ;
     public:
     void post(unsigned int row,unsigned int col, Direction dir, string str);
     string read(unsigned int row,unsigned int col, Direction dir,int len);
     void show();
     };
 }