#include "../compiler/compiler.h"
#include "register.h"
#include "memory.h"
#include "./simulator/simulator.h"

class SMC{
	public:
		SMC(){}
		Compiler compiler;
		Memory memory;
		Register registers;
		Simulator simulator;

		void run(){}
		void reset(){}
		
};
