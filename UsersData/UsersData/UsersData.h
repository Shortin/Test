#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#pragma once
#include <iostream>
#include <string>

#ifdef USERDATA_EXPORTS
#define USERDATA_API __declspec(dllexport)
#else
#define USERDATA_API __declspec(dllimport)
#endif

extern "C" USERDATA_API int datausers(char* data);
