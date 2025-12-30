#include "Sorter.hpp"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cerr << "Use: ./executable <mode(int)> <size(int)>\n"; 
        std::cout << "Mode list:\n" << std::endl; 
        std::cout << "0 - insertion sort\n"; 
        std::cout << "1 - merge sort\n"; 
        std::cout << "2 - heap sort\n"; 
        return -1; 
    }

    vec A = generateRandomVector(atoi(argv[2])); 
    test(A, atoi(argv[1])); 
}