#include "../include/includer.hpp"
#include "../src/Sorter.hpp"

using vec = vector<int>; 
constexpr int MINVAL = -1000; 
constexpr int MAXVAL = 1000; 

vec generateRandomVector(int n) {
    if (n <= 0) return {};
    std::random_device rd; 

    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(MINVAL, MAXVAL);

    vec A(n);
    for (int i = 0; i < n; ++i) {
        A[i] = distrib(gen);
    }

    return A;
}

void printVector(vec& A)
{   
    if(A.size() == 0)
    {
        std::cout << "Empty Array!" << std::endl; 
        return; 
    }
    std::cout << "{"; 
    for(size_t i = 0; i < A.size() - 1; ++i)
        std::cout << A[i] << ", "; 

    std::cout << A[A.size()-1] << "}" << std::endl; 
}

void test(vec& A, int mode)
{   
    string sort; 
    if(A.size() < 15)
        printVector(A); 
    
    unique_ptr<Sorter> sorter = nullptr; 
    switch(mode)
    {
        case 0: 
            sorter = make_unique<InsertionSort>(A); 
            break; 
        case 1: 
            sorter = make_unique<MergeSort>(A); 
            break; 
        case 2: 
            sorter = make_unique<HeapSort>(A); 
            break; 
        case 3: 
            sorter = make_unique<QuickSort>(A); 
            break; 
    }
    
    sorter -> sort(); 
    if(A.size() < 15)
        printVector(A); 

    sorter -> printTime(); 
    
}