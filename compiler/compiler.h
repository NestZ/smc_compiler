#include "preprocessor.h"
#include "lexer.h"
#include "parser.h"
#include "semantic_analyzer.h"
#include "interpreter.h"

class Compiler{
	private:
		Preprocessor preprocessor;
		Lexer lexer;
		Parser parser;
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

		void compile(){
			string pre_str = this->preprocessor.process(source_code);
			cout << pre_str;
		}
};
