#include<bits/stdc++.h>
using namespace std;
#include "./smc/smc.h"

int main(int argc, char *argv[]){
	if(argc != 2){
		cout << "Invalid arguments!\n";
		return 1;
	}

	const char *inFileStr = argv[1];
	if(freopen(inFileStr, "r", stdin) == NULL){
		cout << "Error in opening " << inFileStr << endl;
		return 1;
	}

	try{
		SMC smc;
		smc.run();
	}
	catch(const char *err){
		cout << "Exception: " << err << endl;
		return 1;
	}
}
