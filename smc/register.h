class Register{
	public:
		//TODO add dynamic size
		Register(){}
		void reset(){}
		void set(){}
		void get(){}
	private:
		const int MAX_REGISTER_SIZE = 8;
		vector<int> register_lst = vector<int>(MAX_REGISTER_SIZE, 0);
};
