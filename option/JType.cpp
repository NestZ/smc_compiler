#include <bits/stdc++.h>
#include <iostream>
using namespace std;

 int32_t J_Type (string sOp, int32_t iRs, int32_t iRd) {

    int32_t opcode = 5;
    int32_t sum = 0;


   if (sOp == "jalr")
   {
     sum = (opcode << 22) + (iRs << 19) + (iRd << 16);
     cout << sum;
   }
   return sum;
   return 0;
  }

 int main(int argc, char const *argv[])
 {
  J_Type("jalr",5,5);
   return 0;
 }
 