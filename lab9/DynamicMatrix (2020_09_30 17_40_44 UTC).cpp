#include <iostream>

#include "DynamicMatrix.h"

DynamicMatrix::DynamicMatrix(int cols, int rows, int value)
  : m_cols(cols),
    m_rows(rows)
{ 
  if (m_cols && m_rows){  //allocate only when it makes sense
    m_matrix = new(std::nothrow) int* [m_rows];
    if (m_matrix){
      for (int i=0; i<m_rows; ++i){
        m_matrix[i] = new(std::nothrow) int [m_cols]; 
        if (m_matrix[i]){
          for (int k=0; k<m_cols; ++k){  //only assign values to the row we have just allocated (no [j][i] over [m_rows][m_cols], because some rows have not been allocated yet) 
            m_matrix[i][k] = value;
          }
        }
        else{  //row allocation failed, cleanup everything (could retry too)
          for (; i>=0; --i){
            delete [] m_matrix[i];
	  }
          delete [] m_matrix;
          m_rows = 0;
          m_cols = 0;
          break;
        }
      }
    }
    else{
      m_rows = 0;
      m_cols = 0;
      m_matrix = NULL;
    }
  }
  else{
    m_matrix = NULL;
  }
}

DynamicMatrix::~DynamicMatrix()
{
  for (int i=0; i<m_rows; ++i){
    delete [] m_matrix[i];
  }
  delete [] m_matrix;
}

std::ostream & operator<<(std::ostream & os, const DynamicMatrix & dm){ 
  for (int j=0; j<dm.m_rows; ++j){	
    os << "[";
    for (int i=0; i<dm.m_cols; ++i){
      os << " " << dm.m_matrix[j][i];  
    }
    os << " ]";
    os << std::endl;
  }
  return os; 
}


DynamicMatrix::DynamicMatrix(const DynamicMatrix & other)
  : m_cols(other.m_cols),
    m_rows(other.m_rows)
{ 

      try{
      m_matrix = new int *[m_rows];
        for(size_t i = 0; i < m_rows; ++i){
          m_matrix[i] = nullptr;
        }
        for(size_t i = 0; i< m_rows; ++i){
          try{
            m_matrix[i] = new int [m_cols];
            
          }
          catch(std::bad_alloc & ex){
            for(;i>=0;--i){
              delete[] m_matrix[i];
              throw;
            }
          }
        }
      }
        catch(const std::bad_alloc & ex){
          delete [] m_matrix;
        }
        
        if(m_matrix){
              for(std::size_t k = 0; k < m_rows; k++){
                for(std::size_t l = 0; l < m_rows; l++){
                  m_matrix[k][l]= other.m_matrix[k][l];
                }
              }
            }else{
              std::cerr<<"DynamicVector: Allocation failed!" << std::endl;
              m_rows = 0;
              m_cols = 0;
            }
        
      
  


}

DynamicMatrix & DynamicMatrix::operator=(const DynamicMatrix & rhs)
{ 
  if (this != &rhs){  //check for self-assignment
    if (m_rows != rhs.m_rows){  //allocate only when it makes sense
      for(size_t i=0; i<m_rows; ++i){
        delete [] m_matrix[i];
      }
      delete [] m_matrix;
      m_matrix = nullptr;

      //reallocate
     try{
       m_rows=rhs.m_rows;
      m_matrix = new int *[m_rows];
        for(size_t i = 0; i < m_rows; ++i){
          m_matrix[i] = nullptr;
        }
        for(size_t i = 0; i< m_rows; ++i){
          try{
            m_cols=rhs.m_cols;
            m_matrix[i] = new int [m_cols];
            
          }
          catch(std::bad_alloc & ex){
            for(;i>=0;--i){
              delete[] m_matrix[i];
              throw;
            }
          }
        }
      }
        catch(const std::bad_alloc & ex){
          delete [] m_matrix;
        }
        //copy
        if(m_matrix){
              for(std::size_t k = 0; k < m_rows; k++){
                for(std::size_t l = 0; l < m_rows; l++){
                  m_matrix[k][l]= rhs.m_matrix[k][l];
                }
              }
        }else{
              std::cerr<<"DynamicVector: Allocation failed!" << std::endl;
              m_rows = 0;
              m_cols = 0;
        }
  return *this;
}

  

}
}

