#include <algorithm.hpp>
#include <maze_manager.hpp>

#include <chrono>
#include <format>
#include <iostream>
#include <map>


const std::map<std::string, PathFindingAlgorithm> algorithmsCatalog {
	{ "bfs", bfs},
	{ "dfs", dfs },
	{ "a*", aStar }
};

int main(int argc, char* argv[])
{
	if (argc < 3) {
		std::cerr << "missing arguments" << std::endl;
		exit(-1);
	}

	try
	{
		auto mazeFsPath{ argv[1] };
		auto usedAlgorithm{ argv[2] };

		MazeManager mazeManager{ mazeFsPath };

		if (algorithmsCatalog.contains(usedAlgorithm)) 
		{
			auto algo = algorithmsCatalog.at(usedAlgorithm);

			auto startT = std::chrono::high_resolution_clock::now();

			mazeManager.solveMaze(algo);

			auto endT = std::chrono::high_resolution_clock::now();

			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endT - startT);

			std::cout << std::format("Operation done in {} microseconds", duration);
		}
		else
		{
			std::cerr << std::format("{} algorithms is not avalaible in the algorithm catalog composed of bfs, dfs and a*\n", usedAlgorithm);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}
