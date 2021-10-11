//Purpose: String Class source file
//Name: string.cpp
//Author: Mackenzie Zappe
//Date: 3/28/2020

#include <my_string/MyString.h>
#include <string.h>

//Ctors/dtors
MyString:: MyString()
: m_size(0)
{
    std::cout << "Default Ctor" << std::endl;
    m_buffer = nullptr;
}
MyString:: MyString(const char * str)
{
    int size = strlen(str);
    buffer_allocate(size);
    strcpy(m_buffer,str);
    std::cout << m_buffer << std:: endl;
}
MyString:: MyString(const MyString & other_myStr)
: m_size(other_myStr.size())
{  
    int size = strlen(other_myStr.c_str());
    buffer_allocate(size);
    strcpy(m_buffer, other_myStr.c_str());
    std::cout << m_buffer << " " << m_size << std:: endl;
}
MyString:: ~MyString(){
    buffer_deallocate();
    m_size = 0;
    std::cout << "Dtor " << m_size << std:: endl;
}
//Other Class Methods
size_t MyString:: size() const{
    return strlen(m_buffer) +1;
}
size_t MyString:: length() const{
    return strlen(m_buffer);
}
const char * MyString:: c_str() const{
    return m_buffer;
}
bool MyString:: operator== (const MyString & other_myStr) const{
    if(strcmp(m_buffer, other_myStr.c_str())){
        return 0;
    }
    return 1;
}
MyString & MyString:: operator= (const MyString & other_myStr){
    this -> buffer_deallocate();
    int size = strlen(other_myStr.c_str());
    buffer_allocate(size);
    strcpy(m_buffer, other_myStr.c_str());

}
MyString MyString:: operator+ (const MyString & other_myStr) const{
    char temp[256];
    strcpy(temp, m_buffer);
    MyString newWord("Hello");
    strcat(temp, other_myStr.c_str());    
    int size = strlen(temp);
    newWord.buffer_allocate(size);
    newWord = temp;
    return newWord;
}
char & MyString:: operator[] (size_t index){
    return m_buffer[index];
}
const char & MyString:: operator[] (size_t index) const{
    return m_buffer[index];

}
//Private helper methods
void MyString:: buffer_deallocate(){
    delete [] m_buffer;
}
void MyString:: buffer_allocate(size_t size){
    m_buffer = new char[size+1];
}

//Friend methods 
std::ostream & operator<<(std::ostream & os, const MyString & myStr){
    os << myStr.c_str();
}