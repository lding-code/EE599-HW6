# EE599-HW6

Q1. 
A tree is an undirected graph.
A tree is a cnnected graph.
A tree is a acyclic graph.
In a tree, there is not a path from each vertex to all other vectices.
A simple graphs is a graph that doesn not have loops or multiple edges between same pair of vertices.


Q2.
[ilovecoding]
[ilove] [coding]
[[il] [ove]] [[cod] [ing]]
[[[i] [l]] [[o] [ve]]] [[[c] [od]] [[i] [ng]]]
[[[i] [l]] [[o] [[v] [e]]]] [[[c] [[o] [d]]] [[i] [[n] [g]]]]
[[il] [[o] [ev]]] [[[c] [do]] [[i] [gn]]]
[[il] [eov]] [[cdo] [ign]]
[[eilov] [cdgino]]
[cdegiilnoov]

Q3.
Implemented in the solution source file as DFS() method of class Graph.
Tested in GTest.
Runtime = O(V+E) because all vertices and edges are visited for once.

Q4.
Implemented in the solution source file as DFS_ALL() method of class Graph.
My algorithm always tries to visit edges with lowest value possible. Therefore, the output with example input from question 4 would be:
[0, 1, 2, 3, 4, 6, 5]
because at vertex 1, it will try to traverse from 2 to 3 where 2 is visited first. Although the order is different, this is still a DFS algorithm as it tries to visit next connected vertex (child of child in tree terminology) before it visit all connected vertices of the current vertex. It goes deep isteand of broad.

Tedted in GTest.
Runtime = O(V+E) because all vertices and edges are visited for once.

Q5.
Implemented in the solution source file as mazeHasPath() method of class Graph.
It first convert 2D vector to a graph through for loop and call DFS() method to get a vector containing reachable vertices from the start point. It then find the end point in the reachable vertices. If the end point is in the vector, there is a path.

Tested in GTest

Runtime = O((V+E) + (V+E)) = O(V+E):
    The first (V+E) is time complexity of converting 2D vecvtor to graph.
    The second (V+E) is time complexity of DFS.

Q6.
Implemented in solution source file as rearrange() method of class Solution.
It iterates the vector for 3 times.
The first time it finds elements smaller than the target and push_back those elements to the return vector.
The second time it finds elements that equals to the target and push_back those elements to the return vector.
The third time it finds elements that are greater than the target and push_back those elements to the return vector.

Tested in GTest

Runtime = O(3n) = O(n)