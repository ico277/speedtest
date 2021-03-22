#pragma once

#define VERSION "0.1.0-BETA"
#ifdef __linux__
#define OS "Linux"
#elif __FreeBSD__
#define OS "FreeBSD"
#else
#define OS "Unrecognised OS"
#endif