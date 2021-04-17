#pragma once

#define VERSION "1.0.0-RELEASE"
#ifdef __linux__
#define OS "Linux"
#elif __FreeBSD__
#define OS "FreeBSD"
#else
#define OS "Unrecognised OS"
#endif