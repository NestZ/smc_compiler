#include "../compiler/compiler.h"
#include "register.h"
#include "memory.h"
#include "./simulator/simulator.h"

class SMC{
	private:
		Compiler compiler;
		Memory memory;
		Register registers;
		Simulator simulator;

	public:
		SMC(){}

		void run(){
			this->reset();
			this->compiler.read_source_code();
			vector<int> binary = *this->compiler.compile();
			simulator.simulate(registers,memory,binary,0,8);
			
		}

		void reset(){
			this->memory.reset();
			this->registers.reset();
		}
};
