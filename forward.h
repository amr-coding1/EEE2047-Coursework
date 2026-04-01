#ifndef FORWARD_H
#define FORWARD_H

#include "command.h"

class Forward : public Command {
public:
    void run();
    friend std::istream& operator>>(std::istream& is, Forward& f);
};

#endif
