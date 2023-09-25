#pragma once

#include <common.hpp>

NodeList getNeightBors(const Node& node);
bool isUsableNode(const Node& node, const Maze& maze);
NodeList getUnvisitedNeighbors(const Node& node, const Maze& maze, const Path& visitedNodes);
std::optional<Node> getUnvisitedNeighbor(const Node& node, const Maze& maze, const Path& visitedNodes);