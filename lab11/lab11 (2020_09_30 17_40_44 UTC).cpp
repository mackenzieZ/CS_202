#include <iostream>
#include "DataType.h"
using namespace std;

class Queue;  //forward declaration that the identifier "Queue" is a class name

class Node{
	
    friend class Queue;  //allows direct accessing of link m_next from queue class
   
    public:
      Node() 
       : m_next(nullptr)
	  { }
      Node(const DataType & data, Node * next = nullptr)
       : m_next(next)
	   , m_data(data)
	  { }	    	
      Node(const Node & other)
       : m_next(other.m_next)
	   , m_data(other.m_data)
	  { }
      DataType & data(){  return m_data; }    	
      const DataType & data() const{  return m_data; }
    private:    
      Node * m_next; 						
      DataType m_data;	
};

class Queue{
	
    friend std::ostream& operator<<(std::ostream& os, const Queue& queue) {
      queue.serialize(os);
      return os;
    }
  
    public:    
      Queue()
	    : m_front(nullptr)
        , m_back(nullptr)
      { }
      
      void push(const DataType & value); 	       
      void pop();
      void serialize(std::ostream & os) const; //helper, to be called by the const-qualified queue object passed to operator<<	
    private:
      Node * m_front;
      Node * m_back;
};

void Queue::push(const DataType & value){
  /* Your implementation here */
  Node * ptr = new Node;
  ptr->m_data = value;
  ptr->m_next=NULL;
  if(m_front == NULL){
    m_front=m_back=ptr;
  }else{
    m_back->m_next=ptr;
    m_back = ptr;
  }

}

void Queue::pop(){
  /* Your implementation here */
  if(m_front != NULL){
    Node * temp = m_front;
    m_front = m_front->m_next;
    delete temp;
    
  }
}

void Queue::serialize(std::ostream & os) const{
  /* Your implementation here */
  Node * iterator = m_front;
  while(iterator!=NULL){
    os << iterator->data();
    iterator = iterator->m_next;
  }
 
}

int main(){
	
	Queue queue;

    for (size_t i=0; i<10; ++i){
      DataType dt_i(i, 0.1*i);
      queue.push( dt_i );	
	}	

    cout << endl << queue << endl;

	for (size_t i=0; i<5; ++i){
      queue.pop( );	
	}
    cout << endl << queue << endl;

}

