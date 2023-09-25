#include "algorithm.hpp"

#include <queue>


static double manhattanDistance(const Node& from, const Node& to)
{
    auto [fromX, fromY] = from.getCoordinate();
    auto [toX, toY] = to.getCoordinate();

    return std::abs(fromX - fromY)
           +
           std::abs(fromY - toY);
}

OptionalPath aStar(const Maze& maze, const Node& startingNode, const Node& endingNode)
{
    auto compareFunction = [&endingNode](const Node& l, const Node& r) {
        return manhattanDistance(l, endingNode) > manhattanDistance(r, endingNode);
    };

    std::priority_queue<Node, std::vector<Node>, decltype(compareFunction)> openList { compareFunction };
    Path closeList{};
    
    openList.push(startingNode);

    while (!openList.empty())
    {
        auto currNode = openList.top();
        openList.pop();
        closeList.insert(currNode);

        if (currNode == endingNode) 
        {
            return closeList;
        }
        
        auto neighBor = getUnvisitedNeighbors(currNode, maze, closeList);

        std::ranges::for_each(neighBor, [&openList](const Node& item) {
            openList.push(item);
        });
    }

    return {};
}