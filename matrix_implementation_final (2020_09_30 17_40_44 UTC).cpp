//M2D Dynamic Matrix implementation for final
#include <iostream>

DynamicMatrix()
:m_data(nullptr);
{

}
DynamicMatrix(size_t rows, size_t cols, int value)
:m_data(nullptr)
{
    if (rows == 0 || cols == 0) {
	throw std::bad_alloc();
  }
  
  try {
	m_data = new double * [rows];
	for (std::size_t i_alloc=0; i_alloc<rows; ++i_alloc) {
	  try {
	    m_data[i_alloc] = new double [cols];
	  }
	  catch (const std::bad_alloc & ex) {
		for (std::size_t i_del=0; i_del<i_alloc; ++i_del) {
          delete [] m_data[i_del];
		}
		throw;
	  }
	}
  }
  catch (const std::bad_alloc & ex) {
    delete [] m_data;
	std::cerr << "Matrix2D construction failure: " << ex.what() << std::endl;
	throw;
  }
  m_cols = cols;
  m_rows = rows;


    for (std::size_t i_row=0; i_row<m_rows; ++i_row) {
    for (std::size_t i_col=0; i_col<m_cols; ++i_col) {
      m_data[i_row][i_col] = value;
    }
  }
}

DynamicMatrix(const DynamicMatrix & other)
: m_data(nullptr);
{
if (other.rows == 0 || other.cols == 0) {
	throw std::bad_alloc();
  }
  
  try {
	m_data = new double * [other.rows];
	for (std::size_t i_alloc=0; i_alloc<rows; ++i_alloc) {
	  try {
	    m_data[i_alloc] = new double [other.cols];
	  }
	  catch (const std::bad_alloc & ex) {
		for (std::size_t i_del=0; i_del<i_alloc; ++i_del) {
          delete [] m_data[i_del];
		}
		throw;
	  }
	}
  }
  catch (const std::bad_alloc & ex) {
    delete [] m_data;
	std::cerr << "Matrix2D construction failure: " << ex.what() << std::endl;
	throw;
  }
  m_cols = other.cols;
  m_rows = other.rows;

    for (std::size_t i_row=0; i_row<m_rows; ++i_row) {
    for (std::size_t i_col=0; i_col<m_cols; ++i_col) {
      m_data[i_row][i_col] = other.m_data[i_row][i_col];
    }
  }
}

~DynamicMatrix(){
      if (m_data != nullptr) {
    for (std::size_t i=0; i<m_rows; ++i){
      delete [] m_data[i];
    }
    delete [] m_data;
  }
}

DynamicMatriz & operator = (const DynamicMatrix & rhs){
    if(this != &rhs){
        if(rhs){
            if (m_data != nullptr) {
                for (std::size_t i=0; i<m_rows; ++i){
                    delete [] m_data[i];
                }
                delete [] m_data;
                m_data = nullptr;
            }

            if (rhs.rows == 0 || rhs.cols == 0) {
                throw std::bad_alloc();
            }
    
            try {
                m_data = new double * [rhs.rows];
                for (std::size_t i_alloc=0; i_alloc<rows; ++i_alloc) {
                try {
                    m_data[i_alloc] = new double [rhs.cols];
                }
                catch (const std::bad_alloc & ex) {
                    for (std::size_t i_del=0; i_del<i_alloc; ++i_del) {
                    delete [] m_data[i_del];
                    }
                    throw;
                }
                }
            }
            catch (const std::bad_alloc & ex) {
                delete [] m_data;
                std::cerr << "Matrix2D construction failure: " << ex.what() << std::endl;
                throw;
            }
            m_cols = rhs.cols;
            m_rows = rhs.rows;
            for (std::size_t i_row=0; i_row<m_rows; ++i_row) {
                for (std::size_t i_col=0; i_col<m_cols; ++i_col) {
                m_data[i_row][i_col] = rhs.m_data[i_row][i_col];
                }
            }
        }

    }
    return *this;
}