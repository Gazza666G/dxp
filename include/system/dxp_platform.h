#pragma once

#ifdef _WIN32
	#define DXP_SYS_WINDOWS
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif
#elif defined(__linux__)
	#define DXP_SYS_LINUX
#elif defined(__APPLE__)
	#define DXP_SYS_MACOS
#else
	#error System is not supported by DXP
#endif

#ifndef DXP_IMPORT
	#ifdef DXP_SYS_WINDOWS
		#define DXP_IMPORT __declspec(dllimport)
	#else
		#define DXP_IMPORT __attribute__ ((__visibility__("default")))
	#endif
#endif

#ifndef DXP_EXPORT
	#ifdef DXP_SYS_WINDOWS
		#define DXP_EXPORT __declspec(dllexport)
	#else
		#define DXP_EXPORT __attribute__ ((__visibility__("default")))
	#endif
#endif

#ifndef DXP_STATIC
	#ifdef DXP_SYS_WINDOWS
		#ifdef DXP_NONCLIENT_BUILD
			#ifndef DXP_API
				#define DXP_API __declspec(dllexport)
			#endif
		#else
			#ifndef DXP_API
				#define DXP_API __declspec(dllimport)
			#endif
		#endif

		//Visual c++ compiler warning C4251 disable
		//#ifdef _MSC_VER
		//	#pragma warning(disable : 4251)
		//#endif
	#else //Linux and MAC OS X
		#if __GNUC__ >= 4
			#define DXP_API __attribute__ ((__visibility__("default")))
		#else
			#define DXP_API
		#endif
	#endif
#else
	#define DXP_API
#endif

/*BYTE define for non Windows platforms*/
#ifndef DXP_SYS_WINDOWS
	typedef unsigned char BYTE;
#endif

#ifndef DXP_BUFSIZE
	#define DXP_BUFSIZE 1024
#endif

#ifndef DXP_LARGE_BUFSIZE
	#define DXP_LARGE_BUFSIZE 10240
#endif