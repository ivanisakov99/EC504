#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

using namespace std;

static int swapCount = 0;

void swap(int* a, int* b)
{
    //swapCount++;
    int temp;
    temp = *a; 
    *a = *b; 
    *b = temp; 
}


/* See Knuth's shuffles https://en.wikipedia.org/wiki/Random_permutation */



void insertionsort(int a[],  int n){
  int i, key, j;  
  for (i = 1; i < n; i++){  
    key = a[i];  
    j = i - 1;  
    
    while (j >= 0 && a[j] > key) {  
      a[j + 1] = a[j];  
      j = j - 1;  
    }  
    a[j + 1] = key;  
  }  
}

// Order Theta(NlogN) sorting
void mergeSort(int a[], int a_tmp[], int l, int r)
{
  // a_tmp can be used for merging 
  int i, j, k;
  if(r > l){
    int m = (l + r)/2;

    mergeSort(a, a_tmp, l, m);
    mergeSort(a, a_tmp, m + 1, r);

    for(i = m + 1; i > l; i--){
      a_tmp[i - 1] = a[i - 1];
    }
    for(j = m; j < r; j++){
      a_tmp[r + m - j] = a[j + 1];
    }
    for(k = l; k <= r; k++){
      a[k] = (a_tmp[i] < a_tmp[j]) ? a_tmp[i++] : a_tmp[j--];
    }
  }
    
}
// 
void mergeSortblend(int a[], int a_tmp[], int l, int r)
{
  int i, j, k;
  if(r <= l){
    return;
  }

 if(r - l > 32){
  int m = (l + r)/2;
  mergeSortblend(a, a_tmp, l, m);
  mergeSortblend(a, a_tmp, m + 1, r);

    for(i = m + 1; i > l; i--){
      a_tmp[i - 1] = a[i - 1];
    }
    for(j = m; j < r; j++){
      a_tmp[r + m - j] = a[j + 1];
    }
    for(k = l; k <= r; k++){
      a[k] = (a_tmp[i] < a_tmp[j]) ? a_tmp[i++] : a_tmp[j--];
    }
 }
 else{
   for(i = l + 1; i <= r; i++){
      k = a[i];
      j = i - 1;

      while(j >= l && a[j] > k){
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = k;
   }
 }

}

bool checkInorder(int a[],int left, int right){
  //checks that a is in order from left to right
  int tmp;
  for (int i = left; i < right; i++){
    if (a[i] > a[i+1]){
      tmp = i;
      
    }
  }

  return true;
}

void simpleTimsort(int a[], int a_tmp[], int n)
{ 
  const int RUN = 32;
  int runstack[n/32], num_in_stack = 0;
  runstack[num_in_stack] = 0;
  int i, j, z, key, l, m, r;
  int secondLast, Last;

  for(z = 1; z < n; z++){
    if(a[z] > a[z - 1]){
      continue;
    }
    else{
      //If the size of the run is less than minrun
      if( (z - runstack[num_in_stack]) < RUN){
        //Insertion
        key = a[z];
        j = z - 1;

        while (j >= runstack[num_in_stack] && a[j] > key) {  
          a[j + 1] = a[j];  
          j = j - 1;  
        }  

        a[j + 1] = key;  
        
        continue;
      }
      //If the run is greater or equal to minrun
      else if((z - runstack[num_in_stack]) >= RUN){
        num_in_stack++;
        runstack[num_in_stack] = z;
        
        secondLast = runstack[num_in_stack - 1] - runstack[num_in_stack - 2];
        Last = runstack[num_in_stack] - runstack[num_in_stack - 1];
        
        while(secondLast <= Last && num_in_stack > 1){
          //Merge
          l = runstack[num_in_stack - 2];
          m = runstack[num_in_stack - 1];
          r = z;

          for(i = m - 1; i >= l; i--){
            a_tmp[i] = a[i];
          }

          i = l;
          j = m;

          for(key = l; key < r; key++){
            if(i < m && j < r){
              if(a_tmp[i] < a[j]){
                a[key] = a_tmp[i++];
              }
              else{
                a[key] = a[j++];
              }
            }
            else{
              if(j >= r ){
                a[key] = a_tmp[i++];
              }
              else if(i >= m){
                break;
              }
            }
      
          }

          num_in_stack--;
          runstack[num_in_stack] = z;

          secondLast = runstack[num_in_stack - 1] - runstack[num_in_stack - 2];
          Last = runstack[num_in_stack] - runstack[num_in_stack - 1];
        }
        
      }
    } 
    
  }

  num_in_stack++;
  runstack[num_in_stack] = n;

  while(num_in_stack > 1){
    //Merge
    l = runstack[num_in_stack - 2];
    m = runstack[num_in_stack - 1];
    r = n;
    
    for(i = m - 1; i >= l; i--){
      a_tmp[i] = a[i];
    }
    
    i = l;
    j = m;
    
    for(key = l; key < r; key++){
      if(i < m && j < r){
        if(a_tmp[i] < a[j]){
          a[key] = a_tmp[i++];
        }
        else{
          a[key] = a[j++];
        }
      }
      else{
        if(j >= r ){
          a[key] = a_tmp[i++];
        }
        else if(i >= m){
          break;
        }
      }
      
    }
    
    num_in_stack--;
    runstack[num_in_stack] = n;
  }
}// end function

#endif 
