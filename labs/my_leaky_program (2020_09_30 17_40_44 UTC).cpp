#include <cstddef>
#include <iostream>
#include <string> //string
#include <memory> //unique_ptr
using namespace std;

class Person {
  public:
    Person(const char * name)
      : m_name(name)
    {
    }
  protected:
    std::string m_name;
};


class Student : public Person {
  public:
    Student()
      : Person("")
    {
      m_grades = new uint32_t[42]; 
    }
    Student(const char * name,
            std::size_t grades_num)
      : Person(name)
    {
      m_grades = new uint32_t[grades_num];
    }
    ~Student()
    {
      delete [] m_grades;
    }
  private:
    uint32_t * m_grades;
};


class Director : public Person {
  public:
    Director(const char * name, uint32_t salary)
      : Person(name)
      , m_salary(salary)
    {
    }
  private:
    uint32_t m_salary;
};


class University {
  public:
    University(const char * director_name,
          uint32_t director_salary,
          std::size_t student_roster_size)
    {
      m_students = new Student[student_roster_size];
      m_director.reset(new Director(director_name, director_salary));
    }
  ~University(){
    std::cout << "dtor being called" << std::endl;
    delete [] m_students;
  }
    
  private:
    std::unique_ptr<Director> m_director;
    Student * m_students;
};




int main(int argc, char * argv[]) {

  University unr("Johnson", 1000, 300);

  return 0;
}