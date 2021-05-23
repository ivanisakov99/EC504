// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <iostream>
#include "KMP.h"

using namespace std;
  
// Driver program to test above function 
int main(){ 
    string txt = "AAACAAAAACAAACAAAAAC"; 
    string pat = "AAA"; 
    KMPSearch(pat, txt); 
    return 0; 
} 