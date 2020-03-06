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
Implemented in the solution source file as DFS method of class Graph.
Tested in GTest.
Runtime = O(V+E) because all vertices and edges are visited for once.

Q4.
Implemented in the solution source file as DFS_ALL of class Graph.
My algorithm always tries to visit edges with lowest value possible. Therefore, the output with example input from question 4 would be:
[0, 1, 2, 3, 4, 6, 5]
because at vertex 1, it will try to traverse from 2 to 3 where 2 is visited first. Although the order is different, this is still a DFS algorithm as it tries to visit next connected vertex (child of child in tree terminology) before it visit all connected vertices of the current vertex. It goes deep isteand of broad.

Tedted in GTest.
Runtime = O(V+E) because all vertices and edges are visited for once.

Q5