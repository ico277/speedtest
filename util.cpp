#include <chrono>
#include <iostream>
#include <string>
#include "info.h"

decltype(std::chrono::seconds().count()) getTime()
{
    const auto now = std::chrono::system_clock::now();
    const auto epoch = now.time_since_epoch();
    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);
    return seconds.count();
}

void parseArgs(int &secs, int &CPUs, int &argc, char *argv[])
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
				std::cout << "Available arguments:" << std::endl;
				std::cout << "\t-c <amount> - Sets the amount of threads to use" << std::endl;
				std::cout << "\t-t <time>   - Sets the time in seconds for as long the test should run" << std::endl;
				std::cout << "\t-v          - Gives information about the current version" << std::endl;
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
				std::cout << "Available arguments:" << std::endl;
				std::cout << "\t-c <amount> - Sets the amount of threads to use" << std::endl;
				std::cout << "\t-t <time>   - Sets the time in seconds for as long the test should run" << std::endl;
				std::cout << "\t-v          - Gives information about the current version" << std::endl;
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
			std::cout << "Available arguments:" << std::endl;
			std::cout << "\t-c <amount> - Sets the amount of threads to use" << std::endl;
			std::cout << "\t-t <time>   - Sets the time in seconds for as long the test should run" << std::endl;
			std::cout << "\t-v          - Gives information about the current version" << std::endl;
			num = 0;
			break;
		}
	}
	if (num != -1) 
	{
		exit(num);
	}
	else if (CPUs < 1)
	{
		std::cout << "'" << CPUs << "' is an invalid amount!" << std::endl;
		exit(1);
	} 
	else if (secs < 1) 
	{
		std::cout << "'" << secs << "' is an invalid amount!" << std::endl;
		exit(1);
	}
}