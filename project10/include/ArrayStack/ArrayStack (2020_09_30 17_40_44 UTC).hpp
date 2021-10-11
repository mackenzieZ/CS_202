//Purpose: Array Stack Template Class (header and source file)
//Name: ArrayStack.hpp
//Author: Mackenzie Zappe
//Date: 4/27/2020

#ifndef ARRAYSTACK_HPP_
#define ARRAYSTACK_HPP_

#include <iostream>
//#include "DataType.h"

template <typename T> class ArrayStack;
template <typename T> std::ostream & operator <<(std::ostream& os, const ArrayStack <T> & arrayStack);

const size_t ARRAY_CAPACITY = 1000;

template <typename T>
class ArrayStack{
    friend std:: ostream & operator << <> (std::ostream & os, const ArrayStack<T> & arrayStack);

    public:
        ArrayStack()
        : m_top(0){}

        ArrayStack(size_t count, const T & value){
            if(count < ARRAY_CAPACITY && count > 0){
                size_t i = 0;
                m_top = count;
                while( i <= m_top){
                    m_container[i] = value;
                    i++;
                }

            }else{
                std::cout << "Count value not valid" << std::endl;
                m_top = 0;
            }
        }

        ArrayStack(const ArrayStack<T> & other){
            m_top = other.m_top;
            for(size_t i = 0; i <= m_top; i++){
                m_container[i] = other.m_container[i];
            }
        }

        ~ArrayStack(){
            clear();
            std::cout << "ArrayStack Dtor" << std::endl;
        }

        ArrayStack & operator= (const ArrayStack<T> & rhs){
            if(this != &rhs){
                m_top = rhs.m_top;
                for(size_t i = 0; i < m_top; i++){
                    m_container[i] = rhs.m_container[i];
                }
                return *this;
            }
            
            return *this; 
        }

        T & top(){
            return m_container[m_top];
        }

        const T & top()const{
            return m_container[m_top];
        }

        void push(const T & value){
            if(m_top < ARRAY_CAPACITY){
                m_top++;
                m_container[m_top] = value;
            }else{
                std::cout <<"ArrayStack full, cannot add value" << std::endl;
            }
        }

        void pop(){
            if(!empty()){
                T empty(-1, -1.1);
                m_container[m_top] = empty;
                m_top -= 1;
            }else{
                std::cout << "Stack is empty, no popping needed" << std::endl;
            }
        }

        size_t size() const{
            return m_top;
        }

        bool empty() const{
            if(m_top == 0){
                return true;
            }else{
                return false;
            }
        }

        bool full() const{
            if(m_top == (ARRAY_CAPACITY -1)){
                return true;
            }else{
                return false;
            }
        }

        void clear(){
            if(!empty()){
                do{
                    pop();
                }while(!empty());
            }else{
                std::cout << "This stack is empty" << std::endl;
            }
        }

        void serialize(std::ostream & os) const{
            if(!empty()){
                for(size_t i = 0; i < m_top; i++){
                    os << m_container[i] << " ";
                }
            }else{
                os << "Empty" << std::endl;
            }
            os << std::endl;
        }


    private:
        T m_container[ARRAY_CAPACITY];
        size_t m_top;

};

template <typename T>
std::ostream & operator<<(std::ostream & os, const ArrayStack<T> & arrayStack){
    arrayStack.serialize(os);
    return os;
}

#endif