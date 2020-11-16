class Register{
	public:
		//TODO add dynamic size
		Register(){}
		void reset(){
			register_lst.clear();
		}
		void set(int register_no, int value){
			if(register_no == 0)return;
			this->register_lst[register_no] = value;
		}
		int get(int register_no){
			return register_lst[register_no];
		}
	private:
		const int MAX_REGISTER_SIZE = 8;
		vector<int> register_lst = vector<int>(MAX_REGISTER_SIZE, 0);
};
