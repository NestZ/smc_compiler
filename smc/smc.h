#include "../compiler/compiler.h"
#include "register.h"
#include "memory.h"

class SMC{
	public:
		SMC(){}
		Compiler compiler;
		Memory memory;
		Register registers;
		void run(){}
		void reset(){}
};
