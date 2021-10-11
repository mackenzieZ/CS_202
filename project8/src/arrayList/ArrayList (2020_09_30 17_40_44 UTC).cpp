//Purpose: Array List source code
//Name: ArrayList.cpp
//Author: Mackenzie Zappe
//Date: 4/13/2020
#include <arrayList/ArrayList.h>

//Ctors & Dtor
ArrayList::ArrayList()
:m_size(0), m_maxsize(0)
{
    m_array =NULL;

}
ArrayList::ArrayList(size_t count, const DataType & value)
: m_size(count), m_maxsize(count)
{
    m_array = new DataType[m_maxsize];
    for(int i = 0; i < m_size; i ++){
        m_array[i] = value;
    }
}
ArrayList::ArrayList(const ArrayList & other)
: m_size(other.size()), m_maxsize(other.size())
{
    m_array = new DataType[m_maxsize];
     for(int i = 0; i < m_size; i ++){
        m_array[i] = other.m_array[i];
    }
}

ArrayList::~ArrayList(){
    if(m_array!= nullptr){
        delete [] m_array; 
    }
    std::cout << "ArrayList Dtor" << std:: endl;
}
//Public Methods
ArrayList & ArrayList::operator= (const ArrayList & rhs){
    if(this != &rhs){
        m_size = rhs.m_size;
        m_maxsize = rhs.m_maxsize;
        for(size_t i = 0; i != m_maxsize; i++){
            m_array[i] = rhs.m_array[i]; 
        }
    }else{

        return *this;
    }
    return *this;
}


DataType * ArrayList::front(){
        if(m_array == NULL){
            std::cout << "List Empty" << std:: endl;
            return NULL;
        }else{
            return &m_array[0];
        }
}
DataType * ArrayList::back(){
    if(m_array == NULL){
            std::cout << "List Empty...Failure" << std:: endl;
            return NULL;
        }else{
            return &m_array[m_size];
        }
}
	
DataType * ArrayList::find(const DataType & target,	DataType * & previous, const DataType * start){
        DataType *ptr = m_array;
        if(ptr != NULL){
            for(int i = 0; i< m_size; i++, ptr++){
                if(*ptr == target){
                    if(ptr-- != NULL){
                        previous = ptr--;
                    }else{
                        previous = NULL;
                    }
                    return ptr;
                }
            }
        }else{
            previous = NULL;
            return NULL;
        }
}
	
DataType * ArrayList::insertAfter(const DataType & target,const DataType & value){
    size_t i = 0;
    DataType * current = m_array;
    while(current != NULL){
        if(*current == target){
            int next = i+1;
            for(int j = m_size -1; j > i; j--){
                m_array[j] = m_array[j-1];
            }
            m_array[next]=value;
            *current = m_array [next];
            return current;
        }
        i++; current++;
    }
    if(empty()){
        m_array[0]=value;
        *current = m_array[0];
        m_size++;
        return current;
    }
    return NULL;
}

DataType * ArrayList::insertBefore(const DataType & target, const DataType & value){
        size_t i = 0;
    DataType * current = m_array;
    while(current != NULL){
        if(*current == target){
            for(int j = m_size -1; j > i; j--){
                m_array[j] = m_array[j-1];
            }
            m_array[i]=value;
            return current;
        }
        i++; current++;
    }
    if(empty()){
        m_array[0]=value;
        *current = m_array[0];
        m_size++;
        return current;
    }
    return NULL;         
}

DataType * ArrayList::erase(const DataType & target){
    int count = 0;
    DataType * current = m_array;
    while(current != NULL){
        if(target == *current){
            for(int i = count; i< m_size; i++){
                m_array[i-1] = m_array[i];
            }
            if(count == 0){
                return m_array;
            }else{
                return current --;

            }

        }
        count++; current++;
    }
    return NULL;
}

	
DataType & ArrayList::operator[] (size_t position){
    return m_array[position];
}

const DataType & ArrayList::operator[] (size_t position) const{
    return m_array[position];
}

size_t ArrayList::size() const{
    return m_size;
}

bool ArrayList::empty() const{
    if(m_array==nullptr){
        return 1;
    }
    return 0;
}

void ArrayList::clear(){
    DataType zero(0,0);
    for(int i = 0; i < m_size; i ++){
        m_array[i] = zero;
    }
    //no deallocation
}
//Private Methods
void ArrayList::resize(size_t count){
    DataType * temp = new DataType[m_size];
    if(m_array!=nullptr){
        for(int i = 0; i < m_size; i++){
            temp[i] = m_array[i];
        }
    }else{
        for(int i = 0; i < m_size; i++, temp++){
            temp =nullptr;
        }
    }
    delete [] m_array;
    m_array= nullptr;
    m_maxsize = count+m_maxsize;
    m_array = new DataType[m_maxsize];
    for(int i = 0; i<m_maxsize; i++,m_array++,temp++){
        if(m_size < m_maxsize && i>m_size){
            m_array = 0;
        }else{
            m_array = temp;

        }
    }
}	

//Friend Methods
std::ostream & operator<<(std::ostream & os,const ArrayList & arrayList){
    if(arrayList.empty()){
            os << "Array Empty";
    }else{
        for(int i = 0; i != arrayList.m_size; i++){
            
            os << "Values: " << arrayList.m_array[i];
        }
    }
    return os;
}