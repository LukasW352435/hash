//
// Created by lukas on 6/13/19.
//

#include "SHA1Debug.hpp"
#include "BlockFactory.hpp"

using namespace std;

SHA1Debug::SHA1Debug(std::string message) : SHA1() {
    BlockFactory b = BlockFactory(message);
    list<Block> blocks = b.getBlocks();
    createHash(&blocks);
}
SHA1Debug::SHA1Debug(std::list<Block> *blocks) : SHA1(){
    createHash(blocks);
}

void SHA1Debug::printX(std::array<uint,80> *x) {
    cout << "X" << endl;
    for(int i=0;i<80;i++){
        cout << setfill('0') << setw(8) << hex << (*x)[i] << "\t";
        if(i==19||i==39||i==59||i==79){
            cout << endl;
        }
    }
}
void SHA1Debug::printH() {
    cout << "H1 H2 H3 H4 H5" << endl;
    cout << setfill('0') << setw(8) << hex << h1 << "\t";
    cout << setfill('0') << setw(8) << hex << h2 << "\t";
    cout << setfill('0') << setw(8) << hex << h3 << "\t";
    cout << setfill('0') << setw(8) << hex << h4 << "\t";
    cout << setfill('0') << setw(8) << hex << h5 << endl;
}
void SHA1Debug::printA() {
    cout << "A B C D E" << endl;
    cout << setfill('0') << setw(8) << hex << a << "\t";
    cout << setfill('0') << setw(8) << hex << b << "\t";
    cout << setfill('0') << setw(8) << hex << c << "\t";
    cout << setfill('0') << setw(8) << hex << d << "\t";
    cout << setfill('0') << setw(8) << hex << e << endl;
}
void SHA1Debug::createHash(std::list<Block> *blocks) {
    for(auto const& block :*blocks){
        cout << "Block" << endl;
        cout << block;

        // init a,b,c,d,e
        cout << "Init" << endl;
        printH();
        printA();
        a = h1;
        b = h2;
        c = h3;
        d = h4;
        e = h5;
        printA();

        // assign x
        cout << "Assign x" << endl;
        array<uint, 80> x = {0};
        array<uint, 16> words = block.getWords();
        for(int i=0;i<16;i++){
            x[i] = words[i];
        }
        printX(&x);

        // expand x
        cout << "Expand x" << endl;
        expansion(&x);
        printX(&x);

        // round 1,2,3,4
        cout << "Round 1" << endl;
        round1(&x);
        printA();
        printX(&x);
        cout << "Round 2" << endl;
        round2(&x);
        printA();
        printX(&x);
        cout << "Round 3" << endl;
        round3(&x);
        printA();
        printX(&x);
        cout << "Round 4" << endl;
        round4(&x);
        printA();
        printX(&x);

        // new h
        cout << "New h" << endl;
        h1 += a;
        h2 += b;
        h3 += c;
        h4 += d;
        h5 += e;
        printH();
    }
}