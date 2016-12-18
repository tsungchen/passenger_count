#ifndef _PASSENGER_STAT_DEF_H
#define _PASSENGER_STAT_DEF_H

#if (defined WIN32 || defined _WIN32 || defined WINCE || defined __CYGWIN__) && defined PASSEGER_API_EXPORT
#  define PASSEGER_EXPORTS __declspec(dllexport)
#elif defined __GNUC__ && __GNUC__ >= 4
#  define PASSEGER_EXPORTS __attribute__ ((visibility ("default")))
#else
#  define PASSEGER_EXPORTS
#endif




#endif