#include "algorithm.hpp"

#include <queue>


static void setVisited(const Node& node, Path& visitedNodes, std::queue<Node>& nodeQueue)
{
	visitedNodes.insert(node);
	nodeQueue.push(node);
}

static void setNeighBorsInQueue(const Node& node, const Maze& maze, Path& visitedNodes, std::queue<Node>& nodeQueue)
{
	while(auto neighBor = getUnvisitedNeighbor(node, maze, visitedNodes))
	{
		setVisited(neighBor.value(), visitedNodes, nodeQueue);
	}
}

OptionalPath bfs(const Maze& maze, const Node& startingNode, const Node& endingNode)
{
	Path path{};
	std::queue<Node> nodeQueue{};

	using namespace std::placeholders;
	setVisited(startingNode, path, nodeQueue);
	while (!nodeQueue.empty())
	{
		auto currentNode = nodeQueue.front();

		if (currentNode == endingNode)
		{
			return path;
		}

		nodeQueue.pop();
		setNeighBorsInQueue(currentNode, maze, path, nodeQueue);
	}

	return {};
}