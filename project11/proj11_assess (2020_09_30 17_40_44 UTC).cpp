//Purpose: Critical assessment of vector functions
//Name: proj11_assess.cpp
//Author: Mackenzie Zappe
//Date: 5/5/2020

#include <iostream>
#include <cstring>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <chrono>
#include <cmath>
#include "VectorRecursion.hpp"
using namespace std::chrono;

#define CAPACITY_1 100
#define CAPACITY_2 1000
#define CAPACITY_3 10000
#define CAPACITY_4 100000

int main(){
    std::ofstream outSortP;
    std::ofstream outSortS;
    std::ofstream outSearchP;
    std::ofstream outSearchS;
    outSortP.open("PersonalSortResults.txt");
    outSortS.open("StandardSortResults.txt");
    outSearchP.open("PersonalSearchResults.txt");
    outSearchS.open("StandardSearchResults.txt");

    outSortP << "Vector_Capacity = 100 \n";
    outSortS << "Vector_Capacity = 100 \n";
    outSearchP << "Vector_Capacity = 100 \n";
    outSearchS << "Vector_Capacity = 100 \n";
    for(int i = 0; i < 100; ++i){
        std::cout<< "============Personal Function Testing==========" << "\n";
        std::vector<int> vecInt1 (CAPACITY_1);
        
        for(int i = 0; i < CAPACITY_1; i++){
            vecInt1.push_back(std::rand());
        }
        //Timing Personal Quicksort Duration
        auto start1 = high_resolution_clock::now();
        quickSort(vecInt1, 0, CAPACITY_1);
        auto stop1 = high_resolution_clock::now();

        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        outSortP << duration1.count() << "\n"; 
        std::cout << "Personal QuickSort duration:  " << duration1.count() << " microseconds" << std:: endl;

        
        int target1 = 5;


        auto start2 = high_resolution_clock::now();    
        research(vecInt1, vecInt1.size(), target1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        outSearchP << duration2.count() << "\n";
        std::cout << "Personal Research duration:  " << duration2.count() << " microseconds" << std:: endl;


        std::cout<< "=========Standard Function Testing===========" << "\n";

        std::vector<int> vecInt2 (CAPACITY_1);
        

        for(int i = 0; i < CAPACITY_1; i++){
            vecInt2.push_back(std::rand());
        }
        //Timing Personal Quicksort Duration
        auto start3 = high_resolution_clock::now();
        std::sort(vecInt2.begin(), vecInt2.end());
        auto stop3 = high_resolution_clock::now();

        auto duration3 = duration_cast<microseconds>(stop3 - start3);
        outSortS << duration3.count() << "\n";
        std::cout << "Standard Sort duration:  " << duration3.count() << " microseconds" << std:: endl;

        
        int target2 = 5;

        auto start4 = high_resolution_clock::now();    
        std::binary_search(vecInt2.begin(), vecInt2.end(), target2);
        auto stop4 = high_resolution_clock::now();
        auto duration4 = duration_cast<microseconds>(stop4 - start4);
        outSearchS << duration4.count() << "\n";
        std::cout << "Standard Binary Search duration:  " << duration4.count() << " microseconds" << std:: endl;
    }

    outSortP << "Vector_Capacity = 1,000 \n";
    outSortS << "Vector_Capacity = 1,000 \n";
    outSearchP << "Vector_Capacity = 1,000 \n";
    outSearchS << "Vector_Capacity = 1,000 \n";
    for(int i = 0; i < 100; ++i){
        std::cout<< "============Personal Function Testing==========" << "\n";
        std::vector<int> vecInt1 (CAPACITY_2);
        
        for(int i = 0; i < CAPACITY_1; i++){
            vecInt1.push_back(std::rand());
        }
        //Timing Personal Quicksort Duration
        auto start1 = high_resolution_clock::now();
        quickSort(vecInt1, 0, CAPACITY_2);
        auto stop1 = high_resolution_clock::now();

        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        outSortP << duration1.count() << "\n"; 
        std::cout << "Personal QuickSort duration:  " << duration1.count() << " microseconds" << std:: endl;

        
        int target1 = 5;


        auto start2 = high_resolution_clock::now();    
        research(vecInt1, vecInt1.size(), target1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        outSearchP << duration2.count() << "\n";
        std::cout << "Personal Research duration:  " << duration2.count() << " microseconds" << std:: endl;


        std::cout<< "=========Standard Function Testing===========" << "\n";

        std::vector<int> vecInt2 (CAPACITY_2);
        

        for(int i = 0; i < CAPACITY_1; i++){
            vecInt2.push_back(std::rand());
        }
        //Timing Personal Quicksort Duration
        auto start3 = high_resolution_clock::now();
        std::sort(vecInt2.begin(), vecInt2.end());
        auto stop3 = high_resolution_clock::now();

        auto duration3 = duration_cast<microseconds>(stop3 - start3);
        outSortS << duration3.count() << "\n";
        std::cout << "Standard Sort duration:  " << duration3.count() << " microseconds" << std:: endl;

        
        int target2 = 5;

        auto start4 = high_resolution_clock::now();    
        std::binary_search(vecInt2.begin(), vecInt2.end(), target2);
        auto stop4 = high_resolution_clock::now();
        auto duration4 = duration_cast<microseconds>(stop4 - start4);
        outSearchS << duration4.count() << "\n";
        std::cout << "Standard Binary Search duration:  " << duration4.count() << " microseconds" << std:: endl;
    }

    outSortP << "Vector_Capacity = 10,000 \n";
    outSortS << "Vector_Capacity = 10,000 \n";
    outSearchP << "Vector_Capacity = 10,000 \n";
    outSearchS << "Vector_Capacity = 10,000 \n";
    for(int i = 0; i < 100; ++i){
        std::cout<< "============Personal Function Testing==========" << "\n";
        std::vector<int> vecInt1 (CAPACITY_3);
        
        for(int i = 0; i < CAPACITY_1; i++){
            vecInt1.push_back(std::rand());
        }
        //Timing Personal Quicksort Duration
        auto start1 = high_resolution_clock::now();
        quickSort(vecInt1, 0, CAPACITY_3);
        auto stop1 = high_resolution_clock::now();

        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        outSortP << duration1.count() << "\n"; 
        std::cout << "Personal QuickSort duration:  " << duration1.count() << " microseconds" << std:: endl;

        
        int target1 = 5;


        auto start2 = high_resolution_clock::now();    
        research(vecInt1, vecInt1.size(), target1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        outSearchP << duration2.count() << "\n";
        std::cout << "Personal Research duration:  " << duration2.count() << " microseconds" << std:: endl;


        std::cout<< "=========Standard Function Testing===========" << "\n";

        std::vector<int> vecInt2 (CAPACITY_3);
        

        for(int i = 0; i < CAPACITY_1; i++){
            vecInt2.push_back(std::rand());
        }
        //Timing Personal Quicksort Duration
        auto start3 = high_resolution_clock::now();
        std::sort(vecInt2.begin(), vecInt2.end());
        auto stop3 = high_resolution_clock::now();

        auto duration3 = duration_cast<microseconds>(stop3 - start3);
        outSortS << duration3.count() << "\n";
        std::cout << "Standard Sort duration:  " << duration3.count() << " microseconds" << std:: endl;

        
        int target2 = 5;

        auto start4 = high_resolution_clock::now();    
        std::binary_search(vecInt2.begin(), vecInt2.end(), target2);
        auto stop4 = high_resolution_clock::now();
        auto duration4 = duration_cast<microseconds>(stop4 - start4);
        outSearchS << duration4.count() << "\n";
        std::cout << "Standard Binary Search duration:  " << duration4.count() << " microseconds" << std:: endl;
    }

    outSortP << "Vector_Capacity = 100,000 \n";
    outSortS << "Vector_Capacity = 100,000 \n";
    outSearchP << "Vector_Capacity = 100,000 \n";
    outSearchS << "Vector_Capacity = 100,000 \n";
    for(int i = 0; i < 100; ++i){
        std::cout<< "============Personal Function Testing==========" << "\n";
        std::vector<int> vecInt1 (CAPACITY_4);
        
        for(int i = 0; i < CAPACITY_1; i++){
            vecInt1.push_back(std::rand());
        }
        //Timing Personal Quicksort Duration
        auto start1 = high_resolution_clock::now();
        quickSort(vecInt1, 0, CAPACITY_4);
        auto stop1 = high_resolution_clock::now();

        auto duration1 = duration_cast<microseconds>(stop1 - start1);
        outSortP << duration1.count() << "\n"; 
        std::cout << "Personal QuickSort duration:  " << duration1.count() << " microseconds" << std:: endl;

        
        int target1 = 5;


        auto start2 = high_resolution_clock::now();    
        research(vecInt1, vecInt1.size(), target1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        outSearchP << duration2.count() << "\n";
        std::cout << "Personal Research duration:  " << duration2.count() << " microseconds" << std:: endl;


        std::cout<< "=========Standard Function Testing===========" << "\n";

        std::vector<int> vecInt2 (CAPACITY_4);
        

        for(int i = 0; i < CAPACITY_1; i++){
            vecInt2.push_back(std::rand());
        }
        //Timing Personal Quicksort Duration
        auto start3 = high_resolution_clock::now();
        std::sort(vecInt2.begin(), vecInt2.end());
        auto stop3 = high_resolution_clock::now();

        auto duration3 = duration_cast<microseconds>(stop3 - start3);
        outSortS << duration3.count() << "\n";
        std::cout << "Standard Sort duration:  " << duration3.count() << " microseconds" << std:: endl;

        
        int target2 = 5;

        auto start4 = high_resolution_clock::now();    
        std::binary_search(vecInt2.begin(), vecInt2.end(), target2);
        auto stop4 = high_resolution_clock::now();
        auto duration4 = duration_cast<microseconds>(stop4 - start4);
        outSearchS << duration4.count() << "\n";
        std::cout << "Standard Binary Search duration:  " << duration4.count() << " microseconds" << std:: endl;
    }

outSortP.close();
outSortS.close();
outSearchP.close();
outSearchS.close();

return 0; 
}