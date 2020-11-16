class R_Type{
  public:
    void add(int rs, int rt, int rd , Register *reg){
       cout << "This is rs" << " " <<rs << endl;
       cout << "This is rt" << " " <<rt << endl;
       cout << "This is rd" << " " <<rd << endl;
      int value;
      value = (*reg).get(rs) + (*reg).get(rt);
     
      (*reg).set(rd,value);
    } 

    void nand(int rs, int rt, int rd , Register &reg){
      int value;
      value =  ~(reg.get(rs) & reg.get(rt));
      reg.set(rd,value);
    }
};
