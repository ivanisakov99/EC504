#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

using namespace std;

const int MAX_SIZE = 100000; //the maximum amount of elements our heap should have.

template <typename Object>
class Heap{
public:
   Heap(){
      elements = 0;
   };

   void insert(Object* item){// Add the object pointer item to the heap
	   if(elements >= MAX_SIZE){
		   cout << "Heap is full; can't insert "<< endl;
			return;
	   }
      else{
         elements++; // Increment the number of elements
         int i = elements - 1;   // Index of the new element in the array
         
         array[i] = item;  // Place the object in the array
         array[i]->position = i; // Record the position
         
         upHeap(array[i]->position);   // Correct any inconsistencies with the properites
      }
   };  	
   
   Object* remove_min(){
      if(elements == 0){
		   cout << "empty heap error, can't delete"<<endl;
	   }
      Object* temp = array[0];   // Copy the min object to return
      temp->position = -1; // Set the position to -1

      array[0] = array[elements - 1];  // Place the last/largest object into the position of min
      array[0]->position = 0; //Correct its position

      elements--; // Decrement the number of elements

      downHeap(array[0]->position); // Restore the property

      return temp;
   };       // Remove the smallest element in the heap & restructure heap
   
   void decreaseKey(int pos, int val){ // Decreases Key in pos to val
      array[pos]->key = val;  // Change the value of the key
      upHeap(array[pos]->position); // Restore the property
   }; 
   
   bool IsEmpty() const {  return (elements <= 0);};
   
   bool IsFull() const {return (elements >=MAX_SIZE );};
   
   int count() const {return elements;};
   
   Object* value(int pos) const{ //return a pointer to an object in heap position
	   if(pos >= elements){
		   cout << "Out of range of heap " << pos << "elements " << elements << endl;
	   }
      return (array[pos]);
   };  
   
   protected:
   Object* array[MAX_SIZE];
   int elements;       //  how many elements are in the heap
   
   private:
   void downHeap(int pos){// starting with element in position pos, sift it down the heap 
                       // until it is in final min-heap position
      Object* item = array[pos];
      int j = 2*pos + 1;   //Left child

      while(j <= elements){
         if(j < elements - 1 && array[j]->key > array[j + 1]->key){  // If the left child is larger than the right one
            j++;
         }

         if(array[pos]->key > array[j]->key){   // Swap the elements
            array[pos] = array[j];
            array[pos]->position = pos;

            array[j] = item;
            array[j]->position = j;
            pos = j;
            j = 2*pos + 1;   //Left child
         }
         else{
            break;
         }
      }
      //array[j] = item;
      //array[j]->position = pos;

   }; 

   void upHeap(int new_pos){// starting with element in position int, sift it up the heap
                       // until it is in final min-heap position
      Object* item = array[new_pos];
      
      if(new_pos == 0){ // Root
         return;
      }
      if(array[new_pos]->key < array[(new_pos - 1)/2]->key){   // If the element is smaller than its parent
         Object* temp;
         temp = array[(new_pos - 1)/2];

         temp->position = new_pos;
         item->position = (new_pos - 1)/2;

         array[(new_pos - 1)/2] = item;
         array[new_pos] = temp;

         new_pos = (new_pos - 1)/2;

         upHeap(new_pos); 
      }
      else{
         return;
      }
   };   
};
#endif
