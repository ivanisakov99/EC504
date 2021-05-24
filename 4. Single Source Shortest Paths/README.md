# <ins>Single Source Shortest Paths</ins>
### <ins>Problem 1: Finding Shortest Paths</ins>
In this problem, you will implement three versions of shortest path algorithms: a simple version of Dijkstra’s algorithm using a list instead of a priority queue, a version of 
Dijkstra’s algorithm that uses a binary heap as a priority queue, and a version of Bellman-Ford algorithm that uses a work queue.

*Shortest paths.cpp* is the main program with all the timing routines included. It reads a directed graph from a file. It loads the information into an array of vertices called Nodes. Associated with each node is a linked list of edges (arcs). The Node structure and the arc structure are defined in an include file *shortPath.h* , along with the three shortest path algorithms that need to be developed.

A makefile is included. To compile your executable, simply type *make shortest*. Three different input graphs are provided: Graph1.txt, Graph2.txt, Graph3.txt. A fourth input graph, smallgraph.txt, is provided along with the output file smallgraph1.txt out to help you with debugging.

Note that the vertices in the input files are numbered from 1 to *Nm*. The Nodes[] data structure hence ignores the Nodes[0] element, so that an index equals to the node id. The element Nodes[0] has no information, and should not be used in any of the algorithms.

To run the program, simply type __./shortest smallgraph.txt__. This will generate the output small-graph.txt_out which you can compare with the output file provided.

Note that you can compile and run the codes as they are and get the correct output for one algorithm. You can use this to verify that your other algorithms are also getting correct outputs.

If you program your algorithms well, your BellmanFord and DijkstraHeap algorithms should run four orders of magnitude faster than the simple Dijkstra algorithm I’ve provided, for Graph3.txt that has 100,000 vertices. This is due to the O(|V|^2) complexity versus the O(|E|log(|V|) complexity of Dijkstra’s algorithm with a binary heap. The surprise is the Bellman Ford algorithm’s speed, which shows that an average case for this algorithm can be very fast when you avoid unneeded computations.
