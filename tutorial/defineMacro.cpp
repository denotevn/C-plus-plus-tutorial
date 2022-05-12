/* Test #define macro (TestMacro.cpp) */
#include <iostream>
using namespace std;
 
#define SQUARE(x) x*x     // Macro with argument
 
inline int square(int x) { return x*x; }  // inline function
 
int main() {
   cout << SQUARE(5) << endl;  // expand to 5*5 (25)
   int x = 2, y = 3;
   cout << SQUARE(x) << endl;  // expand to x*x (4)
 
   // Problem with the following macro expansions
   cout << SQUARE(5+5) << endl;   // expand to 5+5*5+5 - wrong answer
   cout << square(5+5) << endl;   // Okay square(10)
   cout << SQUARE(x+y) << endl;   // expand to x+y*x+y - wrong answer
   cout << square(x+y) << endl;   // Okay
      // can be fixed using #define SQUARE(x) (x)*(x)
 
   cout << SQUARE(++x) << endl;   // expand to ++x*++x (16) - x increment twice
   cout << x << endl;             // x = 4
   cout << square(++y) << endl;   // Okay ++y, (y*y) (16)
   cout << y << endl;             // y = 4
}