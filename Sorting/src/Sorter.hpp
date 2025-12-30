#include "../include/includer.hpp"

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

// === INSERTION SORT === 
void insertion_sort(vec& A)
{
    if(A.size() == 1) return; 
    for(size_t j = 1; j < A.size(); ++j)
    {
        int k = A[j]; 
        int i = j-1; 
        while(i >= 0 && A[i] > k)
        {
            A[i + 1] = A[i]; 
            --i; 
        }
        A[i + 1] = k; 
    }
}

// === MERGE SORT === 
void merge(vec& A, int p, int q, int r)
{
    int n1 = q - p + 1; 
    int n2 = r - q; 
    vec L(n1 + 1), R(n2 + 1); 
    for(int i = 0; i < n1; ++i)
        L[i] = A[p + i]; 
    for(int i = 0; i < n2; ++i)
        R[i] = A[q + i + 1]; 

    L[n1] = INT_MAX; 
    R[n2] = INT_MAX; 

    int i = 0, j = 0; 
    for(int k = p; k <= r; ++k)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i]; 
            ++i; 
        }
        else
        {
            A[k] = R[j]; 
            ++j; 
        }
    }
}

void merge_sort(vec&A, int p, int r)
{
    if(p < r)
    {
        int q = p + (r - p) / 2; 
        merge_sort(A, p, q); 
        merge_sort(A, q+1, r); 
        merge(A, p, q, r); 
    }
}

class HeapSort
{   
    private: 
        vec& A; 
        int heap_size; 
        int parent(int i){return  (i-1)/2;}
        int left(int i){return 2 * i + 1;}
        int right(int i){return 2 * i + 2;}

        void max_heapify(int i)
        {
            int max = i; 
            int l = left(i); 
            int r = right(i); 
            if(l < heap_size && A[l] > A[i]) max = l; 
            if(r < heap_size && A[r] > A[max]) max = r; 
            if(max != i)
            {
                swap(A[i], A[max]); 
                max_heapify(max); 
            }
        }

        void build_max_heap()
        {
            heap_size = A.size();
            for(int i = A.size()/2 - 1; i >= 0; --i) 
                max_heapify(i); 
        }

    public: 
        HeapSort(vec& A_) : A(A_){heap_size = A.size();}

        void heap_sort()
        {
            build_max_heap(); 
            for(int i = A.size() - 1; i > 0; --i)
            {
                swap(A[0], A[i]); 
                --heap_size; 
                max_heapify(0); 
            }
        }

}; 

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
    clock_t t0 = clock(); 
    string sort; 
    if(A.size() < 15)
        printVector(A); 
    switch(mode)
    {
        case 0: 
            sort = "INSERTION-SORT"; 
            insertion_sort(A); 
            break; 
        case 1: 
            sort = "MERGE-SORT";
            merge_sort(A, 0, A.size()-1); 
            break; 
        case 2: 
            sort = "HEAP-SORT"; 
            HeapSort sorter(A); 
            sorter.heap_sort(); 
            break; 
    }
    if(A.size() < 15)
        printVector(A); 
    clock_t tf = clock() - t0; 
    double seconds = ((double)tf) / CLOCKS_PER_SEC;
    std::cout << "\n=== Total time " << sort << " (seconds): " << seconds << " ===\n" << std::endl; 
}