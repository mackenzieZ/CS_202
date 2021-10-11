//Purpose: Node Stack Template Class (header and source file)
//Name: NodeStack.hpp
//Author: Mackenzie Zappe
//Date: 4/28/2020

#ifndef NODESTACK_H_
#define NODESTACK_H_

#include <iostream>
//#include "DataType.h"

template <typename T> class NodeStack;
template <typename T> std:: ostream & operator<< (std::ostream &os, const NodeStack<T> & nodeStack);

template <typename T>
class Node {

    friend class NodeStack <T>;

    public:
        Node()
        :m_next(nullptr) {;}
        Node(const T & data, Node<T> *next = nullptr)
        :m_next(next), m_data(data){;}
        T  & data(){
            return m_data;
        }
        const T & data()const{
            return m_data;
        }

    private:
        Node * m_next;
        T m_data;
};

template <typename T>
class NodeStack{
    friend std:: ostream & operator << <> (std::ostream & os, const NodeStack<T> & nodeStack);

    public:
        NodeStack()
        : m_top(nullptr) {}
        NodeStack(size_t count, const T & value= T()){
            if(count >= 1){
                m_top = nullptr;
                for(size_t i = 0; i < count; i++){
                    push(value);
                }
            }else{
                std::cout << "Count invalid" << std::endl;
                m_top = nullptr;
            }
        }

        NodeStack(const NodeStack<T> & other){
            m_top = new Node<T>(other.m_top->data(), nullptr);
            Node <T> * othercp = other.m_top;
            Node <T> * thiscp = m_top;

            while(othercp->m_next){
                thiscp->m_next = new Node<T>(othercp->data(), nullptr);
                thiscp = thiscp->m_next;
                othercp = othercp->m_next;
            }
        }
        
        ~NodeStack(){
            clear();
            std::cout << "Dtor NodeStack" << std::endl;
        }

        NodeStack & operator=(const NodeStack<T> &rhs){
            if(this != &rhs){
                m_top = new Node<T>(rhs.m_top->data(), nullptr);
                Node<T> * cpy = m_top;
                Node<T> * rhscpy = rhs.m_top;
                while(rhscpy->m_next != nullptr){
                    cpy->m_next = new Node<T>(rhscpy->data(), nullptr);
                    rhscpy = rhscpy->m_next;
                    cpy = cpy->m_next; 
                }
                return *this;
            }else{
                return *this;

            }
        }

        T & top(){
            return m_top->data();
        }

        const T & top() const{
            return m_top->data();
        }

        void push(const T & value){
            if(!empty()){
                Node<T> * newN = new Node<T>(value, nullptr);
                newN->m_next = m_top;
                m_top = newN;
            }else{
                m_top = new Node<T>(value, nullptr);
            }
        }

        void pop(){
            if(!empty()){
                Node<T> * topN = m_top;
                m_top = m_top->m_next;
                delete topN;
                topN = nullptr;
            }else{
                std::cout << "Stack is empty" << std::endl;
            }
        }

        size_t size() const{
            size_t i = 0;
            if(!empty()){
                Node<T> * size = m_top;
                while(size != nullptr){
                    i++;
                    size = size->m_next;
                }
            }
            return i;
        }

        bool empty() const{
            if(m_top == nullptr){
                return true;
            }else{
                return false;
            }
        }

        bool full() const{
            return false;
        }

        void clear(){
            if(!empty()){
                do{
                    pop();
                }while(!empty());
            }else{
                std::cout << "Stack is empty" << std::endl;
            }
        }

        void serialize(std::ostream & os) const{
            if(!empty()){
                Node<T> * traverse = m_top;
                while(traverse != nullptr){
                    os << traverse->data() << " ";
                    traverse = traverse->m_next;
                }
            }else{
                os << "Stack empty";
            }
            os << std::endl;
        }

    private:
    Node<T> * m_top;
};

template<typename T>
std::ostream & operator << (std::ostream & os, const NodeStack<T> & nodeStack){
    nodeStack.serialize(os);
    return os;
}

#endif