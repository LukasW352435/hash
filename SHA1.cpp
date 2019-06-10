//
// Created by lukas on 6/10/19.
//

#include <climits>
#include "BlockFactory.hpp"
#include "SHA1.hpp"

using namespace std;

SHA1::SHA1(std::string message) {
    BlockFactory b = BlockFactory(message);
    list<Block> blocks = b.getBlocks();
    createHash(&blocks);
}
SHA1::SHA1(std::list<Block> *blocks) {
    createHash(blocks);
}

ostream& operator<<(ostream& os, const SHA1& sha1) {
    os << setfill('0') << setw(8) << hex <<sha1.h1 << sha1.h2 << sha1.h3 << sha1.h4 << sha1.h5;
    return os;
}

uint SHA1::f(uint u, uint v, uint w) {
    return (u & v) | ((~u) & w);
}
uint SHA1::g(uint u, uint v, uint w) {
    return (u & v) | (u & w) | (v & w);
}
uint SHA1::h(uint u, uint v, uint w) {
    return u ^ v ^ w;
}
void SHA1::expansion(std::array<uint, 80> *x) {
    for(int i=16;i<80;i++){
        (*x)[i] = rotateLeft(((*x)[i-3] ^ (*x)[i-8] ^ (*x)[i-14] ^ (*x)[i-16]),1);
    }
}
void SHA1::round1(std::array<uint, 80> *x) {
    for(int i=0;i<20;i++){
        uint t = rotateLeft(a,5) + f(b,c,d) + e + (*x)[i] + y1;
        e = d;
        d = c;
        c = rotateLeft(b,30);
        b = a;
        a = t;
    }
}
void SHA1::round2(std::array<uint, 80> *x) {
    for(int i=20;i<40;i++){
        uint t = rotateLeft(a,5) + h(b,c,d) + e + (*x)[i] + y2;
        e = d;
        d = c;
        c = rotateLeft(b,30);
        b = a;
        a = t;
    }
}
void SHA1::round3(std::array<uint, 80> *x) {
    for(int i=40;i<60;i++){
        uint t = rotateLeft(a,5) + g(b,c,d) + e + (*x)[i] + y3;
        e = d;
        d = c;
        c = rotateLeft(b,30);
        b = a;
        a = t;
    }
}
void SHA1::round4(std::array<uint, 80> *x) {
    for(int i=60;i<80;i++){
        uint t = rotateLeft(a,5) + h(b,c,d) + e + (*x)[i] + y4;
        e = d;
        d = c;
        c = rotateLeft(b,30);
        b = a;
        a = t;
    }
}
void SHA1::createHash(std::list<Block> *blocks) {
    for(auto const& block :*blocks){
        // init a,b,c,d,e
        a = h1;
        b = h2;
        c = h3;
        d = h4;
        e = h5;

        // assign x
        array<uint, 80> x = {0};
        array<uint, 16> words = block.getWords();
        for(int i=0;i<16;i++){
            x[i] = words[i];
        }

        // expand x
        expansion(&x);

        // round 1,2,3,4
        round1(&x);
        round2(&x);
        round3(&x);
        round4(&x);

        // new h
        h1 += a;
        h2 += b;
        h3 += c;
        h4 += d;
        h5 += e;
    }
}

uint SHA1::rotateLeft(uint value, uint n){
    const unsigned int mask = (CHAR_BIT*sizeof(value) - 1);
    n &= mask;
    return (value<<n) | (value>>( (-n)&mask ));
}
