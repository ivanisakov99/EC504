#ifndef KMP_H_
#define KMP_H_

// Fills lps[] for given patttern pat[0..M-1] 
void computePiArray(string pat, int M, int* pi) 
{ 
    int k = 0, j = 1;
    pi[0] = 0;

    while (j < M){
        if(pat[k] == pat[j]){
            k++;
            pi[j] = k;
            j++;
        }
        else if(k == 0){    //First character did not match
            pi[j] = 0;
            j++;
        }
        else{   //Mismatch after the first character
            k = pi[k - 1];
        }
    }
    
}   
// Prints occurrences of txt[] in pat[] 
void KMPSearch(string pat, string txt) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
  
    int pi[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computePiArray(pat, M, pi); 
  
    int k = 0, j = 0;

    while(j < N){
        if(pat[k] == txt[j]){
            k++;
            j++;
        }
        if(k == M){
            cout << "Match at " << j - k << endl;
            k = pi[k - 1];
        }
        else if(j < N && pat[k] != txt[j]){ //Mismatch
            if(k != 0){
                k = pi[k - 1];
            }
            else{
                j++;
            }
        }
    }
} 
  

#endif
