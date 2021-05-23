#include <chrono>
#include <iostream>
#include <fstream>
#include "myHeap.h"

using namespace std;

typedef struct heapItem{
	int key;
	double data;
	int position;
}hItem;

int myrand(int iseed){
	int wrap = 131071;
	int factor = 23;
	return (factor*iseed)%wrap;
}

int main() {
	Heap<hItem> *thisHeap;
	int i;
	thisHeap = new Heap<hItem>;

	hItem Elements[1000];
	hItem *temp;
	int newkey;
	int iseed=3571;
	
	for(i = 0; i < 1000; i++){
		iseed = myrand(iseed);
		Elements[i].key = iseed;  
		iseed = myrand(iseed);
		Elements[i].data = ((double) iseed)/10000.0;
		thisHeap->insert(&Elements[i]);
	}

	for (int j = 0; j < 10; j++){
		temp = thisHeap->remove_min();
		cout << temp->key<<";" ;
	}
	cout << endl;
	for (int j = 0; j < 100; j++){
		newkey = Elements[j].key/37;
		if (Elements[j].position < 0){			
			continue;
		}
		thisHeap->decreaseKey(Elements[j].position, newkey);
	}
	for (int j = 0; j < 10; j++){
		temp = thisHeap->remove_min();
		cout << temp->key<<";" ;
	}
	cout << endl;
	return 0;
}
