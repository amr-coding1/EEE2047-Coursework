#ifndef REPEAT_H_
#define REPEAT_H_

#include "command.h"
#include "program.h"

class Repeat : public Command {
public:
	void run();
	friend std::istream& operator>>(std::istream& in, Repeat& r);
private:
	Program prg;
};

std::istream& operator>>(std::istream& in, Repeat& r);

#endif /* REPEAT_H_ */
