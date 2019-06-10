//
// Created by lukas on 6/10/19.
//

#ifndef HASH_BLOCKFACTORY_HPP
#define HASH_BLOCKFACTORY_HPP

#include <list>
#include "Block.hpp"

class BlockFactory {
private:
    std::list<Block> blocks;
public:
    BlockFactory(std::string message);
    friend std::ostream& operator<< (std::ostream& os, const BlockFactory& BlockFactory);
    ulong size();
    std::list<Block> getBlocks();
};

#endif //HASH_BLOCKFACTORY_HPP
