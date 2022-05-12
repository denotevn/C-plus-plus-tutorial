/*
 *  Testing insert_iterator (TestInsertIterator.cpp)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
 
int main() {
   int a1[5] = {11, 55, 44, 33, 88};
   vector<int> v(a1, a1+5);
   ostream_iterator<int, char> out (cout, " ");  // for printing
   copy(v.begin(), v.end(), out);
   cout << endl;
 
   // Construct a back_insert_iterator to insert at the end
   back_insert_iterator<vector<int> > back (v);
   int a2[3] = {91, 92, 93};
   copy(a2, a2+3, back);
   copy(v.begin(), v.end(), out);
   cout << endl;
 
   // Use an anonymous insert_iterator to insert at the front
   int a3[3] = {81, 82, 83};
   copy(a3, a3+3, insert_iterator<vector<int> >(v, v.begin()));
   copy(v.begin(), v.end(), out);
   cout << endl;
   return 0;
}