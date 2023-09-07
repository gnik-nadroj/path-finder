#include <algorithm.hpp>
#include <maze_manager.hpp>


#include <iostream>

int main() 
{
	try
	{
		MazeManager mazeManager{ "K:/dev-projects/path-finder/maze/rect_01.map" };
		mazeManager.solveMaze(Algorithm::dfs);
		mazeManager.printMaze();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}