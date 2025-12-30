#include "../include/includer.hpp"

using vec = vector<int>; 

class Sorter
{
    protected: 
        string sorterName; 
        clock_t t0, tf; 
        double seconds; 
        vec& A; 
    public: 
        Sorter(vec& A_) : A(A_) {}
        virtual void sort() = 0; 
        virtual void printTime()
        {
            std::cout << "\n=== Total time " << sorterName << " (seconds): " << seconds << " ===\n" << std::endl; 
        } 
}; 

class InsertionSort : public Sorter
{
    private: 
        void insertion_sort()
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

    public: 
        InsertionSort(vec& A_) : Sorter(A_) {sorterName = "INSERTION SORT";}
        
        virtual void sort()
        {
            t0 = clock(); 
            insertion_sort(); 
            tf = clock() - t0; 
            seconds = ((double)tf) / CLOCKS_PER_SEC;
        }
}; 

class MergeSort : public Sorter
{   
    private:
        void merge(int p, int q, int r)
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

        void merge_sort(int p, int r)
        {
            if(p < r)
            {
                int q = p + (r - p) / 2; 
                merge_sort(p, q); 
                merge_sort(q+1, r); 
                merge(p, q, r); 
            }
        }

    public: 
        MergeSort(vec& A_) : Sorter(A_) {sorterName = "MERGE SORT";}
        
        virtual void sort() override
        {
            clock_t t0 = clock(); 
            merge_sort(0, A.size()-1); 
            clock_t tf = clock() - t0; 
            seconds = ((double)tf) / CLOCKS_PER_SEC;
        }
};

class HeapSort : public Sorter
{
    private: 
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

    public: 
        HeapSort(vec& A_) : Sorter(A_)
        {
            heap_size = A_.size();
            sorterName = "HEAP SORT";
        }
        virtual void sort() override
        {
            clock_t t0 = clock(); 
            heap_sort(); 
            clock_t tf = clock() - t0; 
            seconds = ((double)tf) / CLOCKS_PER_SEC;
        }
};

class QuickSort : public Sorter
{   
    private: 
        int partition(int p, int r)
        {
            int pivot = A[r]; 
            int i = p-1; 
            for(int j = p; j < r; ++j)
            {
                if(A[j] <= pivot)
                {
                    ++i; 
                    swap(A[i], A[j]); 
                }
            }
            swap(A[i+1], A[r]); 
            return i+1; 
        }
        void quick_sort(int p, int r)
        {
            if(p < r)
            {
                int q = partition(p, r); 
                quick_sort(p, q-1); 
                quick_sort(q+1, r); 
            }
        }
    public: 
        QuickSort(vec& A_) : Sorter(A_) {sorterName = "QUICK SORT";}
        virtual void sort() override
        {
            clock_t t0 = clock(); 
            quick_sort(0, A.size()-1); 
            clock_t tf = clock() - t0; 
            seconds = ((double)tf) / CLOCKS_PER_SEC;
        }
};