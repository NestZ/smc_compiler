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
			this->reset();
			this->compiler.read_source_code();
			vector<int> binary = *this->compiler.compile();
			for(int i : binary)
				cout << i << endl;
		}

		void reset(){
			this->memory.reset();
			this->registers.reset();
		}
};
