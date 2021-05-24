#include<iostream>
#include <fstream>
#include <cstdlib> 
#include <chrono>
#include <math.h>
#include "sorting.h"
using namespace std;

#define Debug 0

// Debugging routine: (should be in separate test.cpp)
void printArray(int a[], int N){ 
     cout << N << "\n";
     for(int i = 0;i<N;i++){
          cout << a[i] << "\n";
     }
}

int main(){
     // int N = 1048576; //a power of 2
     int N = 131072; //a power of 2

     int a[N];
     int a_save[N];
     int a_tmp[N];
     string filename("input.txt");
     ifstream in1;

     /* Timing and IO setup */
     chrono::time_point<chrono::steady_clock> start, stop; 
     chrono::duration<double> difference_in_time;
     double delta_time; // Holds the final run time 


     srand(137); // fixes intial seed 
     // Choose a random list of N integers.
     for(int i = 0; i < N; i++){
          a[i] = (rand() + 1)%1000000;
     }
     for(int i = 0; i < N; i++){
          a_save[i] = a[i]; // keep random array
     }
     for(int kk = 0; kk < 2; kk++){
          if(kk == 1){// read from file
               in1.open(filename);   
               if(!in1){	// did not open the file
	               cout << "Sorry, bad file."<<endl;
	               exit(0);	
               } 
               in1 >> N;
               for(int i = 0; i < N; i++){
                    in1 >> a[i];
               }
               in1.close();
               for(int i = 0; i < N; i++){
                    a_save[i] = a[i]; // keep random array
               }
          }
          // Insertion sort 
          start = chrono::steady_clock::now();    
          insertionsort(a, N);
          stop = chrono::steady_clock::now(); 
          difference_in_time = stop - start;
          delta_time = double(difference_in_time.count()); 
          cout << "Insertion sort time 1: " << delta_time << endl;
          for(int i = 0; i < N; i++){
               if(i%10000 == 0){
                    cout << a[i] << endl;
               }
          } 
  
          // Test mergeSort
          for(int i = 0; i < N; i++){
               a[i] = a_save[i];
          }
          start = chrono::steady_clock::now();
          mergeSort(a, a_tmp, 0, N - 1);
          stop = chrono::steady_clock::now(); 
          difference_in_time = stop - start;
          delta_time = double(difference_in_time.count()); 
          cout << "Merge sort time 1: " << delta_time << endl;
          for(int i = 0; i < N; i++){
               if(i%10000 == 0){
                    cout << a[i] << endl;
               }
          }
          
          // Test mergeSortblend
          for(int i = 0; i < N; i++){
               a[i] = a_save[i];
          }
          start = chrono::steady_clock::now();
          mergeSortblend(a, a_tmp, 0, N - 1);
          stop = chrono::steady_clock::now(); 
          difference_in_time = stop - start;
          delta_time = double(difference_in_time.count()); 
          cout << "Merge sort blendtime 1: " << delta_time << endl;
          for(int i = 0; i < N; i++){
               if(i%10000 == 0){
                    cout << a[i] << endl;
               }
          }
  
          //Test simpleTimsort
          for(int i = 0; i < N; i++){
               a[i] = a_save[i];
          }
          start = chrono::steady_clock::now();
          simpleTimsort(a, a_tmp, N);
          stop = chrono::steady_clock::now(); 
          difference_in_time = stop - start;
          delta_time = double(difference_in_time.count());   
          cout << "Simple timsort time 1: " << delta_time << endl;
          for(int i = 0; i < N; i++){
               if(i%10000 == 0){
                    cout << a[i] << endl;
               }
          }
     }
     return 0;
}
