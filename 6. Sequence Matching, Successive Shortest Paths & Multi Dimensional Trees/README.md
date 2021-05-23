### <ins>Problem: Fractional Knapsack</ins>
Assume you have a scheduling problem with 10 customers. Customer i has value Vi, and requires processing time Ti. The values of Vi and Ti are listed below as arrays:

    V = {3,4,7,5,2,3,5,8,9,6}
    T = {2,3,4,3,1,3,3,5,6,4}

Assume that jobs can be scheduled partially, so that a job of value *Vi* which requires time *Ti* will receive value _(Vi*t)/Ti_ if processed only for time *T*.

Find the maximum value which can be scheduled with total processing time 10 units.

To make, call *make all*. To run, call *./fractionalKnapsack >> fractionalKnapsack.out*.

### <ins>Problem: Integer Knapsack</ins>
Assume you have a scheduling problem with 10 customers. Customer i has value Vi, and requires processing time Ti. The values of Vi and Ti are listed below as arrays:

    V = {3,4,7,5,2,3,5,8,9,6}
    T = {2,3,4,3,1,3,3,5,6,4}

Assume that jobs must be scheduled fully, with no partial credit.

Use dynamic programming to find the optimal value which can be scheduled in a total of 9, 10, 11, 12 time units.

To make, call *make all*. To run, call *./integerKnapsack >> integerKnapsack.out*.
