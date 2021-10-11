//Purpose: testing the different classes
//Name: proj8.cpp
//Author: Mackenzie Zappe
//Date: 4/13/2020

#include <arrayList/ArrayList.h>
#include <nodeList/NodeList.h>

#include <iostream>
using namespace std;

 int main(){

cout << "Testing Default Ctors" << endl;
ArrayList a1;
cout << a1 << endl;
NodeList n1;
cout << n1 << endl;


cout << "Testing Parametrized Ctors" << endl;
DataType d1(2, 2.4);
ArrayList a2(2, d1);
cout << a2 << endl;
NodeList n2(2,d1);
cout << n2 << endl;

cout << "Testing Copy Ctors" << endl;
ArrayList a3(a2);
cout << a3 << endl;
NodeList n3(n2);
cout << n3 << endl;

cout << "Testing operator =" << endl;
DataType d2(740,100.9), d3(98, 22.2);
ArrayList a4(8,d2);
a4 = ArrayList(8,d3);
cout << a4 << endl;
NodeList n4(8,d2);
n4 = NodeList(8,d3);
cout << n4 << endl;

cout << "Testing Front Method" << endl;
cout << a3.front() << endl;
//cout << a1.front() << endl; //Fails like it should
cout << n3.front() << endl;
//cout << n1.front() << endl; //Fails like it should

cout << "Testing Back Method" << endl;
cout << a3.back() << endl;
//cout << a1.back() << endl; //Fails like it should
cout << n3.back() << endl;
//cout << n1.back() << endl; //Fails like it should


cout << "Testing Clear Method" << endl;
a3.clear();
cout << a3 << endl;
n3.clear();
cout << n3 << endl;

cout << "Testing Find Method" << endl;
Node * prev =nullptr;
if(n2.find(d1, prev)!= NULL){
    cout << "Find = true " << endl;
}else{
    cout << "Find == false " << endl; 
}

cout << "Testing Before Method" << endl; 
if(n3.insertBefore(d1,d2) != NULL){
    cout << "Before = true" << endl;
}else{
    cout << "Before = false" << endl;
}

cout << "Testing After Method" << endl; 
if(n3.insertAfter(d1,d2) != NULL){
    cout << "After = true" << endl;
}else{
    cout << "After = false" << endl;
}

cout << "Testing Erase Method" << endl;
if(n2.erase(d1) != NULL){
    cout << "Erase = true" << endl;
}else{
    cout << "Erase = false" << endl;
}



return 0;
 }