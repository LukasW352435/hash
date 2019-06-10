//
// Created by lukas on 6/10/19.
//

#include "Block.hpp"

using namespace std;

Block::Block(){
    words={0};
}
Block::Block(std::array<uint, 16> words) :words(words){
}
Block::Block(std::string message) {
    if(message.length()>64){
        throw "Message is to long for one Block!";
    }
    words={0};
    int j=0;
    for(int i=0;i<message.length();i++){
        switch(i%4){
            case 0:
                words[j] = (uint)(message[i] << 24);
                break;
            case 1:
                words[j] |= (uint)(message[i] << 16);
                break;
            case 2:
                words[j] |= (uint)(message[i] << 8);
                break;
            case 3:
                words[j] |= (uint)(message[i]);
                j++;
                break;
        }
    }
}

ostream& operator<<(ostream& os, const Block& block) {
    int size = block.words.size();
    for(int i=0;i<size;i++){
        os << setfill('0') << setw(8) << hex <<block.words[i] << "\t";
        if(i==3||i==7||i==11||i==15){
            os << endl;
        }
    }
    return os;
}

void Block::addSize(ulong size){
    words[14] = (uint)(size >> 32);
    words[15] = (uint)(size);
}
void Block::appendOne(uint byteIndex) {
    if(byteIndex > 63){
        throw "Index is to big!";
    }
    uint wordIndex = byteIndex/4;
    switch (byteIndex%4){
        case 0:
            words[wordIndex] |= 1 << 31;
            break;
        case 1:
            words[wordIndex] |= 1 << 23;
            break;
        case 2:
            words[wordIndex] |= 1 << 15;
            break;
        case 3:
            words[wordIndex] |= 1 << 7;
            break;
    }
}
array<uint, 16> Block::getWords() const {
    return words;
}