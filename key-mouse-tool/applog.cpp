#include "applog.h"

FILE *logfile;
int logstart()
{
    time_t nowtime;
    nowtime = time(NULL); //获取当前时间戳
    char filename[20];
    sprintf(filename, "log-%d.txt", nowtime);
    logfile = fopen(filename, "w");
    return 0;
}
int logstop()
{
    fclose(logfile);
    return 0;
}
