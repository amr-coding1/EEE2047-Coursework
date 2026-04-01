#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class Command {
protected:
    float value;
public:
    Command() : value(0) {}
    virtual ~Command() {}
    virtual void run() = 0;
};

#endif
