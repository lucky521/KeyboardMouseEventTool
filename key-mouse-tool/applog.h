#ifndef APPLOG_H
#define APPLOG_H
#include <stdio.h>
#include <ctime>

extern FILE *logfile;
int logstart();
int logstop();

#endif // APPLOG_H
