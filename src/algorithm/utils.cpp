#include "utils.hpp"
#include <ranges>

NodeList getNeightBors(const Node& node)
{
	auto [nodeRow, nodeColumn] = node.getCoordinate();

	NodeList neighBors =
	{
		Node({nodeRow, nodeColumn + 1}),
		Node({nodeRow + 1, nodeColumn}),
		Node({nodeRow - 1, nodeColumn}),
		Node({nodeRow, nodeColumn - 1})
	};

	return neighBors;
}

bool isUsableNode(const Node& node, const Maze& maze)
{
	auto [nodeRow, nodeColumn] = node.getCoordinate();

	auto isValidCoordinate = nodeRow >= 0 && nodeRow < maze.size() && nodeColumn >= 0 && nodeColumn < maze.front().size();

	auto isNotAWall = isValidCoordinate ? maze[nodeRow][nodeColumn] != '*' : false;

	return isValidCoordinate && isNotAWall;
}

NodeList getUnvisitedNeighbors(const Node& node, const Maze& maze, const Path& visitedNodes)
{
	auto usableNeighBors = getNeightBors(node) | std::views::filter([&maze, &visitedNodes](const Node& item) {
		return isUsableNode(item, maze) && !visitedNodes.contains(item);
	});

	return { usableNeighBors.begin(), usableNeighBors.end() };
}

std::optional<Node> getUnvisitedNeighbor(const Node& node, const Maze& maze, const Path& visitedNodes)
{

	if (auto neighbors = getUnvisitedNeighbors(node, maze, visitedNodes); !neighbors.empty())
	{
		return neighbors.front();
	}

	return {};
}