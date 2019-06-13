//
// Created by lukas on 6/13/19.
//

#ifndef HASH_SHA1DEBUG_HPP
#define HASH_SHA1DEBUG_HPP

#include "SHA1.hpp"

class SHA1Debug : public SHA1 {
private:
    void printX(std::array<uint,80> *x);
    void printH();
    void printA();
    void createHash(std::list<Block> *blocks);
public:
    SHA1Debug(std::string message);
    SHA1Debug(std::list<Block> *blocks);
};

#endif //HASH_SHA1DEBUG_HPP
