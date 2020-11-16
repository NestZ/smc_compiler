#include <iostream>
#include <string>
using namespace std;

int32_t r_type(string type,int32_t rd,int32_t rt,int32_t rs){
    int32_t sum = 0;
    sum = rd + (rt << 16) + (rs << 19);
    if(type == "add"){
        
    }else if(type == "nand"){
        int32_t temp = 1;
        temp = temp << 22;
        sum += temp;
    }else{
        return 0;
    }
    cout << sum << endl;
    return sum;
}

int main(){
    int32_t x = 0;
    x = r_type("add",1,2,1);
    cout << x << endl;
    cout << ~(3&5);
}