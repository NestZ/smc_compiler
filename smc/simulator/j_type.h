class J_Type{
  public:
    void jalr(int rs, int rd, int &pc, Register &reg){
      reg.set(rd,pc+1);
      pc = rs;
    }
};
