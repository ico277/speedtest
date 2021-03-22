#pragma once
#include <chrono>

decltype(std::chrono::seconds().count()) getTime();
void parseArgs(int &secs, int &CPUs, int &argc, char *argv[]);
unsigned long long int factorial(unsigned long long int n);
bool isPrime(long n);