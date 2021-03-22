#pragma once

#define VERSION "0.0.3-BETA"
#ifdef __linux__
#define OS "Linux"
#elif __FreeBSD__
#define OS "FreeBSD"
#else
#define OS "Unrecognised OS"
#endif