#ifndef JUMP_H
#define JUMP_H

#include "command.h"

class Jump : public Command {
public:
    void run();
    friend std::istream& operator>>(std::istream& is, Jump& j);
};

#endif
