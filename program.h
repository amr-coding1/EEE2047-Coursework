#ifndef PROGRAM_H
#define PROGRAM_H

#include "command.h"
#include <vector>

class Program {
private:
    std::vector<Command*> cmds;
public:
    ~Program();
    void run();
    friend std::istream& operator>>(std::istream& is, Program& p);
};

#endif
