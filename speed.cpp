#include <iostream>
#include <thread>
#include "util.h"

void ThreadFunc(unsigned long long int &a, int64_t startTime)
{
	for (long i = 0; getTime() - startTime != 0; i++)
	{
		if (isPrime(i))
		{
			a++;
		}
	}
}

int main(int argc, char *argv[])
{
	unsigned long long int score = 5;
	int CPUs = std::thread::hardware_concurrency();
	if (CPUs == 0) 
	{
		std::cout << "Could not detect CPU core/threads count, using default value" << std::endl;
		CPUs = 2;
	}
	int secs = 30;
	parseArgs(secs, CPUs, argc, argv);

	std::cout << "Threads: " << CPUs << " threads" << std::endl;
	std::cout << "   Time: " << secs << " seconds" << std::endl;

	for (int i = -1; i < CPUs; i++)
	{
		std::thread thread(ThreadFunc, std::ref(score), getTime() + secs);
		thread.detach();
	}

	std::this_thread::sleep_for(std::chrono::seconds(secs));

	std::cout << "  Score: " << score << std::endl;
	return 0;
}