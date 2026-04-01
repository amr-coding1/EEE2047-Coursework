#ifndef LEFT_H
#define LEFT_H

#include "command.h"

class Left : public Command {
public:
    void run();
    friend std::istream& operator>>(std::istream& is, Left& l);
};

#endif
