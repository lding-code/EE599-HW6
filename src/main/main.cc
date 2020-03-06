#include <iostream>

#include "src/lib/solution.h"

int main(int argc, char* argv[]) {
    Solution solution;
    std::cout << solution.HelloWorld() << std::endl;
    std::vector<std::vector<int>> maze = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };
    Graph g;

    std::cout << "maze.size() = " << std::to_string(maze.size()) << std::endl;

    std::cout << "has path: " << std::to_string(g.mazeHasPath(maze,  {0, 0}, {4, 4})) << std::endl;

    return EXIT_SUCCESS;
}