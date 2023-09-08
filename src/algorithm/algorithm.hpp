#pragma once

#include "utils.hpp"

#include <common.hpp>


OptionalPath dfs(const Maze& maze, const Node& startingNode, const Node& endingNode);
OptionalPath bfs(const Maze& maze, const Node& startingNode, const Node& endingNode);
