#pragma once
#include <chrono>

decltype(std::chrono::seconds().count()) getTime();
void parseArgs(int &secs, int &CPUs, int &argc, char *argv[]);