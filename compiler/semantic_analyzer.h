class SemanticAnalyzer{
	private:
		set<string> label;

	public:
		SemanticAnalyzer(){}

		void analyze(vector<AST::instr> &ast_instr){
			for(AST::instr instr : ast_instr){
				if(instr.label != "null"){
					if(this->label.count(instr.label) > 0)
						throw "Semantic Error! - Label with same name";
					this->label.insert(instr.label);
				}
			}
			for(AST::instr instr : ast_instr){
				for(pair<string, Lexer::TokenType> p : instr.operand){
					if(p.second == Lexer::TokenType::LABEL){
						if(this->label.count(p.first) == 0)
							throw "Semantic Error! - Undefined Label";
					}
				}
			}
		}
};
