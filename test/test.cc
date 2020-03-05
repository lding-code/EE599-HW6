#include "gtest/gtest.h"
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

#include "src/lib/solution.h"

TEST(HelloWorldShould, ReturnHelloWorld) {
    Solution solution;

    std::string actual = solution.HelloWorld();
    std::string expected = "HelloWorld";

    EXPECT_EQ(expected, actual);
}

// Q3 DFS test case 1: example
TEST(DFSShould1, ReturnDFS1) {
    std::map<int, std::set<int>> vertices{
        {0, {1, 2, 5}},
        {1, {0, 2, 3}},
        {2, {0, 1, 3}},
        {3, {1, 2, 4, 6}},
        {4, {3}},
        {5, {0}},
        {6, {3}}
    };
    Graph g(vertices);

    std::vector<int> actual = g.DFS(0);
    std::vector<int> expected = {0, 1, 2, 3, 4, 6, 5};

    EXPECT_EQ(expected, actual);
}

// Q3 DFS test case 2: in the exmaple
TEST(DFSShould2, ReturnDFS2) {
    std::map<int, std::set<int>> vertices{
        {1, {2, 3}},
        {2, {1, 3, 4, 5}},
        {3, {1, 2, 4}},
        {4, {2, 3, 4}},
    };
    Graph g(vertices);

    std::vector<int> actual = g.DFS(1);
    std::vector<int> expected = {1, 2, 3, 4, 5};

    EXPECT_EQ(expected, actual);
}

// Q3 DFS test case 3: single element
TEST(DFSShould3, ReturnDFS3) {
    std::map<int, std::set<int>> vertices{
        {0, {}}
    };
    Graph g(vertices);

    std::vector<int> actual = g.DFS(0);
    std::vector<int> expected = {0};

    EXPECT_EQ(expected, actual);
}

// Q3 DFS test case 4: single branch
TEST(DFSShould4, ReturnDFS4) {
    std::map<int, std::set<int>> vertices{
        {0, {1}},
        {1, {2}},
        {2, {3}},
        {3, {4}},
        {4, {}}
    };
    Graph g(vertices);

    std::vector<int> actual = g.DFS(0);
    std::vector<int> expected = {0, 1, 2, 3, 4};

    EXPECT_EQ(expected, actual);
}

// Q4 DFS_ALL test case 1: example
TEST(DFS_ALLShould1, ReturnDFS_ALL1) {
    std::map<int, std::set<int>> vertices{
        {0, {1}},
        {1, {2, 3}},
        {2, {0}},
        {3, {2, 4, 6}},
        {4, {}},
        {5, {6}},
        {6, {}}

    };
    Graph g(vertices);

    std::vector<int> actual = g.DFS_ALL();
    std::vector<int> expected = {0, 1, 2, 3, 4, 6, 5};

    EXPECT_EQ(expected, actual);
}

// Q4 DFS_ALL test case 2: example from geeks for geeks
TEST(DFS_ALLShould2, ReturnDFS_ALL2) {
    std::map<int, std::set<int>> vertices{
        {0, {1, 2}},
        {1, {0, 3, 4}},
        {2, {0, 4}},
        {3, {1, 4, 5}},
        {4, {1, 2, 3, 5}},
        {5, {3, 4}},

    };
    Graph g(vertices);

    std::vector<int> actual = g.DFS_ALL();
    std::vector<int> expected = {0, 1, 3, 4, 5, 2};

    EXPECT_EQ(expected, actual);
}