#include "solution.h"

#include <iostream>
#include <string>
#include <vector>
#include <stack>

std::string Solution::HelloWorld() {
    return "HelloWorld";
}

std::vector<int> Solution::rearrange(std::vector<int> &v, int i) {
    int target = v[i];
    std::vector<int> rtn{};
    for (auto it = v.begin();it != v.end(); it++) {
        if (*it < target) {
            rtn.push_back(*it);
        }
    }
    for (auto it = v.begin();it != v.end(); it++) {
        if (*it == target) {
            rtn.push_back(*it);
        }
    }
    for (auto it = v.begin();it != v.end(); it++) {
        if (*it > target) {
            rtn.push_back(*it);
        }
    }
    return rtn;
}

std::vector<int> Graph::DFS(int root) {

    std::stack<int> verStack({root});
    std::set<int> visited;
    std::vector<int> rtnVec;

    while (verStack.empty() != true) {
        std::set<int> topEdge(v_[verStack.top()]);
        bool allVisited = true;

        // if current vertex is not visited before: (push it to return vector and insert to visited)
        if (visited.find(verStack.top()) == visited.end()) {
            // push to return vector
            rtnVec.push_back(verStack.top());
            // insert to visited
            visited.insert(verStack.top());
        }
        
        // iterate all edges of the top vertex
        for (auto it = topEdge.begin(); it != topEdge.end(); it++) {
            // if find new vectex that has not been visited before: (keep search down)
            if (visited.find(*it) == visited.end()) {
                // set allVisited to false
                allVisited = false;
                // add new vertex to stack
                verStack.push(*it);
                break;
            }
        }

        // if all edges are visited -> this vertex needs to be popped
        if (allVisited == true) {
            // pop the top vertex
            verStack.pop();
        }
    }

    return rtnVec;
}

std::vector<int> Graph::DFS_ALL() {
    std::set<int> visited;
    std::vector<int> rtnVec;

    for (auto verIt = v_.begin(); verIt != v_.end(); verIt++) {
        std::stack<int> verStack({verIt->first});
        while (verStack.empty() != true) {
            std::set<int> topEdge(v_[verStack.top()]);
            bool allVisited = true;

            // if current vertex is not visited before: (push it to return vector and insert to visited)
            if (visited.find(verStack.top()) == visited.end()) {
                // push to return vector
                rtnVec.push_back(verStack.top());
                // insert to visited
                visited.insert(verStack.top());
            }
            
            // iterate all edges of the top vertex
            for (auto it = topEdge.begin(); it != topEdge.end(); it++) {
                // if find new vectex that has not been visited before: (keep search down)
                if (visited.find(*it) == visited.end()) {
                    // set allVisited to false
                    allVisited = false;
                    // add new vertex to stack
                    verStack.push(*it);
                    break;
                }
            }

            // if all edges are visited -> this vertex needs to be popped
            if (allVisited == true) {
                // pop the top vertex
                verStack.pop();
            }
        }
    }
    return rtnVec;
}


bool Graph::mazeHasPath(std::vector<std::vector<int>> &maze, std::vector<int> start, std::vector<int>end) {

    // convert 2D vector to connected graph
    int rowSize = maze.size();
    int colSize = maze[0].size();
    for (int row = 0; row < rowSize; row++) {
        for (int col = 0; col < colSize; col++) {
            // if current cell is 1 -> valid vertex
            if (maze[row][col] == 1) {
                v_.insert(std::pair<int, std::set<int>>(row * colSize + col, {}));
                int ver = row * colSize + col;
                // if not on top -> possible to connect to top cell if it's also 1
                if (row != 0) {
                    if (maze[row - 1][col] == 1) {
                        v_[ver].insert((row-1) * colSize + col);
                    }
                }
                // if not on left edge -> possible to connect to left cell if it's also 1
                if (col != 0) {
                    if (maze[row][col - 1] == 1) {
                        v_[ver].insert(row * colSize + (col - 1));
                    }
                }
                // if not on bottom -> possible to connect to bottom cell if it's also 1
                if (row != rowSize - 1) {
                    if (maze[row + 1][col] == 1) {
                        v_[ver].insert((row + 1) * colSize + col);
                    }
                }
                // if not on right edge -> possible to connect to right cell if it's also 1
                if (col != colSize - 1) {
                    if (maze[row][col + 1] == 1) {
                        v_[ver].insert(row * colSize + (col + 1));
                    }
                }
            }
        }
    }

    // get start and end point
    int startVer = start[0] * colSize + start[1];
    int endVer = end[0] * colSize + end[1];

    // traverse all from start point
    std::vector<int> reachableVer = DFS(startVer);

    // find if end vertex exists in the traverse vector
    for (auto it = reachableVer.begin(); it != reachableVer.end(); it++) {
        if (*it == endVer) {
            return true;
        }
    }
    return false;
}