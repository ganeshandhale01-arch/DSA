void (*signal(int, (*new_handler)(int))(int); 

typedef void(*sighandler_t)(int); 

typedef     void(*)(int)    sighandler_t;   // NO ERROR

sighandler_t signal(int signum, sighandler_t new_handler); 