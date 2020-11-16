#include "preprocessor.h"
#include "lexer.h"
#include "./ast/ast.h"
#include "semantic_analyzer.h"
#include "interpreter.h"

class Compiler{
	private:
		Preprocessor preprocessor;
		Lexer lexer;
		AST parser;
		SemanticAnalyzer semantic_analyzer;
		Interpreter interpreter;
		vector<string> source_code;

	public:
		Compiler(){}

		void read_source_code(){
			string temp;
			while(getline(cin, temp))
				this->source_code.push_back(temp);
		}

		vector<int> *compile(){
			vector<string> pre_str = *(this->preprocessor.process(source_code));
			queue<pair<string, Lexer::TokenType>> token = *lexer.tokenize(pre_str);
			this->parser = AST(&token);
			vector<AST::instr> ast_instr = *parser.parse();
			this->semantic_analyzer.analyze(ast_instr);
			return this->interpreter.interpret(ast_instr);
		}
};
