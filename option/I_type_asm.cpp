#include <bits/stdc++.h>
using namespace std;

int32_t reg[7];
int32_t Mem[65536];
int32_t PC;

class itest
{
public:
    int32_t regA;
    int32_t regB;
    int32_t osf;
};

int32_t itype_toasm(string inst, itest &x)
{
    int32_t opv, osfv; //opcode value and offset value
    if (inst == "lw")
        opv = 2;
    else if (inst == "sw")
        opv = 3;
    else if (inst == "beq")
        opv = 4;
    else
        return -1;

    if (x.osf < 0)
        osfv = (1 << 15) + x.osf + 32768;
    else
        osfv = x.osf;

    int32_t sum = (opv << 22) + (x.regA << 19) + (x.regB << 16) + osfv;

    return sum;
}

//010 8,388,608
//011 12,582,912
//100 16,777,216
//0000000 010 000 001 0000000000001000
//0000000 011 000 001 0000000000001000
//0000000 100 000 001 0000000000001000

int main()
{
    //test case worked out
    // itest a;
    // a.regA = 0;
    // a.regB = 1;
    // a.osf = 8;
    // cout << itype_toasm("lw", a) << endl;
    // cout << itype_toasm("sw", a) << endl;
    // cout << itype_toasm("beq", a) << endl;

    return 0;
}
