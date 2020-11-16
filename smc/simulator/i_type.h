class I_Type{
    public:
    void lw(int rA, int rB, int16_t offsetv, Register &reg, Memory &mem){
        reg.set(rB,mem.get(reg.get(rA) + offsetv));
    }
    void sw(int rA, int rB, int16_t offsetv, Register &reg, Memory &mem){
        mem.set(reg.get(rA) + offsetv,reg.get(rB));
    }
    void beq(int rA, int rB, int16_t offsetv, Register &reg, int &PC){
        if (reg.get(rA) == reg.get(rB))
        PC +=  offsetv;
    }
};
