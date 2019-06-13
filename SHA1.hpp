//
// Created by lukas on 6/10/19.
//

#ifndef HASH_SHA1_HPP
#define HASH_SHA1_HPP

#include <list>
#include "Block.hpp"

class SHA1 {
protected:
    uint h1=0x67452301;
    uint h2=0xEFCDAB89;
    uint h3=0x98BADCFE;
    uint h4=0x10325476;
    uint h5=0xC3D2E1F0;
    const uint y1=0x5A827999;
    const uint y2=0x6ED9EBA1;
    const uint y3=0x8F1BBCDC;
    const uint y4=0xCA62C1D6;
    uint a=0,b=0,c=0,d=0,e=0;
    uint f(uint u,uint v,uint w);
    uint g(uint u,uint v,uint w);
    uint h(uint u,uint v,uint w);
    static void expansion(std::array<uint,80> *x);
    void round1(std::array<uint,80> *x);
    void round2(std::array<uint,80> *x);
    void round3(std::array<uint,80> *x);
    void round4(std::array<uint,80> *x);
    virtual void createHash(std::list<Block> *blocks);
    static uint rotateLeft(uint value, uint n);
public:
    SHA1();
    SHA1(std::string message);
    SHA1(std::list<Block> *blocks);
    friend std::ostream& operator<<(std::ostream& os,const SHA1& sha1);
};

#endif //HASH_SHA1_HPP
