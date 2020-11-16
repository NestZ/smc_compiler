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
		map<string, int> label;

	public:
		Interpreter(){}

		bool isInt16(int n){
			if(n > INT16_MAX || n < INT16_MIN)return false;
			return true;
		}

		int to_int16(int n){
			return (n & ((1 << 16) - 1));
		}

		void map_label(vector<AST::instr> &ast_instr){
			int len = ast_instr.size();
			for(int i = 0;i < len;i++){
				if(ast_instr[i].label != "null")
					label[ast_instr[i].label] = i;
			}
		}

		int interpret_r_type(AST::instr &instr){
			int cur_bin = 0;
			if(instr.name == "add")
				cur_bin |= (OPCODE_ADD << 22);
			else if(instr.name == "nand")
				cur_bin |= (OPCODE_NAND << 22);
			cur_bin |= stoi(instr.operand[2].first);
			cur_bin |= (stoi(instr.operand[0].first) << 19);
			cur_bin |= (stoi(instr.operand[1].first) << 16);
			return cur_bin;
		}

		int interpret_i_type(AST::instr &instr, int pc){
			int cur_bin = 0;
			if(instr.name == "lw")
				cur_bin |= (OPCODE_LW << 22);
			else if(instr.name == "sw")
				cur_bin |= (OPCODE_SW << 22);
			else if(instr.name == "beq")
				cur_bin |= (OPCODE_BEQ << 22);
			cur_bin |= (stoi(instr.operand[0].first) << 19);
			cur_bin |= (stoi(instr.operand[1].first) << 16);
			if(instr.operand[2].second == Lexer::TokenType::LABEL){
				int symbolic_line = label[instr.operand[2].first];
				if(!isInt16(symbolic_line))throw "too large offSet";
				if(instr.name == "beq")
					cur_bin |= to_int16(symbolic_line - pc - 1);
				else cur_bin |= to_int16(symbolic_line);
			}
			else if(instr.operand[2].second == Lexer::TokenType::INT){
				int offSet = stoi(instr.operand[2].first);
				if(!isInt16(offSet))throw "too large offSet!";
				cur_bin |= to_int16(offSet);
			}
			return cur_bin;
		}

		int interpret_j_type(AST::instr &instr){
			int cur_bin = 0;
			cur_bin |= (OPCODE_JALR << 22);
			cur_bin |= (stoi(instr.operand[0].first) << 19);
			cur_bin |= (stoi(instr.operand[1].first) << 16);
			return cur_bin;
		}

		int interpret_o_type(AST::instr &instr){
			int cur_bin = 0;
			if(instr.name == "halt")
				cur_bin |= (OPCODE_HALT << 22);
			else if(instr.name == "noop")
				cur_bin |= (OPCODE_NOOP << 22);
			return cur_bin;
		}

		int interpret_f_type(AST::instr &instr){
			int cur_bin = 0;
			if(instr.operand[0].second == Lexer::TokenType::LABEL)
				cur_bin = label[instr.operand[0].first];
			else if(instr.operand[0].second == Lexer::TokenType::INT)
				cur_bin = stoi(instr.operand[0].first);
			return cur_bin;
		}

		vector<int> *interpret(vector<AST::instr> &ast_instr){
			map_label(ast_instr);
			int pc = 0;
			for(AST::instr instr : ast_instr){
				if(instr.type == Lexer::TokenType::R_TYPE)
					this->binary.push_back(this->interpret_r_type(instr));
				else if(instr.type == Lexer::TokenType::I_TYPE)
					this->binary.push_back(this->interpret_i_type(instr, pc));
				else if(instr.type == Lexer::TokenType::J_TYPE)
					this->binary.push_back(this->interpret_j_type(instr));
				else if(instr.type == Lexer::TokenType::O_TYPE)
					this->binary.push_back(this->interpret_o_type(instr));
				else if(instr.type == Lexer::TokenType::F_TYPE)
					this->binary.push_back(this->interpret_f_type(instr));
				pc++;
			}
			return &this->binary;
		}
};
