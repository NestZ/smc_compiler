#include "../compiler/compiler.h"
#include "i_type.h"
#include "r_type.h"
#include "o_type.h"

class Simulator{
	public:
		Simulator(){}
		R_Type r_type = new R_Type();
		I_Type i_type = new I_Type();
		O_Type o_type = new o_type();
		void simulate(Register smc_reg,Memory smc_mem,Instruction[] instruction_set,int mem_start,int mem_stop);
};

void simulate(Register smc_reg,Memory smc_mem,Instruction[] instruction_set,int mem_start,int mem_stop){
	int pc = mem_start;
	int total_instruction = 0;
	Instruction inst = new Instruction();
	while(running){
		inst = instruction_set[pc];

		switch(temp_for_op){
            case 0:
                //goRtype
            break;
            case 1:
                //goRtype
            break;
            case 2:
                //goItype
            break;
            case 3:
                //goItype
            break;
            case 4:
                //goItype
            break;
            case 5:
                //goJtype
            break;
            case 6:
                running = false;
            break;
            case 7:

            break;
        }

		cout << "state:" << endl << "   PC " << tostring(PC) << endl << "    memory:" << endl;
        for(int i = mem_start ; i <= mem_stop ;i++){
            cout << "       mem[ " << tostring(i) << " ] " << smc_mem.get(i) << endl;
        }
        cout << "   registers:" << endl;
        for(int i = 0 ; i<8 ; i++){
            cout << "       reg[ " << tostring(i) << " ] " << smc_reg.get(i) << endl;
        }
        cout << "end state" << endl
        if(running == false){
            cout << "machine halted" << endl << "total of " << tostring(total_instruction) << " instructions executed" << endl << "final state of machine:";
        }


        total_instruction++;
        PC++;
	}
}