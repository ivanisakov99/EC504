### <ins>Problem 1: Finding Connected Components</ins>
In this problem, you will search two undirected Graphs, to find the connected components. You will output a vector which is of the length number of vertices, where each vertex will be assigned the number of the component the vertex is in, from 1 to total number of components. You will need to complete the two functions to do Breadth First Search of the graph, as well as Depth First Search.

*An undirected graph G(V, E) is defined in terms of two arrays: First Vertex[0 : Vsize] and EdgeList[0 : Esize] that label the vertices from 0, 1, . . . , Vsize−1 and edges from 0, 1, . . . , Esize−1, respectively. The last “fake” vertex (First Vertex[Vsize] = Esize) points to the null “fake” edge with ”null” value ( Edge[Esize] = −1). This is the Forward Star data structure discussed in class.*


### <ins>Problem 2: Searching Decision Graphs/N-Queen Problem</ins>
There are many decision problems where finding a solution can be cast as a search problem in a graph of states. In this exercise, you will solve another large decision problem through implicit enumeration and search on the graph. Consider the classical 8 queens problem in chess: Given a chess board, how do you place 8 queens so that no two queens can capture each other? That is, each row must have only one queen, each column must have only one queen, and no two queens can be on the same diagonal.

How do we pose the problem as a search problem in a graph? One needs to define the concept of a state of a computation. A state will correspond to a partial solution. The idea is to build a complete solution from partial solutions, by traversing the graph of possible partial solutions until one finds a complete solution. The states of computations are the vertices.

What is the graph of partial solutions? To convert the 8 queens problem to a sequential problem, consider the placement of queens one row at a time. Thus, after placing a queen in the first row, one has a partial solution (a first-layer solution). Having placed queens in the first two columns, there is another partial solution (second layer solution), corresponding to a new vertex at the second layer.

The problem is that this graph is enormous. To illustrate, for a 10 × 10 board, the number of possible states in the ninth level are 10^9. We don’t want to draw or store this graph.

Fortunately, when we use Depth First Search, we don’t have to enumerate this graph. We just know how to transition from one solution to the next layer by adding a queen. The DFS recursion keeps track of the partial solution to date, and returns with a full solution. The problem is thus reduced to finding a path from the root node (an empty board with no queens) to solution with n queens on an n × n board.

Note the following:
* For an n × n board, a vertex in this problem can be characterized as a set of positions of queens on the board.
* Assume that one is at a vertex which is at level k in the problem, so that there are Queens on the first k rows. Then, the children of this vertex have first k queens in the same position, plus one additional queen in column k + 1, but only if the additional queen is placed in a location where it cannot be captured. Thus, one has to check whether that position in the next level for that queen is one that cannot be captured by any of the queens in the previous columns.

__This works for boards that are bigger than 3 by 3__
