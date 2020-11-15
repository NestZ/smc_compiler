class Preprocessor{
	public:
		Preprocessor(){}

		string process(vector<string> &source_code){
			string res = "";
			for(string s : source_code){
				res += s;
				res += "\n";
			}
			return res;
		}
};
