#include <iostream>
#include <fstream>
#include <chrono>
#include <queue>
using namespace std;

/***********************************************************
Given two arrays: FirstVertex pointing to the EdgeList with destination 
node for an undirected graph G(V,E). 

The input file begins with number of vertices (V = |V|)
and number of edges (E =|E|) and the list of value for 

int FirstVertex[V+1]
int EdgeList[E+1]

The vertices(nodes) are numbered 0,..,|V| -1.  The last entry 
FirstVertex[V] = E pointing to  EdgeList[E] = -1;
represented as a null

You are to compute the number of the connected components.

************************************************************/


int find_connected_components_BFS(int *FirstVertex, int V, int *EdgeList,int E, int *Component);
int find_connected_components_DFS(int *FirstVertex, int V, int *EdgeList,int E, int *Component);
void DFS(int v, int *FirstVertex, int V, int *EdgeList,int E, int *Component,int NCC);
void PrintAdjacencyListFormat(int *FirstVertex, int V, int *EdgeList,int E);
// void BFS(Queue * Q,, int *Found, int *FirstVertex, int V, int *EdgeList,int E);

int main(int argc, char *argv[]){
  chrono::time_point<chrono::steady_clock> start, stop; 
  chrono::duration<double> difference_in_time;
  double difference_in_seconds_BFS; // Holds the final run time for BFS
  
  ifstream infile1;
  int V;
  int E;
  int NumberCC_BFS;
  //string filename = "graph_100_190.txt";
  
  infile1.open(argv[1]);
  //infile1.open(filename);
  if(!infile1){
    cout << "Error opening file " <<endl;
    return -1;
  } 
  
     infile1 >> V;
     infile1 >> E;
    
    int *Component = new int[V];
    fill_n(Component, V, -1);


    int *FirstVertex = new int[V+1];
    for(int i=0; i< V+1 ; i++) 
      infile1 >> FirstVertex[i];  //  Note: FirstVertex[V] = E  fake extra link
    
    int *EdgeList = new int[E+1];
    for(int i=0; i< E +1 ; i++)
      infile1 >> EdgeList[i];   // Note  EdgeList[E] = -1;  is null flag
    
    infile1.close();

     cout << endl << "A print in Adjacency  List form to help with Debugging! " << endl;
     PrintAdjacencyListFormat(FirstVertex, V, EdgeList, E);
    
    /* Find NumberCC_BFS   */
    start = chrono::steady_clock::now();
    NumberCC_BFS= find_connected_components_BFS(FirstVertex, V, EdgeList,E,Component);
    stop = chrono::steady_clock::now();
    difference_in_time = stop - start;
    difference_in_seconds_BFS = double(difference_in_time.count());

    //Begin output file : DO NOT CHANGE
    ofstream outfile(strcat(argv[1],"_out"));
    outfile << difference_in_seconds_BFS << endl;
    outfile << NumberCC_BFS << endl;
    outfile << "BFS Components: " << endl;
    for (int kk = 0; kk <  V; kk+= 10){
        for (int jj = 0; jj < 10; jj++)
            if (kk + jj < V)
                outfile << Component[kk+jj]<< "\t";
        outfile << endl;
    }

//  Now do DFS connected components

    start = chrono::steady_clock::now();
    NumberCC_BFS = find_connected_components_DFS(FirstVertex, V,EdgeList,E,Component);
    stop = chrono::steady_clock::now();
    difference_in_time = stop - start;
    difference_in_seconds_BFS = double(difference_in_time.count());

    outfile << difference_in_seconds_BFS << endl;
    outfile << "DFS Components: " << endl;
    for (int kk = 0; kk <  V; kk+= 10){
        for (int jj = 0; jj < 10; jj++)
            if (kk + jj < V)
                outfile << Component[kk+jj]<< "\t";
        outfile << endl;
    }
     
    delete[] FirstVertex;
    delete[] EdgeList;
    delete[] Component;
    return 0;
}

int find_connected_components_BFS(int *FirstVertex, int V, int *EdgeList,int E, int *Component)
{  
    int NCC_BFS  = 0;
    int current = -1;
    fill_n(Component, V, -1);
    queue<int> Q; // standard template library queue

    for (int kk = 0; kk < V; kk++){
        
        if (Component[kk] < 0){
            NCC_BFS++;

            // Implementing BFS starting from vertex kk.  Mark every vertex v you find with 
            // Component[v]= NCC_BFS, the component number.

          Component[kk] = NCC_BFS;
          Q.push(kk);

          while(!Q.empty()){
            current = Q.front();
            
            for(int i = FirstVertex[current]; i <= FirstVertex[current + 1] - 1; i++){
              if(Component[EdgeList[i]] < 0){
                Component[EdgeList[i]] = NCC_BFS;
                Q.push(EdgeList[i]);
              }
            }

            Q.pop();
          }
        }
    }
    
    return NCC_BFS;
}
void DFS(int v, int *FirstVertex, int V, int *EdgeList,int E, int *Component,int NCC){
    //
    // Mark v with the number of the component. Then find an unmarked 
    // neighbor of v and recursively do DFS on the neighbor
    
    if(Component[v] < 0){
      int current;
      Component[v] = NCC;
      
      for (int i = FirstVertex[v]; i <= FirstVertex[v + 1] - 1; i++){
        current = EdgeList[i];

        if(Component[current] < 0){
          DFS(current, FirstVertex, V, EdgeList, E, Component, NCC);
        }
      }
    }
  

}


int find_connected_components_DFS(int *FirstVertex, int V, int *EdgeList,int E, int *Component)
{  
    int NCC_DFS  = 0;
    int current = -1;
    fill_n(Component, V, -1);
    for (int kk = 0; kk < V; kk++){
        if (Component[kk] < 0){
            NCC_DFS++;
            DFS(kk,FirstVertex,V,EdgeList,E,Component,NCC_DFS);
        }
    }
    
    return NCC_DFS;
}

void PrintAdjacencyListFormat(int *FirstVertex, int V, int *EdgeList,int E){
    int v;
    int e;
    cout << "V = " << V << "  E = " <<E <<endl;
    for( v = 0; v < V; v++)
      {
	cout << endl;
	cout << v  << ": ";
	
	for(e = FirstVertex[v]; e < FirstVertex[v+1]; e++) 
	  cout << EdgeList[e]<< "-> ";

	cout <<"nil";
      }

    cout << endl;
    cout << v  << " : ";
    cout << EdgeList[e]  << " That's Edge List  nil  Folks " << endl;
 
  }
