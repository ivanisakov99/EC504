#ifndef SHORTPATH_H_
#define SHORTPATH_H_

#include <queue>
#include "myHeap.full.h"  // This is my version of HW 2.  You can include your own binary heap
//#include "myHeap.h"

#define LARGE1 9999999

using namespace std;


struct arc{
  struct arc *next;
  int length;
  int end;
  };

typedef struct node{
   struct arc *first; /* first arc in linked list */
   int id;  // The number of the vertex in this node 
   int key;  /* Distance estimate, named key to reuse heap code*/
   int P;  /* Predecessor node in shortest path */
   int position;  /* Position of node in heap, from 0 to Nm, where 0 is best */
   } nodeitem;

void BellmanFord(nodeitem N[], int Or, int Nm)
{
   // You program this, a  Bellman Ford algorithm that uses a work queue.  DO NOT implement this as 3 for loops. 
   // That can be very slow, and waste many iterations. 

    int v, dv, u;
    struct arc *edge;

    queue<int> Q;
    Q.push(Or);
    N[Or].key = 0;
    N[Or].position = 1;

    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        N[u].position = -1;

        edge = N[u].first;
        while(edge != NULL){
            v = edge->end;
            dv = N[u].key + edge->length;

            if(N[v].key > dv){
                N[v].key = dv;
                N[v].P = u;

                if(N[v].position != 1){
                    Q.push(v);
                    N[v].position = 1;
                }
            }
            edge = edge->next;
        }

    }

}/* end Bellman-Ford */
/* ---------------*/


void Dijkstra(nodeitem N[], int Or, int Nm)
{
    int Mark[Nm+1];
    struct arc *edge;
    int v, dv, min_d, min_v, finished;
    for (int i=1; i<=Nm; i++){
        Mark[i]=-1;
    }
    N[Or].key = 0;
    Mark[Or] = 1;
    finished = 1;
    min_v = Or;
    min_d = 0;
    while (finished < Nm){
        edge = N[min_v].first;  //update distances
        while (edge != NULL){ // explore the outgoing arcs of u 
            v = edge->end;
            dv = min_d + edge->length;
            if (N[v].key > dv){
                N[v].key = dv;
                N[v].P = min_v;
            }//if D > dv 
            edge = edge->next;
        }// while edge           
        
        min_d = LARGE1;
        for (int j = 0; j <= Nm; j++){
            if (Mark[j] < 1){
                if (N[j].key < min_d){
                    min_d = N[j].key;
                    min_v = j;
                }
            }
        } 
        Mark[min_v]=1;
        finished++;
    } 
} /* end Dijkstra */


void DijkstraHeap(nodeitem N[], int Or, int Nm)
{
    Heap<nodeitem> *thisHeap;
    struct arc *edge;
    nodeitem *node;
   
    // You write a Dijkstra algorithm using a binary heap; you can reuse the one from HW 2 with minor variations

    thisHeap = new Heap<nodeitem>;
    int v, dv;
    N[Or].key = 0;
   
    for(int i = 1; i <= Nm; i++){
        thisHeap->insert(&N[i]);
    }
   
    while(!thisHeap->IsEmpty()){
        node = thisHeap->remove_min();
        edge = node->first;
        while(edge != NULL){
            v = edge->end;
            dv = node->key + edge->length;
            
            if(N[v].key > dv){
                N[v].key = dv;
                N[v].P = node->id;

                thisHeap->decreaseKey(N[v].position, dv);
            }
            edge = edge->next;
        }
    }
} /* end DijkstraHeap */ 
#endif
