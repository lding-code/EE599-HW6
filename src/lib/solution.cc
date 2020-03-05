#include "solution.h"

#include <iostream>
#include <string>
#include <vector>
#include <stack>

std::string Solution::HelloWorld() {
    return "HelloWorld";
}

std::vector<int> Graph::DFS(int root) {
    std::stack<int> verStack({root});
    std::set<int> visited;
    std::vector<int> rtnVec;

    while (verStack.empty() != true) {
        std::set<int> topEdge(v_[verStack.top()]);
        bool allVisited = true;

        std::cout << "now at vertex " << std::to_string(verStack.top()) << std::endl;
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

            std::cout << "now at vertex " << std::to_string(verStack.top()) << std::endl;
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