class Register{
	public:
		//TODO add dynamic size
		Register(){}
		void reset(){}
		void set(int register_no, int value){}
		int get(int register_no){
			return register_lst.at(register_no);
		}
	private:
		const int MAX_REGISTER_SIZE = 8;
		vector<int> register_lst = vector<int>(MAX_REGISTER_SIZE, 0);
};
