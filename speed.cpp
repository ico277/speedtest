#include <iostream>
#include <thread>
#include "util.h"

void ThreadFunc(int &a, int64_t startTime)
{
	while (getTime() - startTime != 0)
	{
		a++;
	}
}


int main(int argc, char *argv[])
{
	int score = 0;
	int CPUs = std::thread::hardware_concurrency();
	if (CPUs == 0) CPUs = 2;
	int secs = 30;
	parseArgs(secs, CPUs, argc, argv);

	std::cout << "Using " << CPUs << " Threads" << std::endl;
	std::cout << "Time: " << secs << " seconds" << std::endl;

	for (int i = -1; i < CPUs; i++)
	{
		std::thread thread(ThreadFunc, std::ref(score), getTime() + secs);
		thread.detach();
	}

	std::this_thread::sleep_for(std::chrono::seconds(secs));

	std::cout << "Score: " << score << std::endl;
	return 0;
}