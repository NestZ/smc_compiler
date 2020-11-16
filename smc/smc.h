#include "../compiler/compiler.h"
#include "register.h"
#include "memory.h"
#include "./simulator/simulator.h"

class SMC{
	private:
		Compiler compiler;
		Memory memory;
		Register registers;

	public:
		SMC(){}

		void run(){
			this->compiler.read_source_code();
			this->compiler.compile();
		}

		void reset(){
			this->memory.reset();
			this->registers.reset();
		}
};
