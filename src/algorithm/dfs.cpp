#include "algorithm.hpp"

#include <algorithm>
#include <set>
#include <stack>

static auto getNeightBors(const Node& node)
{
	auto [nodeRow, nodeColumn] = node.getCoordinate();

	std::vector<Node> neighBors = 
	{
		Node({nodeRow, nodeColumn + 1}),
		Node({nodeRow + 1, nodeColumn}),
		Node({nodeRow - 1, nodeColumn}),
		Node({nodeRow, nodeColumn - 1})
	};

	return neighBors;
}

const bool isUsableNode(const Node& node, const Maze& maze)
{
	auto [nodeRow, nodeColumn] = node.getCoordinate();

	auto isValidCoordinate = nodeRow >= 0 && nodeRow < maze.size() && nodeColumn >= 0 && nodeColumn < maze.front().size();

	auto isNotAWall = isValidCoordinate ? maze[nodeRow][nodeColumn] != '*' : false;

	return isValidCoordinate && isNotAWall;
}

static std::optional<Node> getUnvisitedNeighbor(const Node& node, const Maze& maze, const Path& visitedNodes)
{
	auto neighBors = getNeightBors(node);

	auto itemItr = std::find_if(neighBors.begin(), neighBors.end(), [&visitedNodes, &maze](const Node& item) { 
		return isUsableNode(item, maze) && !visitedNodes.contains(item);
	});

	if(itemItr != neighBors.end())
	{
		return *itemItr;
	}

	return {};
}

static void setVisited(const Node& node, Path& visitedNodes, std::stack<Node>& nodeStack)
{
	visitedNodes.insert(node);
	nodeStack.push(node);
}

OptionalPath Algorithm::dfs(const Maze& maze, const Node& startingNode, const Node& endingNode)
{
	std::stack<Node> nodeStack{};
	Path path {};

	using namespace std::placeholders;

	auto setVisitedForward = std::bind(setVisited, _1, std::ref(path), std::ref(nodeStack));
	
	setVisitedForward(startingNode);

	while (!nodeStack.empty())
	{
		auto currentNode = nodeStack.top();

		if (auto neighBorOpt = getUnvisitedNeighbor(currentNode, maze, path))
		{
			auto neighBor = neighBorOpt.value();
			setVisitedForward(neighBor);

			if (neighBor == endingNode)
			{
				return path;
			}
		}
		else
		{
			nodeStack.pop();
		}
	}

	return {};
}