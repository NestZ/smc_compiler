class Interpreter{
	private:
		int OPCODE_ADD = 0;
		int OPCODE_NAND = 1;
		int OPCODE_LW = 2;
		int OPCODE_SW = 3;
		int OPCODE_BEQ = 4;
		int OPCODE_JALR = 5;
		int OPCODE_HALT = 6;
		int OPCODE_NOOP = 7;
		vector<int> binary;
		/*
		* map label to (address, value))
		*/
		map<string, pair<int, int>> label;

	public:
		Interpreter(){}

		void map_label(vector<AST::instr> &ast_instr){
			int cur_address = 0;
			for(AST::instr instr : ast_instr){
				if(instr.label != "null"){
					int value = 0;
					if(instr.name == ".fill" && instr.type == Lexer::TokenType::F_TYPE)
						value = stoi(instr.operand[0].first);
					label[instr.label] = make_pair(cur_address, value);
				}
				cur_address++;
			}
		}

		int interpret_r_type(AST::instr &instr){
			int cur_bin = 0;
			if(instr.name == "add")
				cur_bin |= (OPCODE_ADD << 24);
			else if(instr.name == "nand")
				cur_bin |= (OPCODE_NAND << 24);
			cur_bin |= stoi(instr.operand[2].first);
			cur_bin |= (stoi(instr.operand[0].first) << 21);
			cur_bin |= (stoi(instr.operand[1].first) << 18);
			return cur_bin;
		}

		int interpret_i_type(AST::instr &instr){
			return 0;
		}

		int interpret_j_type(AST::instr &instr){
			return 0;
		}

		int interpret_o_type(AST::instr &instr){
			int cur_bin = 0;
			if(instr.name == "halt")
				cur_bin |= (OPCODE_HALT << 24);
			else if(instr.name == "noop")
				cur_bin |= (OPCODE_NOOP << 24);
			return cur_bin;
		}

		int interpret_f_type(AST::instr &instr){
			return 0;
		}

		vector<int> *interpret(vector<AST::instr> &ast_instr){
			for(AST::instr instr : ast_instr){
				if(instr.type == Lexer::TokenType::R_TYPE)
					this->binary.push_back(this->interpret_r_type(instr));
				else if(instr.type == Lexer::TokenType::I_TYPE)
					this->binary.push_back(this->interpret_i_type(instr));
				else if(instr.type == Lexer::TokenType::J_TYPE)
					this->binary.push_back(this->interpret_j_type(instr));
				else if(instr.type == Lexer::TokenType::O_TYPE)
					this->binary.push_back(this->interpret_o_type(instr));
				else if(instr.type == Lexer::TokenType::F_TYPE)
					this->binary.push_back(this->interpret_f_type(instr));
			}
			return &this->binary;
		}
};
