#include <iostream>
#include <chrono>
#include "Chess_Board.h"

using namespace std;

int main(void){
    int i,Size;
    bool found;
    /* Timing and IO setup */
    chrono::time_point<chrono::steady_clock> start, stop; 
    chrono::duration<double> difference_in_time;
    double delta_time; // Holds the final run time 
   

    for(Size = 8; Size < 32; Size++){
	    Chess_Board *CB = new Chess_Board(Size);

	    start = chrono::steady_clock::now();    
   		CB->Solve();
        stop = chrono::steady_clock::now(); 
		difference_in_time = stop - start;
        delta_time = double(difference_in_time.count()); 
		cout << "Found solution for " << Size << " in " << delta_time << "seconds" << endl;
		cout << *CB << endl;
        cout << endl;
		delete CB;
    }

    cout << "\n" << "Size = " << Size << endl;
}
