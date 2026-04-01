#include "program.h"
#include "forward.h"
#include "jump.h"
#include "left.h"
#include "right.h"
#include "repeat.h"
#include <string>

Program::~Program() {
    for (unsigned int i(0); i < cmds.size(); i++) {
        delete cmds[i];
    }
}

void Program::run() {
    for (unsigned int i(0); i < cmds.size(); i++) {
        cmds[i]->run();
    }
}

std::istream& operator>>(std::istream& is, Program& p) {
    std::string token;
    while (is >> token) {
        if (token == "FORWARD") {
            Forward* cmd = new Forward();
            is >> *cmd;
            p.cmds.push_back(cmd);
        } else if (token == "JUMP") {
            Jump* cmd = new Jump();
            is >> *cmd;
            p.cmds.push_back(cmd);
        } else if (token == "LEFT") {
            Left* cmd = new Left();
            is >> *cmd;
            p.cmds.push_back(cmd);
        } else if (token == "RIGHT") {
            Right* cmd = new Right();
            is >> *cmd;
            p.cmds.push_back(cmd);
        } else if (token == "REPEAT") {
            Repeat* cmd = new Repeat();
            is >> *cmd;
            p.cmds.push_back(cmd);
        } else if (token == "]") {
            return is;
        } else {
            std::cerr << "Error: unknown command '" << token << "'" << std::endl;
        }
    }
    return is;
}
