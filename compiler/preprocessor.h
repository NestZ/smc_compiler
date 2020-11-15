class Preprocessor{
	private:
		vector<string> process_str;

	public:
		Preprocessor(){}

		vector<string> *process(vector<string> &source_code){
			for(string line : source_code){
				istringstream iss(line);
				string word;
				while(iss >> word)this->process_str.push_back(word);
				this->process_str.push_back("\n");
			}
			return &this->process_str;
		}
};
