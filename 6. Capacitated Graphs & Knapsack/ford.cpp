#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
 
// Number of vertices in given graph
#define V 11

                    //1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
int graph[V][V]= {  { 0, 4, 5, 6, 0, 0, 0, 0, 0, 0,  0}, // 1
                    { 0, 0, 2, 0, 2, 0, 0, 0, 0, 0,  0}, // 2
                    { 0, 0, 0, 2, 0, 3, 0, 0, 0, 0,  0}, // 3
                    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,  0}, // 4
                    { 0, 0, 0, 0, 0, 3, 0, 2, 0, 0,  0}, // 5
                    { 0, 0, 0, 0, 0, 0, 0, 0, 3, 0,  0}, // 6
                    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 2,  0}, // 7
                    { 0, 0, 0, 0, 0, 0, 0, 0, 4, 0,  7}, // 8
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  4}, // 9
                    { 0, 0, 0, 0, 0, 0, 0, 0, 3, 0,  6}, // 10
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0}  // 11
                };


typedef struct node {
   int val;
   int state; //status
   int pred; //predecessor
}node;

int minimum(int a, int b) {
   return (a<b)?a:b;
}

int resGraph[V][V];

                   
int bfs(node *vert, node start, node sink) {
   node u;
   int i;
   queue<node> q;

    for(i = 0; i < V; i++) {
        vert[i].state = 0;    //not visited
    }

    vert[start.val].state = 1;   //visited
    vert[start.val].pred = -1;   //no parent node
    q.push(start);   //insert starting node

    while(!q.empty()) {
        //pop from queue and print
        u = q.front();
        q.pop();

        for(i = 0; i < V; i++){
            if(resGraph[u.val][i] > 0 && vert[i].state == 0){
                q.push(vert[i]);
                vert[i].pred = u.val;
                vert[i].state = 1;
            }
        }
    }
    return (vert[sink.val].state == 1);
}

int fordFulkerson(node *vert, node source, node sink) {
    int maxFlow = 0;
    int u, v;

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            resGraph[i][j] = graph[i][j];    //initially residual graph is main graph
        } 
    }

    while(bfs(vert, source, sink)) {    //find augmented path using bfs algorithm
        int pathFlow = 999;//as infinity
        for(v = sink.val; v != source.val; v=vert[v].pred) {
            u = vert[v].pred;
            pathFlow = minimum(pathFlow, resGraph[u][v]);
        }

        for(v = sink.val; v != source.val; v=vert[v].pred) {
            u = vert[v].pred;
            resGraph[u][v] -= pathFlow;   //update residual capacity of edges
            resGraph[v][u] += pathFlow;   //update residual capacity of reverse edges
        }

        maxFlow += pathFlow;
    }

    return maxFlow;    //the overall max flow
}

int main() {
    node vertices[V];
    node source, sink;

    for(int i = 0; i < V; i++) {
        vertices[i].val = i;
    }

    source.val = 0;
    sink.val = 10;
    int maxFlow = fordFulkerson(vertices, source, sink);
    cout << "Maximum flow is: " << maxFlow << endl;
}