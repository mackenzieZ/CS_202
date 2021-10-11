//Purpose: test file
//Name: proj9.cpp
//Author: Mackenzie Zappe
//Date: 4/20/2020

#include <arrayQueue/ArrayQueue.h>
#include <nodeQueue/NodeQueue.h>
using namespace std;


int main(){


cout << "===Testing Default Ctors===" << endl;
ArrayQueue a1;
NodeQueue n1;

cout << "===Testing Parametrized Ctors====" << endl;
DataType parameter(3, 3.14);
ArrayQueue a2(3,parameter);
NodeQueue n2(3,parameter);

cout << "===Testing Copy Ctors====" << endl;
ArrayQueue a3(a2);
NodeQueue n3(n2);

cout << "===Testing Assignment Operator====" << endl;
ArrayQueue a4;
a4 = a3;
NodeQueue n4;
n4 = n3;

cout << "===Testing Empty Method====" << endl;
ArrayQueue a5;
if(a5.empty()){
    cout << "a5 Empty" << endl;
}else{
    cout << "a5 Not Empty" << endl;
}
NodeQueue n5;
if(n5.empty()){
    cout << "n5 Empty" << endl;
}else{
    cout << "n5 Not Empty" << endl;
}

cout << "===Testing Full Method====" << endl;
DataType d2(2, 2.0);
ArrayQueue a6(ARRAY_CAPACITY, d2);
if(a6.full()){
    cout << "a6 Full" << endl;
}else{
    cout << "a6 Not Full" << endl;
}
NodeQueue n6(ARRAY_CAPACITY, d2);
if(n6.full()){
    cout << "n6 Full" << endl;
}else{
    cout << "n6 Not Full" << endl;
    //Should always be not full
}

cout << "===Testing Clear Method====" << endl;
a6.clear();
if(a6.empty()){
    cout << "a6 Cleared so Empty" << endl;
}else{
    cout << "a6 Cleared but Not Empty" << endl;
}
n6.clear();
if(n6.empty()){
    cout << "n6 Cleared so Empty" << endl;
}else{
    cout << "n6 Cleared but Not Empty" << endl;
}

cout << "===Testing << and Serialize Methods===" << endl;
cout << a3 << endl;
cout << n3 << endl;



return 0;
}