#include <iostream>
#include <algorithm>

using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item{
    int value, time, jobNum;
 
    // Constructor
    Item(int value, int time, int jobNum){
       this->value = value;
       this->time = time;
       this->jobNum = jobNum;
    }
};
 
// Comparison function to sort Item according to val/weight
// ratio
bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.value / (double)a.time;
    double r2 = (double)b.value / (double)b.time;
    return r1 > r2;
}

// Main greedy function to solve problem
void fractionalKnapsack(int W, struct Item arr[], int n){
    //    sorting Item on basis of ratio
    sort(arr, arr + n, cmp);

    int currentWeight = 0; // Current weight in knapsack
    double finalvalue = 0.0; // Result (value in Knapsack)
 
    // Looping through all Items
    for (int i = 0; i < n; i++) {
        // If adding Item won't overflow, add it completely
        if (currentWeight + arr[i].time <= W) {
            currentWeight += arr[i].time;
            finalvalue += arr[i].value;
        }
 
        // If we can't add current Item, add fractional part
        // of it
        else{
            int remaining = W - currentWeight;
            finalvalue += arr[i].value * ((double)remaining / (double)arr[i].time);
            break;
        }
    }

    //    The new order of Items with their
    //    ratio
    
    for (int i = 0; i < n; i++){
        cout << "Job Number: " << arr[i].jobNum << " Value: " << arr[i].value << " Time: " << arr[i].time << " -> " << "V/T: " << ((double)arr[i].value / arr[i].time) << endl;
    }
 
    cout << "Optimal Value: " << finalvalue << endl;

    return;
}
 
// Driver code
int main(){
    int W = 10; // Weight of knapsack
    
    // Array of V, T, Job Number
    Item arr[] = {  {3, 2, 1}, 
                    {4, 3, 2}, 
                    {7, 4, 3}, 
                    {5, 3, 4}, 
                    {2, 1, 5}, 
                    {3, 3, 6}, 
                    {5, 3, 7}, 
                    {8, 5, 8}, 
                    {9, 6, 9}, 
                    {6, 4, 10}};
    
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    fractionalKnapsack(W, arr, n);

    return 0;
}