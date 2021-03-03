### <ins>Problem 1:</ins>
In this exercise, you are to implement four sorting algorithms to sort arrays of integers and compare them on two sorting inputs. The sorting algorithms
to be implemented are:

• Insertion Sort
• Merge Sort
• Merge Sort Blend, where, when in the recursion you find you have 32 or less items to sort, you do insertion sort and don’t recur further.
• A simple version of Timsort, to be described below.

All of the sorting routines are to be implemented in the header file sorting.h, which is enclosed as part
of the HW. The main file can be used for debugging, but should not be changed.

The codes will sort two lists of integers. The first list is randomly generated in the main program. The second list is read from file. You cannot change
the original sortScaling.cpp file, but you can write your own main program for debugging with smaller list lengths if you wish. Once you have completed this,
you can make the executable using make all . You can then run ./sort >> sort.out . Turn in your sorting.h file and the sort.out file in HW1 folder in
your /projectnb/ec504/ directory.

Now, here is a brief description of simpleTimsort:

    Set minrunsize to 32. Initialize runstack as array, with runstack[0] = 0, and num_in_stack = 0;
    input array a[], with n elements
    for i in 0 to n-1,
      find a run of nondecreasing entries in i.
      If run length is less than minrunsize, insert element of a[i] into the run and continue;
      If run length is greater than or equal to minrunsize, increment num_in_stack, store the index of t
      current value of i) into runstack[num_in_stack].
    if i gets to n-1, increment num_in_stack and set runstack[num_in_stack] to n.
    
    Now, collapse the stack of runs as follows: While num_in_stack > 1, do
    Merge the last two runs (starting at runstack[num_in_stack-2] and runstack[num_in_stack - 1]);
    decrement num_in_stack by 1 and set runstack[num_in_stack] = n;
    
This last step is inefficient, and does not merge in the same clever way Timsort does, maintaining an invariant. This will be easier to implement, and even
with the inefficiencies, will show how Timsort works when the data is nearly sorted.

**Extra credit**: Implement a better simpleTimsort by managing the stack dynamically as follows: Whenever you insert a run into the stack, if its length
is greater than or equal to the run below in the stack, merge it right away. Continue this merging recursively into the stack before starting the next run.
Hence, if we have a stack with runs of length 128, 64, 32 and you insert a run of length 32 on top, you first merge it with the top of 32, yielding a
size 64 run. Then, you merge that with the 64, yielding a 128 run, which you merge with the 128 run, leaving a single run of length 256 in the stack.
This algorithm will be faster than both versions of mergesort on random data.
