#include <chrono>

decltype(std::chrono::seconds().count()) get_seconds_since_epoch()
{
    // get the current time
    const auto now = std::chrono::system_clock::now();

    // transform the time into a duration since the epoch
    const auto epoch = now.time_since_epoch();

    // cast the duration into seconds
    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);

    // return the number of seconds
    return seconds.count();
}