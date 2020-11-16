#include "../compiler/compiler.h"
#include "./memory.h"
#include "./register.h"

class I_Type{
    public:
    void lw(int32_t rA, int32_t rB, int32_t offsetv, Register reg, Memory mem, int PC){
        reg.set(rB,mem.get(reg.get(rA) + offsetv));
        PC += 1;
    }
    void sw(int32_t rA, int32_t rB, int32_t offsetv, Register reg, Memory mem, int PC){
        mem.set(reg.get(rA) + offsetv,reg.get(rB));
        PC += 1;
    }
    void beq(int32_t rA, int32_t rB, int32_t offsetv, Register reg, int PC){
        if (reg.get(rA) == reg.get(rB))
        PC += (1 + offsetv);
    else
        PC += 1;
    }
};
