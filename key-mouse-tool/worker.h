#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include "hook.h"

class worker : public QThread
{
    Q_OBJECT

public:
    worker(QObject *parent = 0);
    void run();
    unsigned int tid;
//signals:
//    void threadSignal();
};

#endif // WORKER_H
