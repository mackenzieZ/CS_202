//Purpose: Templated Recursive function implementaions/ declarations
//Name: VectorRecursion.hpp
//Author: Mackenzie Zappe
//Date: 5/5/2020

#include <vector>
#include <iostream>


template <class T>
void quickSort(std::vector<T> & vec, T start, T end){ 
    T i = start, j = end, mid, piv, temp;
    mid = start + (end - start)/2;
    piv = vec[mid];

    while(i < end || j>start){
        while(vec[i] < piv){
            i++;
        }
        while(vec[j] > piv){
            j--;
        }
        if(i <=j){
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }else{
            if(i < end){
                quickSort(vec, i, end);
            }
            if(j > start){
                quickSort(vec, start, j);
            }
            return;
        }
    }

}

template <class T>
T research(std::vector<T> & array, size_t size, T target){
    T lower = 0, upper = size - 1;
    while(lower <=  upper){
        T index = std::floor((lower+upper)/2);
        if(array[index] < target){
            lower = index +1;
        }else if(array[index] > target){
            upper = index -1;
        }else{
            return index;
        }
    }

    return -1;
}
