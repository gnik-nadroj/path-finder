#include <algorithm.hpp>
#include <maze_manager.hpp>

#include <chrono>
#include <iostream>

int main() 
{
	try
	{
		MazeManager mazeManager{ "K:/dev-projects/path-finder/maze/rect_05.map" };

		auto startT = std::chrono::high_resolution_clock::now();

		mazeManager.solveMaze(bfs);

		auto endT = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endT - startT);

		std::cout << "Time taken by code block: " << duration.count() << " microseconds" << std::endl;

		mazeManager.printMaze();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}