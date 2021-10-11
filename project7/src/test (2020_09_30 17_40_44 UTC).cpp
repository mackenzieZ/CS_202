//Purpose: Testing the string 
//Name: test.cpp
//Author: Mackenzie Zappe
//Date: 3/30/2020

#include <iostream>

#include <my_string/MyString.h>
using namespace std;

int main(){
    
    cout << "Testing Default ctor" << endl;
    MyString ms_default;
    cout << "Testing Parametrized ctor" << endl;
    MyString ms_parametrized ("MyString parametrized constructor!");
    cout << "Testing Copy ctor" << endl; 
    MyString ms_copy(ms_parametrized);    
    cout << "Testing dtor" << endl;
    {
    MyString ms_destroy("MyString to be destoyed");
    }
    MyString ms_size_length("Size and Length Test");
    cout << "Testing size " << ms_size_length.size() << endl;
    cout << "Testing length " << ms_size_length.length() << endl;
    
   cout << "Testing c_str() " << endl;
   MyString ms_toCstring("C-String equivalent successfully obtained!");
   cout << ms_toCstring.c_str() << endl;

   cout << "Testing == operator" << endl;
   MyString ms_same1 ("The Same"), ms_same2 ("Not The Same");
   if(ms_same1 == ms_same2){
       cout << "success" << endl;
   }else{
       cout << "fail" << endl;
   }
   
    cout << "Testing operator=" << endl;
    MyString ms_assign("Before Assignment");
    cout << ms_assign.c_str() << endl;
    ms_assign = MyString("After performing assignment");
    cout << ms_assign.c_str() << endl;
    

   cout << "Testing operator+" << endl;
   MyString ms_append1("The First part! ");
   MyString ms_append2("and the second part ");
   MyString ms_concat = ms_append1 + ms_append2;
    cout << ms_concat.c_str() << endl;

   
    cout << "Testing operator []" << endl;
    MyString ms_access("Access successful (NOT)");
    ms_access[17] = 0;

    cout << "Testing operator<<()" << endl;
    cout << ms_access << endl;
    
}   
