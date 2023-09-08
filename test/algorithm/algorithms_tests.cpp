#include <algorithm.hpp>

#include <iostream>

#include <gtest/gtest.h>


static Maze findablePathMaze = {
{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
{'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
{'*', ' ', '*', ' ', '*', ' ', '*', '*', ' ', '*'},
{'*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*'},
{'*', ' ', ' ', '*', '*', '*', '*', '*', ' ', '*'},
{'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*'},
{'*', '*', '*', '*', ' ', '*', '*', '*', ' ', '*'},
{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
{'*', '*', '*', '*', '*', '*', '*', '*', ' ', '*'},
{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
};

static const Maze unfindablePathMaze = {
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', '*', '*', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', ' ', '*', '*', '*', '*', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
};

static Node entryNode{{1, 1}};

static Node endNode{{1, 8}};

TEST(findablePath, dfsTest) 
{
    auto path = dfs(findablePathMaze, entryNode, endNode);

    EXPECT_TRUE(path);
}

TEST(unFindablePath, dfsTest)
{
    auto path = dfs(unfindablePathMaze, entryNode, endNode);

    EXPECT_FALSE(path);
}

TEST(some, bfsTest)
{
    auto path = bfs(findablePathMaze, entryNode, endNode);

    EXPECT_TRUE(path);
}

TEST(some2, bfsTest)
{
    auto path = bfs(unfindablePathMaze, entryNode, endNode);

    EXPECT_FALSE(path);
}