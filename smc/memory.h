class Memory{
	public:
		//TODO add dynamic size
		Memory(){}
		void reset(){}
		void set(){}
		void get(){}
	private:
		const int MAX_MEMORY_SIZE = (1 << 16);
		vector<int> memory_lst = vector<int>(MAX_MEMORY_SIZE, 0);
};
