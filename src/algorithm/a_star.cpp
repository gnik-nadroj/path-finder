#include "algorithm.hpp"

#include <cmath>
#include <queue>



static double diagonalDistance(const Node& from, const Node& to)
{
    constexpr auto diagDistance{ 1.414213562373095 };
    constexpr auto nodeLength{ 1 };

    auto [fromX, fromY] = from.getCoordinate();
    auto [toX, toY] = to.getCoordinate();

    auto dX{ std::abs((fromX - toX)) };
    auto dY{ std::abs((fromY - toY)) };

    return nodeLength * (dX + dY) + (diagDistance - 2 * nodeLength) * std::min(dX, dY);
}

OptionalPath aStar(const Maze& maze, const Node& startingNode, const Node& endingNode)
{
    auto compareFunction = [&endingNode](const Node& l, const Node& r) {
        auto lCost = diagonalDistance(l, endingNode);
        auto rCost = diagonalDistance(r, endingNode);
        return lCost > rCost;
    };

    std::priority_queue<Node, std::deque<Node>, decltype(compareFunction)> openList { compareFunction };
    Path closeList{};
    openList.push(startingNode);

    while (!openList.empty())
    {
        Node currNode = openList.top();
        openList.pop();
        closeList.insert(currNode);

        if (currNode == endingNode) 
        {
            return closeList;
        }

        auto [nodeRow, nodeColumn] = currNode.getCoordinate();

        
        auto neighBor = {
            Node({nodeRow, nodeColumn + 1}),
            Node({nodeRow + 1, nodeColumn}),
            Node({nodeRow - 1, nodeColumn}),
            Node({nodeRow, nodeColumn - 1}),
            Node({nodeRow - 1, nodeColumn + 1}),
            Node({nodeRow - 1, nodeColumn - 1}),
            Node({nodeRow + 1, nodeColumn + 1}),
            Node({nodeRow + 1, nodeColumn - 1})
        };

        std::ranges::for_each(neighBor, [&openList, &closeList, &maze](const Node& item) {
            if (isUsableNode(item, maze) && !closeList.contains(item)) {
                openList.push(item);
            }
        });
    }

    return {};
}
