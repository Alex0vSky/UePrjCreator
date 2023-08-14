#pragma once
// minimum operating system version your code supports: Windows XP
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#include <sdkddkver.h>
// disable min and max macros
#define NOMINMAX
// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <locale>
#include <string>
#include <map>
#include <vector>
#include <optional>
#include <fstream>
#include <random>
