//Purpose: test the stacks
//Name: proj10.cpp
//Author: Mackenzie Zappe
//Date: 4/28/2020

#include <iostream>
#include <ArrayStack/ArrayStack.hpp>
#include <NodeStack/NodeStack.hpp>

using namespace std;


class DataType{

friend std::ostream & operator<<(std::ostream & os, const DataType & dataType);
friend std::istream & operator>>(std::istream & is, DataType & dataType);

  public:
    DataType();
    DataType(int intVal, double doubleVal);
	DataType(const DataType & other);
	
    bool operator==(const DataType & rhs) const;
    DataType & operator= (const DataType & rhs);
    
    const int & intVal() const;  // allows read-only (e.g. getter) access in const-qualified context
    int & intVal();  // allows read - and - write (e.g. setter / getter) access in non-const-qualified context
    const double & doubleVal() const;  // allows read-only (e.g. getter) access in const-qualified context
    double & doubleVal();  // allows read - and - write (e.g. setter / getter) access in non-const-qualified context

  private:
    int m_intVal;
    double m_doubleVal;
};

int main(){

    DataType d1( 58, 3.14159);
    
    cout << "+++Testing Default CTORS+++" << endl;
    ArrayStack<DataType> emptyArr;
    NodeStack<DataType> emptyNode;
    cout << "ArrayStack: " << emptyArr << " NodeStack: " << emptyNode << endl;

    cout << "+++Testing Parametrized CTORS+++" << endl;

    ArrayStack<DataType> a1(3, d1);
    NodeStack<DataType> n1(6, d1);
    cout << "ArrayStack: " << a1 << " NodeStack: " << n1 << endl;

    cout << "+++Testing Copy CTORS+++" << endl;
    ArrayStack<DataType> a2(a1);
    NodeStack<DataType> n2(n1);
    cout << "ArrayStack: " << a2 << " NodeStack: " << n2 << endl;  

    cout << "+++Testing Assignment Operator+++" << endl;
    cout << "Before: ArrayStack: " << emptyArr << " NodeStack: " << emptyNode << endl;
    emptyArr = a2;
    emptyNode = n2;
    cout << "After: ArrayStack: " << emptyArr << " NodeStack: " << emptyNode << endl; 

    cout << "+++Testing Top Method+++" << endl;    
    ArrayStack<DataType> a3(3, d1);
    NodeStack<DataType> n3(6, d1);
    cout << "Top of ArrayStack " << a3.top() << " Top of NodeStack " << n3.top() << endl;

    cout << "+++Testing Push Method+++" << endl;  
    a3.push(d1);
    n3.push(d1);
    cout << "ArrayStack: " << a3 << " NodeStack: " << n3 << endl;

    cout << "+++Testing Pop Method+++" << endl;
    a3.pop();
    n3.pop();
    cout << "ArrayStack: " << a3 << " NodeStack: " << n3 << endl;

    cout << "+++Testing Size Method+++" << endl;
    cout << "ArrayStack Size: " << a3.size() << " NodeStack Size: " << n3.size() << endl;       

    cout << "+++Testing Empty Method+++" << endl;  
    ArrayStack<DataType> emptyA; 
    NodeStack<DataType> emptyN;
    if(emptyA.empty()){
        cout << "ArrayStack is empty" << endl;
    }else{
        cout << "ArrayStack isn't empty" << endl;
    }
    if(emptyN.empty()){
        cout << "NodeStack is empty" << endl;
    }else{
        cout << "NodeStack isn't empty" << endl;
    }   

    cout << "+++Testing Full Method+++" << endl;  
    ArrayStack<DataType> fullA(999, d1); 
    NodeStack<DataType> fullN(10000, d1);
    if(fullA.full()){
        cout << "ArrayStack is full" << endl;
    }else{
        cout << "ArrayStack isn't full" << endl;
    }
    if(fullN.full()){
        cout << "NodeStack is full" << endl;
    }else{
        cout << "NodeStack isn't full" << endl;
    }

    cout << "+++Testing Clear Method+++" << endl;
    fullA.clear();
    fullN.clear();
    cout << "ArrayStack " << fullA << " NodeStack " << fullN << endl;

    



return 0;
}

DataType::DataType()
 : m_intVal(0),
   m_doubleVal(0)
{
}

DataType::DataType(int intVal, double doubleVal)
 : m_intVal(intVal),
   m_doubleVal(doubleVal)
{
}

DataType::DataType(const DataType & other)
 : m_intVal(other.m_intVal),
   m_doubleVal(other.m_doubleVal)
{
}
	
bool DataType::operator==(const DataType& rhs) const{
  return m_intVal==rhs.m_intVal && m_doubleVal==rhs.m_doubleVal;
}

DataType& DataType::operator=(const DataType& rhs){
  if (this != &rhs){
    m_intVal = rhs.m_intVal;
    m_doubleVal = rhs.m_doubleVal;
  }
  return *this;
}

const int & DataType::intVal() const{
  return m_intVal;
}

int & DataType::intVal(){
  return m_intVal;
}

const double & DataType::doubleVal() const{
  return m_doubleVal;
}

double & DataType::doubleVal(){
  return m_doubleVal;
}

std::ostream & operator<<(std::ostream& os, const DataType & dt){
  os << "{" << dt.m_intVal << "," << dt.m_doubleVal << "}";
  return os;
}

std::istream & operator>>(std::istream & is, DataType & dt){
  char in_buf[255];
  is >> in_buf;
  dt.m_doubleVal = atof(in_buf);
  dt.m_intVal = (int)dt.m_doubleVal;
  dt.m_doubleVal -= dt.m_intVal;
  return is;
}
