//
// Created by lukas on 6/10/19.
//

#include "BlockFactory.hpp"

using namespace std;

BlockFactory::BlockFactory(std::string message) {
    ulong size = message.length();
    ulong pos = 0;
    string substring;
    Block block;
    do{
        substring = message.substr(pos,64);
        block = Block(substring);
        blocks.push_back(block);
        pos+=64;
    }while (pos<size);
    if(substring.length()<56)
    {
        block.appendOne(size%64);
        block.addSize(size*8);
        blocks.pop_back();
        blocks.push_back(block);
    }else if(substring.length()<64){
        block.appendOne(size%64);
        blocks.pop_back();
        blocks.push_back(block);
        block = Block();
        block.addSize(size*8);
        blocks.push_back(block);
    } else{
        block = Block();
        block.appendOne(0);
        block.addSize(size*8);
        blocks.push_back(block);
    }
}

ostream& operator<<(ostream& os, const BlockFactory& blockFactory) {
    for(auto const& i : blockFactory.blocks){
        os << i << endl;
    }
    return os;
}

ulong BlockFactory::size() {
    return blocks.size();
}
list<Block> BlockFactory::getBlocks() {
    return blocks;
}