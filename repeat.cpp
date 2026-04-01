#include "repeat.h"
#include <string>

void Repeat::run() {
    for (int i(0); i < (int)value; i++) {
        prg.run();
    }
}

std::istream& operator>>(std::istream& is, Repeat& r) {
    is >> r.value;
    std::string bracket;
    is >> bracket;
    if (bracket != "[") {
        std::cerr << "Error: expected '[' after REPEAT count" << std::endl;
        return is;
    }
    is >> r.prg;
    return is;
}
