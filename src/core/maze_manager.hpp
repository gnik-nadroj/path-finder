#pragma once

#include <common.hpp>

#include <string>
#include <string_view>


class MazeManager
{
public:
    MazeManager()
    {}

    MazeManager(std::string_view mazeFilePath) : m_mazeFilePath{ mazeFilePath }
    {
        generateMaze();
    }

    void solveMaze(PathFindingAlgorithm pathFindingAlgo);

    void printMaze();
private:
    std::string m_mazeFilePath{};
    Maze m_maze{};
    Node m_mazeEntry{};
    Node m_mazeEnding{};
    Path m_pathBetweenEntryAndEnding{};

    void generateMaze();
};



