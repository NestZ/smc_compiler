class I_Type{
    public:
    void lw(int rA, int rB, int offsetv, Register &reg, Memory &mem, int &PC){
        reg.set(rB,mem.get(reg.get(rA) + offsetv));
        PC += 1;
    }
    void sw(int rA, int rB, int offsetv, Register &reg, Memory &mem, int &PC){
        mem.set(reg.get(rA) + offsetv,reg.get(rB));
        PC += 1;
    }
    void beq(int rA, int rB, int offsetv, Register &reg, int &PC){
        if (reg.get(rA) == reg.get(rB))
        PC += (1 + offsetv);
    else
        PC += 1;
    }
};
