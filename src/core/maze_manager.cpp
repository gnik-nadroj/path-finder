#include "maze_manager.hpp"

#include <fstream>
#include <iostream>

void MazeManager::generateMaze()
{
    std::ifstream mazeFile{ m_mazeFilePath, std::ios::in };

    if (!mazeFile.is_open())
    {
        throw std::runtime_error("Could not open the file");
    }

    std::string line{};
    int currentRow{};
    bool findingStartingPosition{};
    bool findingEndingPosition{};

    while (getline(mazeFile, line))
    {
        MazeRow mazeLine{};

        for (auto currentColumn = 0; currentColumn < line.size(); currentColumn++)
        {
            if (line[currentColumn] != '\n')
            {
                if (line[currentColumn] == '1')
                {
                    m_mazeEntry.setCoordinate(Coordinate(currentRow, currentColumn));
                    findingStartingPosition = true;
                }
                else if (line[currentColumn] == '2')
                {
                    m_mazeEnding.setCoordinate(Coordinate(currentRow, currentColumn));
                    findingEndingPosition = true;
                }

                mazeLine.push_back(line[currentColumn]);
            }
        }
        m_maze.push_back(mazeLine);
        currentRow++;
    }

    mazeFile.close();

    if (!(findingStartingPosition && findingEndingPosition))
    {
        throw std::runtime_error("Can't find starting and ending position in the maze");
    }
}

void MazeManager::solveMaze(PathFindingAlgorithm pathFindingAlgo)
{
    m_pathBetweenEntryAndEnding = pathFindingAlgo(m_maze, m_mazeEntry, m_mazeEnding).value_or(Path());
}

void MazeManager::printMaze()
{
    for (auto row = 0; row < m_maze.size(); row++)
    {
        for (auto col = 0; col < m_maze[0].size(); col++)
        {
            Node currentNode{ {row, col} };
            if (m_pathBetweenEntryAndEnding.contains(currentNode) && 
                currentNode != m_mazeEntry && 
                currentNode != m_mazeEnding)
            {
                std::cout << "P";
            }
            else
            {
                std::cout << m_maze[row][col];
            }
        }
        std::cout << std::endl;
    }
}
