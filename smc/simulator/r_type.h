#include "../compiler/compiler.h"

class R_Type{
  public:
    void add(int32_t rs, int32_t rt, int32_t rd , Register reg){
      int value;
      value = reg.get(rs) + reg.get(rt);
      reg.set(rd,reg.get(rs) + reg.get(rt));
    } 

    int nand(int32_t rs, int32_t rt, int32_t rd , Register reg){
      int value;
      value = (reg.get(rs)) & (reg.get(rt));
    }
};
