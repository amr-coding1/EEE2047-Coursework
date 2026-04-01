#include "repeat.h"
#include "program.h"

void Program::run() {
	for (unsigned int i(0); i < cmds.size(); i++) {
		cmds[i]->run();
	}
}

std::istream& operator>>(std::istream& in, Program& prog)
{
	std::string token;
	while (in >> token) {
		if (token == "FORWARD") {
			Forward* cmd = new Forward();
			in >> *cmd;
			prog.cmds.push_back(cmd);
		} else if (token == "JUMP") {
			Jump* cmd = new Jump();
			in >> *cmd;
			prog.cmds.push_back(cmd);
		} else if (token == "LEFT") {
			Left* cmd = new Left();
			in >> *cmd;
			prog.cmds.push_back(cmd);
		} else if (token == "RIGHT") {
			Right* cmd = new Right();
			in >> *cmd;
			prog.cmds.push_back(cmd);
		} else if (token == "REPEAT") {
			Repeat* cmd = new Repeat();
			in >> *cmd;
			prog.cmds.push_back(cmd);
		} else if (token == "]") {
			return in;
		} else {
			std::cerr << "Error: unknown command '" << token << "'" << std::endl;
		}
	}
	return in;
}


Program::~Program()
{
	for (unsigned int i(0); i < cmds.size(); i++) {
		delete cmds[i];
	}
}
