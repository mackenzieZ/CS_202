//Purpose: Node Queue Implementation
//Name: NodeQueue.cpp
//Author: Mackenzie Zappe
//Date: 4/20/2020

#include <nodeQueue/NodeQueue.h>

//Ctors and Dtors
NodeQueue::NodeQueue()
: m_front(nullptr), m_back(nullptr)
{
    std::cout << "Default Node Queue Ctor" << std::endl;
}
NodeQueue::NodeQueue(size_t size, const DataType & value){
    if(size <= 0){
        m_front = NULL;
    }else{
        m_front = new Node(value, NULL);
        Node * start = m_front;
        for(int i = 0; i < size; i++){
            start->m_next = new Node(value,NULL);
            start = start->m_next;
        }
        start->m_next=NULL;
    }
    std::cout << "Parametrized Node Queue Ctor" << std::endl;
}
NodeQueue::NodeQueue(const NodeQueue & other){
    if(!other.empty()){
        m_front = new Node(other.m_front->data());
        Node * copy = m_front;
        Node * otherNode = other.m_front;
        while(otherNode->m_next != NULL){
            otherNode = otherNode->m_next;
            copy->m_next = new Node(otherNode->data());
            copy = copy->m_next;

        }
        copy->m_next = NULL;


    }
    std::cout << "Copy Node Queue Ctor" << std::endl;
}
NodeQueue::~NodeQueue(){
    clear();
    std::cout << "Node Queue Dtor" << std::endl;
}
//Public Methods
NodeQueue& NodeQueue::operator= (const NodeQueue & rhs){
    if(!&rhs){
        this->clear();
        if(!rhs.empty()){
            m_front = new Node(rhs.m_front->data());
            Node * copy = m_front;
            Node * otherNode = rhs.m_front;
            while(otherNode->m_next != NULL){
                otherNode = otherNode->m_next;
                copy->m_next = new Node(otherNode->data());
                copy = copy->m_next;
        }
        copy->m_next = NULL;
        }
    return *this;
    }
    return *this;

}

void NodeQueue::push(const DataType & value){
    Node * ptr = new Node(value, nullptr);
    if(m_front == NULL){
        m_front = ptr;
        m_back = ptr;
    }else{
        m_back->m_next=ptr;
        m_back = ptr;
    }
}
void NodeQueue::pop(){
    if(!empty()){
    Node * temp = m_front;
    m_front = m_front->m_next;
    delete temp;
    }
}
size_t NodeQueue::size() const{
    // gets size member kinda
}
bool NodeQueue::empty() const{
    if(m_front ==NULL){
        return true;
    }
    return false;
}
bool NodeQueue::full() const{
    return false;
}
void NodeQueue::clear(){
    
    //deallocate memory for each node then set m_front to 
    Node * current = m_front;
    Node * prev = m_front;
    while( current != NULL){
        current = current-> m_next;
        delete prev;
        prev = current;
    }
    m_front= NULL;
}
void NodeQueue::serialize(std::ostream & os) const{
    Node * iterator = m_front;
    while(iterator!=NULL){
    os << iterator->data();
    iterator = iterator->m_next;
  }
}
//Front and Back Methods
DataType & NodeQueue::front(){
    return m_front->m_data;
}
const DataType & NodeQueue::front() const{
    return m_front->m_data;
}

DataType & NodeQueue::back(){
    return m_back->m_data;
}
const DataType & NodeQueue::back() const{
    return m_back->m_data;
}
//Friend Method
std::ostream & operator<<(std::ostream & os,const NodeQueue & nodeQueue){
    nodeQueue.serialize(os);
    return os;
}