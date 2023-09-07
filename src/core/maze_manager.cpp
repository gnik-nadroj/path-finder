#include "maze_manager.hpp"

#include <fstream>

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

auto MazeManager::solveMaze(PathFindingAlgorithm pathFindingAlgo)
{
    return pathFindingAlgo(m_maze, m_mazeEntry, m_mazeEnding);
}

void MazeManager::printMaze()
{
}
