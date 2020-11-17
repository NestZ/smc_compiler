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
			freopen("binary.out", "w", stdout);
			for(int i : binary)
				cout << i << endl;
			freopen("state.out", "w", stdout);
			simulator.simulate(registers, memory ,binary,compiler.ast_instr, 0, binary.size());
		}

		void reset(){
			this->memory.reset();
			this->registers.reset();
		}
};
