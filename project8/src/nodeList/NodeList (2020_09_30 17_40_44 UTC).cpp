//Purpose: Node List source code
//Name: NodeList.cpp
//Author: Mackenzie Zappe
//Date: 4/13/2020

#include <nodeList/NodeList.h>

//Ctor & dtor
NodeList::NodeList(){
    m_head = NULL;
    
}
NodeList::NodeList(size_t count, const DataType & value){
    if(count <= 0){
        m_head = NULL;
    }else{
        m_head = new Node(value, NULL);
        Node * start = m_head;
        for(int i = 0; i < count; i++){
            start->m_next = new Node(value,NULL);
            start = start->m_next;
        }
        start->m_next=NULL;

    }
}
NodeList::NodeList(const NodeList & other){
    if(other.m_head != NULL){
        m_head = new Node(other.m_head->data());
        Node * copy = m_head;
        Node * otherNode = other.m_head;
        while(otherNode->m_next != NULL){
            otherNode = otherNode->m_next;
            copy->m_next = new Node(otherNode->data());
            copy = copy->m_next;

        }
        copy->m_next = NULL;


    }
}
NodeList::~NodeList(){
    clear();
    std::cout<<"NodeList Dtor" << std::endl;
    
}

//Public Methods
NodeList & NodeList::operator= (const NodeList & rhs){
    if(this != &rhs){
        Node *copy = m_head;
        Node * other = rhs.m_head;
        while(other->m_next !=NULL){
            copy->m_data = other->data();
            copy = copy->m_next;
            other = other ->m_next;

        }
        return *this;

    }
    return *this;
}

Node * NodeList::front(){
    return m_head;
}
Node * NodeList::back(){
    Node * temp = m_head;
    while(temp->m_next != NULL){
     temp = temp->m_next;
    }
    return temp;
}
	
Node * NodeList::find(const DataType & target, Node * & previous, const Node * start){
        Node * ptr = m_head;
        while(ptr->m_next != NULL && ptr != NULL){
            if(ptr->m_next->data() == target){
                if(ptr == NULL){
                    previous = NULL;
                }
                previous = ptr;
                return ptr->m_next;

            }
            ptr = ptr->m_next;

        }
        previous = NULL;
        return NULL;
}
	
Node * NodeList::insertAfter(const DataType & target,  const DataType & value){
            Node * temp = m_head;
            while(temp != NULL){
                if(temp->data() == target && temp != NULL){
                    temp->m_next = new Node(value, temp->m_next);
                    return temp->m_next;
                }
                temp = temp->m_next;
            }
            if(empty()){
                m_head = new Node (value,NULL);
                return m_head;
            }
            return NULL;
}	    
Node * NodeList::insertBefore(const DataType & target, const DataType & value){
            if(empty()){
                m_head = new Node(value,NULL);
                return m_head;
            }else if(m_head->data() == target){
                Node * newN = new Node (value, NULL);
                newN->m_next = m_head;
                return newN;
            }
            Node* h1 = NULL;
            Node* h2 = m_head;
            while(h2 != NULL){
                if(h2->data() == target && h2 != NULL){
                    h1->m_next=new Node (value,h2);
                    return h1->m_next;

                }
                h1 = h2;
                h2 = h2->m_next;

            }
            return NULL;
}
Node * NodeList::erase(const DataType & target){
    if(m_head->data() == target){
        m_head = m_head->m_next;
        return m_head;
    }
    if(empty()){
        return NULL;
    }else{
        Node * h1, *h2;
        h2= find(target,h1);
        if(h2 != NULL){
            h1->m_next = h2->m_next;
            delete h2;
            return h1;
        }
    }
    return NULL;
    
}

DataType & NodeList::operator[] (size_t position){
    int currPos = 0;
    Node * currNode = m_head;
    for(; currPos < position; currPos++, currNode++);
    return currNode->data();
}
const DataType & NodeList::operator[] (size_t position) const{
    int currPos = 0;
    Node * currNode = m_head;
    for(; currPos < position; currPos++, currNode++);
    return currNode->data();
}
    
size_t NodeList::size() const{
    int count = 0;
    Node * curr = m_head;
    while(curr != nullptr){
        count++;
        //move to next link
        curr = curr->m_next;
    }
    return count;
}
bool NodeList::empty() const{
    if(m_head == NULL){
        return 1;
    }
    return 0;
}
void NodeList::clear(){
    Node * current = m_head;
    Node * prev = m_head;
    while( current != NULL){
        current = current-> m_next;
        delete prev;
        prev = current;
    }
    m_head = NULL;
}	

//Friend Methods
std::ostream & operator<<(std::ostream & os, const NodeList & nodeList){
    
    if(nodeList.empty()){
            os << "Array Empty";
    }else{
        for(int i = 0; i < nodeList.size(); i++){
        os << "Values: " << nodeList[i];
        }
    }
    return os;
}
