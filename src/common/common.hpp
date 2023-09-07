#pragma once

#include <functional>
#include <vector>
#include <set>
#include <tuple>
#include <optional>

class Node;

using Coordinate = std::pair <int, int>;
using MazeRow = std::vector<char>;
using Maze = std::vector<MazeRow>;
using Path = std::set<Node>;
using OptionalPath = std::optional<Path>;
using PathFindingAlgorithm = std::function<OptionalPath(const Maze&, const Node&, const Node&)>;

class Node
{
public:
	Node(const Coordinate& coordinate) noexcept :
		m_coordinate{ coordinate }
	{}

	Node()
	{}

	void setCoordinate(const Coordinate& coordinate) noexcept
	{
		m_coordinate = coordinate;
	}

	const Coordinate& getCoordinate() const noexcept
	{
		return m_coordinate;
	}

	bool operator == (const Node& rightOperand) const
	{
		return m_coordinate == rightOperand.m_coordinate;
	}

	auto operator <=> (const Node& rightOperand) const
	{
		return m_coordinate <=> rightOperand.m_coordinate;
	}

private:
	Coordinate m_coordinate{};
};