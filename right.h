#ifndef RIGHT_H
#define RIGHT_H

#include "command.h"

class Right : public Command {
public:
    void run();
    friend std::istream& operator>>(std::istream& is, Right& r);
};

#endif
