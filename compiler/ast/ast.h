class AST{
	private:
		queue<pair<string, Lexer::TokenType>> lexical_tokens;

	public:
		typedef struct instr{
			string label;
			string name;
			Lexer::TokenType type;
			vector<pair<string, Lexer::TokenType>> operand;
		}instr;
		vector<instr> instructions;

		AST(){}

		AST(queue<pair<string, Lexer::TokenType>> *lex_tokens){
			this->lexical_tokens = *lex_tokens;
		}

		instr parse_r(){
			instr cur_instruction = {"null", this->lexical_tokens.front().first, Lexer::TokenType::R_TYPE};
			this->lexical_tokens.pop();
			for(int i = 0;i < 3;i++){
				if(this->lexical_tokens.empty())throw "Syntax Error!";
				if(this->lexical_tokens.front().second != Lexer::TokenType::INT)throw "Syntax Error!";
				cur_instruction.operand.push_back(make_pair(this->lexical_tokens.front().first, this->lexical_tokens.front().second));
				this->lexical_tokens.pop();
			}
			return cur_instruction;
		}

		instr parse_i(){
			instr cur_instruction = {"null", this->lexical_tokens.front().first, Lexer::TokenType::I_TYPE};
			this->lexical_tokens.pop();	
			for(int i = 0;i < 3;i++){
				if(this->lexical_tokens.empty())throw "Syntax Error!";
				if(i < 2 && this->lexical_tokens.front().second != Lexer::TokenType::INT)throw "Syntax Error!";
				else if(i == 2 && this->lexical_tokens.front().second != Lexer::TokenType::INT &&
								this->lexical_tokens.front().second != Lexer::TokenType::LABEL)throw "Syntax Error!";
				cur_instruction.operand.push_back(make_pair(this->lexical_tokens.front().first, this->lexical_tokens.front().second));
				this->lexical_tokens.pop();
			}
			return cur_instruction;
		}

		instr parse_o(){
			instr cur_instruction = {"null", this->lexical_tokens.front().first, Lexer::TokenType::O_TYPE};
			this->lexical_tokens.pop();
			return cur_instruction;
		}

		instr parse_j(){
			instr cur_instruction = {"null", this->lexical_tokens.front().first, Lexer::TokenType::J_TYPE};
			this->lexical_tokens.pop();
			for(int i = 0;i < 2;i++){
				if(this->lexical_tokens.empty())throw "Syntax Error!";
				if(this->lexical_tokens.front().second != Lexer::TokenType::INT)throw "Syntax Error!";
				cur_instruction.operand.push_back(make_pair(this->lexical_tokens.front().first, this->lexical_tokens.front().second));
				this->lexical_tokens.pop();
			}
			return cur_instruction;
		}

		instr parse_f(){
			instr cur_instruction = {"null", this->lexical_tokens.front().first, Lexer::TokenType::J_TYPE};
			this->lexical_tokens.pop();
			if(this->lexical_tokens.empty())throw "Syntax Error!";
			if(this->lexical_tokens.front().second != Lexer::TokenType::INT &&
					this->lexical_tokens.front().second != Lexer::TokenType::LABEL)throw "Syntax Error!";
				cur_instruction.operand.push_back(make_pair(this->lexical_tokens.front().first, this->lexical_tokens.front().second));
			this->lexical_tokens.pop();
			return cur_instruction;
		}

		instr parse_label(){
			instr cur_instruction;
			string label = this->lexical_tokens.front().first;
			this->lexical_tokens.pop();
			if(this->lexical_tokens.front().second == Lexer::TokenType::R_TYPE)cur_instruction = parse_r();
			else if(this->lexical_tokens.front().second == Lexer::TokenType::I_TYPE)cur_instruction = parse_i();
			else if(this->lexical_tokens.front().second == Lexer::TokenType::O_TYPE)cur_instruction = parse_o();
			else if(this->lexical_tokens.front().second == Lexer::TokenType::J_TYPE)cur_instruction = parse_j();
			else if(this->lexical_tokens.front().second == Lexer::TokenType::F_TYPE)cur_instruction = parse_f();
			else throw "Syntax Error!";
			cur_instruction.label = label;
			return cur_instruction;
		}

		void parse_next_line(){
			while(this->lexical_tokens.front().second != Lexer::TokenType::ENDL)
				this->lexical_tokens.pop();
			this->lexical_tokens.pop();
		}

		vector<instr> *parse(){
			while(this->lexical_tokens.front().second == Lexer::TokenType::ENDL)this->lexical_tokens.pop();
			while(!this->lexical_tokens.empty()){
				pair<string, Lexer::TokenType> cur_token = this->lexical_tokens.front();
				if(cur_token.second == Lexer::TokenType::INT){
					throw "Syntax Error!";
				}
				if(cur_token.second == Lexer::TokenType::R_TYPE){
					this->instructions.push_back(parse_r());
				}
				else if(cur_token.second == Lexer::TokenType::I_TYPE){
					this->instructions.push_back(parse_i());
				}
				else if(cur_token.second == Lexer::TokenType::O_TYPE){
					this->instructions.push_back(parse_o());
				}
				else if(cur_token.second == Lexer::TokenType::J_TYPE){
					this->instructions.push_back(parse_j());
				}
				else if(cur_token.second == Lexer::TokenType::F_TYPE){
					this->instructions.push_back(parse_f());
				}
				else if(cur_token.second == Lexer::TokenType::LABEL){
					this->instructions.push_back(parse_label());
				}
				parse_next_line();
			}
			return &this->instructions;
		}
};
