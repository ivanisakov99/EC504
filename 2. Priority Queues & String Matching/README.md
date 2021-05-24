# <ins> Priority Queues & String Matching</ins>
### <ins>Problem 1: Min-Heap Binary Priority Queue</ins>
In this exercise, you are to implement an unusual min-heap binary priority queue. As mentioned in class, the standard class implementations of heaps often fall short of what is needed for algorithms, and are slow. The main program, *main.cpp*, creates an array of records called heapItems, with keys. Each record also holds an index field, *position*, that points to its current in the heap array.

The heap elements will be pointers to these records. This means that there will be a lot less copying of data when heap elements are swapped. It also allows one to update the position field from within the heap class using the pointer. What it also means is that you can’t simply go copy a heap implementation for integers on the web and expect it to work. You don’t want to organise the heap by the value of the pointers; you want to organise it by the key values of the records. From the heap class, you can access this as *array[k]->key*, using the pointer stored in the heap array to get the key value. Similarly, you access the position information as *array[k]->position*. As you do heap operations that move pointers in the heap, you need to make sure you update the position of records in the heap. When a record is removed from the heap, set its position to -1.

Included in the files is an include file, *myHeap.h*, and a makefile. You need to fill out all the missing functions in *myHeap.h*. To make an executable, type make *heapmoves*. Run the executable file, *heapmoves*, using the command 
*./heapmoves >> heap.out*


### <ins>Problem 2: KMP</ins>
The purpose of this exercise is to implement the Knuth-Morris-Platt (KMP) string matching algorithm. Pseudocode for this algorithm is provided in our class slides. You will get an input of two strings: a pattern string and a text string. You are to find the locations of all positions where the pattern matches the string. Enclosed is a trivial main program, *KMP.cpp*, and a header file *KMP.h* that is missing two functions for you to complete: *computePiArray* needs to compute the prefix function 
π(·) for the pattern string, and *KMPSearch.cpp*, which uses this pattern to find the matches using the KMP algorithm.

To make, call make KMP . To run, call ./KMP . Use the provided main program to debug. Feel free to edit the pattern and text to make sure your program works.
