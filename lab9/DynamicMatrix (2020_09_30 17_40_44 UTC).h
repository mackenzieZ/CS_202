#ifndef DYNAMICMATRIX_H_
#define DYNAMICMATRIX_H_

#include <iostream>

class DynamicMatrix {
	
  friend std::ostream & operator<<(std::ostream& os, const DynamicMatrix & dm);

 public: 
  DynamicMatrix(int cols, int rows, int value=0);
  DynamicMatrix(const DynamicMatrix& other);
  ~DynamicMatrix();

  DynamicMatrix & operator=(const DynamicMatrix & rhs);
    
 private:
  int ** m_matrix;
  int m_cols;
  int m_rows;
};

#endif //DYNAMICMATRIX_H_
