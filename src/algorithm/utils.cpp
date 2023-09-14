#include "utils.hpp"

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

std::optional<Node> getUnvisitedNeighbor(const Node& node, const Maze& maze, const Path& visitedNodes)
{
	auto neighBors = getNeightBors(node);

	auto itemItr = std::find_if(neighBors.begin(), neighBors.end(), [&visitedNodes, &maze](const Node& item) {
		return isUsableNode(item, maze) && !visitedNodes.contains(item);
	});

	if (itemItr != neighBors.end())
	{
		return *itemItr;
	}

	return {};
}