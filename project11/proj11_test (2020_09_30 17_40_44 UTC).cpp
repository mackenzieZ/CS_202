//Purpose: Testing the Templated functions with Vectors 
//Name: tempVecTest.cpp
//Author: Mackenzie Zappe
//Date: 5/5/2020

#include<iostream> 
#include<fstream>
#include<vector>
#include<cmath>

#include <VectorRecursion.hpp>

int main(){
    std::vector<int> vecInt;
    /*
    std::ifstream info("RandomData.txt");
    while(info){
        int info_in;
        info >> info_in;
        if(!info){
            break;
        }
        vecInt.push_back(info_in);
    }
    */
    for(int i = 0; i < 100; i++){
            vecInt.push_back(std::rand());
    }


    std::cout << "Before sort Values: ";
    for(size_t i = 0; i < vecInt.size(); ++i){
        std::cout << vecInt[i] << " "; 
    }
    std::cout<< "\n";

    quickSort(vecInt, 0, 100);

    std::cout << "After sort Values: ";
    for(size_t i = 0; i < vecInt.size(); ++i){
        std::cout << vecInt[i] << " "; 
    }
    std::cout<< "\n";
    std::cout << "Vector Sort = Success" << std::endl;
    
    int target;
    std::cout << "Enter an integer you would like to find in the data set: ";
    std::cin >> target;

    if(research(vecInt, vecInt.size(), target) != -1){
    std::cout << "Vector Research is a Success! Target is at index: " << research(vecInt, vecInt.size(), target) << std::endl;
    }else{
    std::cout << "Vector Research is a Failure!" << std::endl;
    }
    



return 0;
}