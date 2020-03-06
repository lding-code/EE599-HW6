#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H


#include <string>
#include <map>
#include <set>
#include <vector>
class Solution {

public:
    std::string HelloWorld();
};

class Graph {
public:
    Graph():v_({}) {}
    Graph(std::map<int, std::set<int>> &vertices) : v_(vertices) {}
    std::vector<int> DFS(int root);
    std::vector<int> DFS_ALL();

    bool mazeHasPath(std::vector<std::vector<int>> &maze, std::vector<int> start, std::vector<int> end);

    std::map<int, std::set<int>> v_;
};

#endif