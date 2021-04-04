#include <iostream>
#include <algorithm>

using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
void knapSack1(int W, int wt[], int val[], int n){
    int i, w;
    int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if (i == 0 || w == 0){
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w){
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else{
                K[i][w] = K[i - 1][w];
            }
        }
    }

    cout << "Scheduling in a total of " << W << " time units" << endl;
    for(int j = 0; j <= n; j++){
        for(int k = 0; k <= W; k++){
            cout << K[j][k] << " ";
        }
        cout << endl;
    }

    cout << "Optimal value: " << K[n][W] << endl;
}

// Returns the value of maximum profit
int knapSackRec(int W, int wt[], int val[], int i, int** dp){
    // base condition
    if (i < 0){
        return 0;
    }
    
    if (dp[i][W] != -1){
        return dp[i][W];
    }
 
    if (wt[i] > W){
 
        // Store the value of function call
        // stack in table before return
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
        return dp[i][W];
    }
    else{
        // Store value in a table before return
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp), knapSackRec(W, wt, val, i - 1, dp));
 
        // Return value of table after storing
        return dp[i][W];
    }
}
 
int knapSack2(int W, int wt[], int val[], int n){
    // double pointer to declare the table dynamically
    int** dp, optimal;
    dp = new int*[n];
 
    // loop to create the table dynamically
    for (int i = 0; i < n; i++){
        dp[i] = new int[W + 1];
    }
 
    // loop to initially filled the
    // table with -1
    for (int i = 0; i < n; i++){
        for (int j = 0; j < W + 1; j++){
            dp[i][j] = -1;
        }
    }

    optimal = knapSackRec(W, wt, val, n - 1, dp);

    cout << "Scheduling in a total of " << W << " time units" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < W + 1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++){
        delete dp[i];
    }
    delete dp;

    cout << "Optimal value: " << optimal << endl;

    return optimal;
}
 
// Driver Code
int main(){
    // int val[] = {1, 6, 18, 22, 28};
    // int wt[] = {1, 2, 5, 6, 7};

    int val[] = {3, 4, 7, 5, 2, 3, 5, 8, 9, 6};
    int wt[] = {2, 3, 4, 3, 1, 3, 3, 5, 6, 4};
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Method 1: DP" << endl;
    for(int k = 9; k < 13; k++){
        knapSack1(k, wt, val, n);
        cout << endl;
    }

    cout << "Method 2: Memoisation" << endl;
    for(int k = 9; k < 13; k++){
        knapSack2(k, wt, val, n);
        cout << endl;
    }
    return 0;
}