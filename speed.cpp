#include <iostream>
#include <thread>
#include <string>
#include "time.h"

#define VERSION "0.0.1-BETA"
#ifdef __linux__
#define OS "Linux"
#elif __FreeBSD__
#define OS "FreeBSD"
#else
#define OS "Unrecognised OS"
#endif

void test(int &a, int64_t startTime)
{
	while (get_seconds_since_epoch() - startTime != 0)
	{
		a++;
	}
}

int parseArgs(int &secs, int &CPUs, int &argc, char *argv[])
{
	int num = -1;
	for (int i = 0; i < argc; i++)
	{
		std::string arg = argv[i];
		if (arg == "-c")
		{
			try
			{
				CPUs = std::stoi(argv[i + 1]);
			}
			catch (...)
			{
				num = 1;
				break;
			}
		}
		else if (arg == "-t")
		{
			try
			{
				secs = std::stoi(argv[i + 1]);
			}
			catch (...)
			{
				num = 1;
				break;
			}
		}
		else if (arg == "-v")
		{
			std::cout << "speedtest v" << VERSION << " on " << OS << std::endl;
			num = 0;
			break;
		}
		else if (arg == "-?")
		{
			num = 0;
			break;
		}
	}
	return num;
}

int main(int argc, char *argv[])
{
	int score = 0;
	int CPUs = std::thread::hardware_concurrency();
	if (CPUs == 0) CPUs = 2;
	int secs = 30;
	int returnNum = parseArgs(secs, CPUs, argc, argv);
	if (returnNum != -1 || CPUs < 1 || secs < 1)
	{
		std::cout << "Available arguments:" << std::endl;
		std::cout << "\t-c <amount> - Sets the amount of threads to use" << std::endl;
		std::cout << "\t-t <time>   - Sets the time in seconds for as long the test should run" << std::endl;
		std::cout << "\t-v          - Gives information about the current version" << std::endl;
		return returnNum;
	}

	std::cout << "Using " << CPUs << " Threads" << std::endl;
	std::cout << "Time: " << secs << " seconds" << std::endl;

	for (int i = -1; i < CPUs; i++)
	{
		std::thread thread_object(test, std::ref(score), get_seconds_since_epoch() + secs);
		thread_object.detach();
	}

	std::this_thread::sleep_for(std::chrono::seconds(secs));

	std::cout << "Score: " << score << std::endl;
	return 0;
}