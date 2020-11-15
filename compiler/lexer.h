class Lexer{
	private:
		set<string> r_types;
		set<string> i_types;
		set<string> o_types;
		set<string> j_types;
		set<string> f_types;

	public:
		enum TokenType{
			R_TYPE,
			I_TYPE,
			O_TYPE,
			J_TYPE,
			F_TYPE,
			INT,
			LABEL,
			ENDL
		};
		vector<pair<string, TokenType>> lexical_tokens;

		Lexer(){
			string r_type[] = {"add", "nand"};
			string i_type[] = {"lw", "sw", "beq"};
			string o_type[] = {"halt", "noop"};
			string j_type[] = {"jalr"};
			string f_type[] = {".fill"};
			insert_to_set(r_types, r_type, 2);
			insert_to_set(i_types, i_type, 3);
			insert_to_set(o_types, o_type, 2);
			insert_to_set(j_types, j_type, 1);
			insert_to_set(f_types, f_type, 1);
		}

		void insert_to_set(set<string> &s, string arr[], int len){
			s.insert(arr, arr + len);
		}

		bool isNumber(string s){
			try{
				stoi(s);
				if(s[0] == '0' && s.length() > 1)return false;
			}
			catch(...){
				return false;
			}
			return true;
		}

		vector<pair<string, TokenType>> *tokenize(vector<string> &str){
			this->lexical_tokens.clear();
			for(string token : str){
				if(token == "\\n"){
					this->lexical_tokens.push_back(make_pair(token, ENDL));
					continue;
				}
				if(isNumber(token)){
					this->lexical_tokens.push_back(make_pair(token, INT));
				}
				else if(this->r_types.count(token) > 0){
					this->lexical_tokens.push_back(make_pair(token, R_TYPE));
				}
				else if(this->i_types.count(token) > 0){
					this->lexical_tokens.push_back(make_pair(token, I_TYPE));
				}
				else if(this->o_types.count(token) > 0){
					this->lexical_tokens.push_back(make_pair(token, O_TYPE));
				}
				else if(this->j_types.count(token) > 0){
					this->lexical_tokens.push_back(make_pair(token, J_TYPE));
				}
				else if(this->f_types.count(token) > 0){
					this->lexical_tokens.push_back(make_pair(token, F_TYPE));
				}
				else{
					this->lexical_tokens.push_back(make_pair(token, LABEL));
				}
			}
			return &this->lexical_tokens;
		}
};
