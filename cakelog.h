#include <sys/types.h>

int cakelog_initialise(const char *executable_name);
int cakelog_stop(void);
ssize_t cakelog(const char* msg_str, ...);
char * get_timestamp(void);

