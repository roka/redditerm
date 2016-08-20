#ifdef DEBUG_MACRO
#define DEBUG(x, ...) fprintf(stderr, "DEBUG %s:%d " x "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define DEBUG(x, ...)
#endif


