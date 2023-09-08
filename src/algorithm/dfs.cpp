#include "algorithm.hpp"

#include <algorithm>
#include <stack>

static void setVisited(const Node& node, Path& visitedNodes, std::stack<Node>& nodeStack)
{
	visitedNodes.insert(node);
	nodeStack.push(node);
}

OptionalPath dfs(const Maze& maze, const Node& startingNode, const Node& endingNode)
{
	std::stack<Node> nodeStack{};
	Path path {};

	using namespace std::placeholders;

	auto setVisitedForward = std::bind(setVisited, _1, std::ref(path), std::ref(nodeStack));
	
	setVisitedForward(startingNode);

	while (!nodeStack.empty())
	{
		auto currentNode = nodeStack.top();

		if (currentNode == endingNode)
		{
			return path;
		}

		if (auto neighBorOpt = getUnvisitedNeighbor(currentNode, maze, path))
		{
			auto neighBor = neighBorOpt.value();
			setVisitedForward(neighBor);
		}
		else
		{
			nodeStack.pop();
		}
	}

	return {};
}
