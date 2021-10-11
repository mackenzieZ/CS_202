//Purpose: Agency Queue implementation
//Name: AgencyQueue.cpp
//Author: Mackenzie Zappe
//Date: 4/20/2020

#include <arrayQueue/ArrayQueue.h>

//Ctors and Dtor
ArrayQueue::ArrayQueue()
: m_size(0), m_back(ARRAY_CAPACITY-1), m_front(0)
{

    std::cout << "Default Array Queue Ctor" << std::endl;
}
ArrayQueue::ArrayQueue(size_t count, const DataType & value)
: m_size(count), m_back(count-1), m_front(0)
{
    for(size_t i = 0; i < ARRAY_CAPACITY; i++){
        m_array[i] = value; 
    }
    std::cout << "Parametrized Array Queue Ctor" << std::endl;
}
ArrayQueue::ArrayQueue(const ArrayQueue & other)
: m_size(other.size()), m_back(other.m_back), m_front(0)
//Lecture 22
{
    for(size_t i = 0; i < m_size; i++){
        m_array[i] = other.m_array[i];
    }
    std::cout << "Copy Array Queue Ctor" << std::endl;
}
ArrayQueue::~ArrayQueue(){
    std::cout << "Array Queue Dtor" << std::endl;
}

//Public Methods
ArrayQueue & ArrayQueue::operator= (const ArrayQueue & rhs){
    std::cout << "Array Queue Assignment Operator" << std::endl;
}
void ArrayQueue::push(const DataType & value){
    if(!full()){
        m_back = (m_back+1) % ARRAY_CAPACITY;
        m_array[m_back] = value;
        ++m_size;
    }
}
void ArrayQueue::pop(){
    if(!empty()){
    m_front = (m_front+1) % ARRAY_CAPACITY;
    --m_size;
    }
}
size_t ArrayQueue::size() const{
    return m_size;
}
bool ArrayQueue::empty() const{
    if(m_size==0){
        return true;
    }
    return false;
}
bool ArrayQueue::full() const{
    if(m_size== ARRAY_CAPACITY){
        return true;
    }
    return false;
}
void ArrayQueue::clear(){
    m_size = 0;
}
void ArrayQueue::serialize(std::ostream & os) const{
    for(size_t i = 0; i < this->size(); i++){
      os << m_array[i] << " ";
    }
}
//Front & Back Methods
DataType & ArrayQueue::front(){
    if(!this->empty()){
        return m_array[m_front];
    }
}
const DataType & ArrayQueue::front() const{
    if(!this->empty()){
        return m_array[m_front];
    }
}

DataType & ArrayQueue::back(){
    if(!this->empty()){
        return m_array[m_back];
    }
}
const DataType & ArrayQueue::back() const{
    if(!this->empty()){
        return m_array[m_back];
    }
}
//Friend Methods
std::ostream & operator<<(std::ostream & os, const ArrayQueue & arrayQueue){
    arrayQueue.serialize(os);
    return os;
}


