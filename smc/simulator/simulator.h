#include "i_type.h"
#include "r_type.h"
#include "j_type.h"
#include "o_type.h"

class Simulator{
	public:
		Simulator(){}
		R_Type r_type;
		I_Type i_type;
        J_Type j_type;
		O_Type o_type;
		void simulate(Register &smc_reg,Memory &smc_mem,vector<int> instruction_set,int mem_start,int mem_stop);
};

void Simulator:: simulate(Register &smc_reg,Memory &smc_mem,vector<int> instruction_set,int mem_start,int mem_stop){
	int pc = mem_start;
	int total_instruction = 0;
    bool running = true;
    int temp_for_op = 0;
    
    for (int i = 0; i < 100 ; i++)
    {
        cout << "this is smc_mem [ " << i << " ]" << " " <<smc_mem.get(i) << endl;
    }
    

	while(running && pc < mem_stop){
		int inst = instruction_set[pc];
        temp_for_op = inst >> 22;
        temp_for_op = temp_for_op%8;

		switch(temp_for_op){
            case 0:
                r_type.add((inst >> 19)%8,(inst>>16)%8,inst%8,&smc_reg);
            break;
            case 1:
                r_type.nand((inst >> 19)%8,(inst>>16)%8,inst%8,smc_reg);
            break;
            case 2:
                i_type.lw((inst >> 19)%8, (inst>>16)%8, (inst & ((1 << 16) - 1)), smc_reg ,smc_mem,pc);
            break;
            case 3:
                i_type.sw((inst >> 19)%8, (inst>>16)%8, (inst & ((1 << 16) - 1)), smc_reg ,smc_mem,pc);
            break;
            case 4:
                i_type.beq((inst >> 19)%8, (inst>>16)%8, (inst & ((1 << 16) - 1)), smc_reg, pc);
            break;
            // case 5:
            //     j_type.jalr((inst >> 19)%8,(inst>>16)%8,pc,smc_reg);
            // break;
            // case 6:
            //     running = false;
            // break;
            // case 7:
            //     pc--;
            // break;
        }

        total_instruction++;

		cout << "state:" << endl << "   PC " << std::to_string(pc) << endl << "    memory:" << endl;
        for(int i = mem_start ; i < mem_stop ;i++){
            cout << "       mem[ " << std::to_string(i) << " ] " << smc_mem.get(i) << endl;
        }
        cout << "   registers:" << endl;
        for(int i = 0 ; i<8 ; i++){
            cout << "       reg[ " << std::to_string(i) << " ] " << smc_reg.get(i) << endl;
        }
        cout << "end state" << endl;
        if(running == false){
            cout << "machine halted" << endl << "total of " << std::to_string(total_instruction) << " instructions executed" << endl << "final state of machine:";
        }
        pc++;
	}
}