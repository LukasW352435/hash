#include <iostream>
#include <array>
#include "BlockFactory.hpp"

#define AAA_64 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
#define AA_16 "aaaaaaaaaaaaaaaa"

using namespace std;

int main() {
    string message;
    for(int i=0;i<2;i++){
        message+=AAA_64;
    }
    message+=AA_16;

    BlockFactory b = BlockFactory(message);

    cout << b <<endl;
    cout << "Size: " << b.size() << endl;
}
