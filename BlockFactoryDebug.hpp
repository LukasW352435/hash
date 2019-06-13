//
// Created by lukas on 6/13/19.
//

#ifndef HASH_BLOCKFACTORYDEBUG_HPP
#define HASH_BLOCKFACTORYDEBUG_HPP

#include "BlockFactory.hpp"

class BlockFactoryDebug : public BlockFactory {
public:
    BlockFactoryDebug(std::string message);
};


#endif //HASH_BLOCKFACTORYDEBUG_HPP
