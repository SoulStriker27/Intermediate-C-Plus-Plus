/*********************************************************************
   PROGRAMMER: Eduardo Leanos

   FUNCTION:   This program tests the functionality of the NIUString
               class.
*********************************************************************/  

#include <iostream>
#include "NIUString.h"

using std::cout;
using std::endl;

int main()
   {
   cout << "Testing default constructor\n\n";

   const NIUString s1;
   
   cout << "s1: " << s1 << endl;   
   cout << "s1 size: " << s1.size() << endl;
   cout << "s1 capacity: " << s1.capacity() << endl;
   cout << "s1 is " << ((s1.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
   
   cout << "Testing second constructor\n\n";
  
   const NIUString s2 = "Hello, world!";

   cout << "s2: " << s2 << endl;   
   cout << "s2 size: " << s2.size() << endl;
   cout << "s2 capacity: " << s2.capacity() << endl;
   cout << "s2 is " << ((s2.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
   
   cout << "Testing second constructor with long string\n\n";
   
   NIUString s4 = "This is a really long string, but all of it will still end up in the array - pretty neat, huh?";
   
   cout << "s4: " << s4 << endl;   
   cout << "s4 size: " << s4.size() << endl;
   cout << "s4 capacity: " << s4.capacity() << endl;
   cout << endl;

   cout << "Testing non-const version of subscript operator\n\n";

   NIUString s3 = "some text";
   
   s3[0] = 'S';
   s3[5] = 'T';
   cout << "s3: " << s3 << endl << endl;
      
   cout << "Testing const version of subscript operator\n\n";
   
   cout << "s2: ";
   for (size_t i = 0; i < s2.size(); i++)
      cout << s2[i];
   cout << endl << endl;

   cout << "Testing reserve() method\n\n";

   s3.reserve(9);

   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
 
   s3.reserve(30);

   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
 
   s3.reserve(15);

   cout << "s3: " << s3 << endl;   
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << "s3 is " << ((s3.empty()) ? "empty\n" : "not empty\n");
   cout << endl;
 
   s4.reserve(10);
  
   cout << "s4: " << s4 << endl;   
   cout << "s4 size: " << s4.size() << endl;
   cout << "s4 capacity: " << s4.capacity() << endl;
   cout << "s4 is " << ((s4.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Testing equality operators\n\n";

   const NIUString s5 = "Some Text";
   
   cout << "s3 and s5 are " << ((s3 == s5) ? "equal\n" : "not equal\n");
   cout << "s4 and s5 are " << ((s4 == s5) ? "equal\n" : "not equal\n\n");
   
   cout << "s5 and \"Some Text\" are " << ((s5 == "Some Text") ? "equal\n" : "not equal\n");
   cout << "s5 and \"More Text\" are " << ((s5 == "More Text") ? "equal\n" : "not equal\n\n");
   
   cout << "\"Some Text\" and s5 are " << (("Some Text" == s5) ? "equal\n" : "not equal\n");
   cout << "\"More Text\" and s5 are " << (("More Text" == s5) ? "equal\n" : "not equal\n\n");

   cout << "Testing clear() method\n\n";

   s4.clear();
   
   cout << "s4: " << s4 << endl;   
   cout << "s4 size: " << s4.size() << endl;
   cout << "s4 capacity: " << s4.capacity() << endl;
   cout << "s4 is " << ((s4.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Testing copy constructor\n\n";
   
   NIUString s6(s5);
   
   cout << "s6: " << s6 << endl;   
   cout << "s6 size: " << s6.size() << endl;
   cout << "s6 capacity: " << s6.capacity() << endl;
   cout << endl;

   cout << "Testing assignment operator\n\n";
   
   s4 = s6;

   cout << "s4: " << s4 << endl;   
   cout << "s4 size: " << s4.size() << endl;
   cout << "s4 capacity: " << s4.capacity() << endl;
   cout << endl;

   s4 = "a different string";

   cout << "s4: " << s4 << endl;   
   cout << "s4 size: " << s4.size() << endl;
   cout << "s4 capacity: " << s4.capacity() << endl;
   cout << endl;

   cout << "Testing self-assignment\n\n";

   s4 = s4;

   cout << "s4: " << s4 << endl;   
   cout << "s4 size: " << s4.size() << endl;
   cout << "s4 capacity: " << s4.capacity() << endl;
   cout << endl;

   cout << "Testing chained assignment\n\n";

   s4 = s3 = "Hello, world";

   cout << "s3: " << s3 << endl;
   cout << "s3 size: " << s3.size() << endl;
   cout << "s3 capacity: " << s3.capacity() << endl;
   cout << endl;

   cout << "s4: " << s4 << endl;
   cout << "s4 size: " << s4.size() << endl;
   cout << "s4 capacity: " << s4.capacity() << endl;
   cout << endl;

   //
   // Extra Credit
   //
   // This code will call the move constructor and move assignment
   // operator if they exist.
   //
   // If those move semantics methods are not implemented, this code
   // will call the copy constructor and copy assignment operator
   // instead. The output will be different in that case.
   //
   cout << "Extra Credit: Testing move constructor\n\n";

   NIUString s7 = std::move(s6);

   cout << "s7: " << s7 << endl;
   cout << "s7 size: " << s7.size() << endl;
   cout << "s7 capacity: " << s7.capacity() << endl;
   cout << "s7 is " << ((s7.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "s6: " << s6 << endl;
   cout << "s6 size: " << s6.size() << endl;
   cout << "s6 capacity: " << s6.capacity() << endl;
   cout << "s6 is " << ((s6.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "Extra Credit: Testing move assignment operator\n\n";

   s6 = std::move(s7);

   cout << "s6: " << s6 << endl;
   cout << "s6 size: " << s6.size() << endl;
   cout << "s6 capacity: " << s6.capacity() << endl;
   cout << "s6 is " << ((s6.empty()) ? "empty\n" : "not empty\n");
   cout << endl;

   cout << "s7: " << s7 << endl;
   cout << "s7 size: " << s7.size() << endl;
   cout << "s7 capacity: " << s7.capacity() << endl;
   cout << "s7 is " << ((s7.empty()) ? "empty\n" : "not empty\n");

   return 0;
   }
