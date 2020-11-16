class Memory{
	public:
		//TODO add dynamic size
		Memory(){}
		void reset(){
			memory_lst.clear();
		}
		void set(int memory_no, int value){
			memory_lst.at(memory_no) = value;
		}
		int get(int memory_no){
			return memory_lst[memory_no];
		}
	private:
		const int MAX_MEMORY_SIZE = (1 << 16);
		vector<int> memory_lst = vector<int>(MAX_MEMORY_SIZE, 0);
};
