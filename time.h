#pragma once
#include <chrono>

decltype(std::chrono::seconds().count()) get_seconds_since_epoch();