# API-Code-Tester
Implementation of the algorithms studied during the Data Structures and Algorithms course at Politecnico di Milano

# Implementations: 
- Sorting algorithms in folder `Sorting`:
  - Insertion Sort implementation
  - Merge Sort implementation
  - Heap Sort implementation

# Compilation and Execution
Firstly, go to the folder of the topic you want to cover (e.g: Sorting). 
Then write this commands on the command prompt (terminal): 
```bash
  mkdir build
  cd build
  cmake ..
  make
  ./executable
```

The `executable` depends on the topic: 
- If you are in the folder "Sorting" ==> ./sort <n1> <n2> 
  `<n1>` and `<n2>` are, respectively, the wanted sorting algorithm and the size of the array A to be sorted. 
  The available sorters are: 
  - 0 -> Insertion Sort  |  $T(n) = \Theta{n^2}$ 
  - 1 -> Merge Sort      |  $T(n) = \Theta{nlog(n)}$
  - 2 -> Heap Sort       |  $T(n) = \Theta{nlog(n)}$
  - 3 -> Quick Sort      |  $T(n) = \Theta{nlog(n)}$ (Avarage Case)







