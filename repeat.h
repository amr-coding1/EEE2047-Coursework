#ifndef REPEAT_H
#define REPEAT_H

#include "command.h"
#include "program.h"

class Repeat : public Command {
private:
    Program prg;
public:
    void run();
    friend std::istream& operator>>(std::istream& is, Repeat& r);
};

#endif
