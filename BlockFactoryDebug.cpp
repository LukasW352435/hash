//
// Created by lukas on 6/13/19.
//

#include "BlockFactoryDebug.hpp"

using namespace std;

BlockFactoryDebug::BlockFactoryDebug(std::string message) : BlockFactory() {
    ulong size = message.length();
    ulong pos = 0;
    string substring;
    Block block;
    do{
        substring = message.substr(pos,64);
        block = Block(substring);
        cout << block;
        blocks.push_back(block);
        pos+=64;
    }while (pos<size);
    if(substring.length()<56)
    {
        cout << "Append One" << endl;
        block.appendOne(size%64);
        cout << block;
        cout << "Add Size" << endl;
        block.addSize(size*8);
        cout << block;
        blocks.pop_back();
        blocks.push_back(block);
    }else if(substring.length()<64){
        cout << "Append One" << endl;
        block.appendOne(size%64);
        cout << block;
        blocks.pop_back();
        blocks.push_back(block);
        block = Block();
        cout << "Add Size" << endl;
        block.addSize(size*8);
        cout << block;
        blocks.push_back(block);
    } else{
        block = Block();
        cout << "Append One" << endl;
        block.appendOne(0);
        cout << block;
        cout << "Add Size" << endl;
        block.addSize(size*8);
        cout << block;
        blocks.push_back(block);
    }
}