#include "preprocessor.h"
#include "lexer.h"
#include "parser.h"
#include "semantic_analyzer.h"
#include "interpreter.h"

class Compiler{
	public:
		Preprocessor preprocessor;
		Lexer lexer;
		Parser parser;
		SemanticAnalyzer semantic_analyzer;
		Interpreter interpreter;
		void compile(){}
};
