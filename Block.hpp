//
// Created by lukas on 6/10/19.
//

#ifndef HASH_BLOCK_HPP
#define HASH_BLOCK_HPP

#include <array>
#include <iostream>
#include <string>
#include <iomanip>

class Block {
private:
    std::array<ushort,32> words;
public:
    Block();
    Block(std::array<ushort,32> words);
    Block(std::string message);
    friend std::ostream& operator<< (std::ostream& os, const Block& block);
    void addSize(ulong size);
};

#endif //HASH_BLOCK_HPP
