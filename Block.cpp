//
// Created by lukas on 6/10/19.
//

#include "Block.hpp"

using namespace std;

Block::Block(){
    words={0};
}
Block::Block(std::array<ushort, 32> words) :words(words){
}
Block::Block(std::string message) {
    if(message.length()>64){
        throw "Message is to long for one Block!";
    }
    words={0};
    int j=0;
    for(int i=0;i<message.length();i++){
        if(i%2==0){
            words[j] = (ushort)(message[i] << 8);
        } else{
            words[j] |= (ushort)message[i];
            j++;
        }
    }
}

ostream& operator<<(ostream& os, const Block& block) {
    int size = block.words.size();
    for(int i=0;i<size;i++){
        os << setfill('0') << setw(4) << hex <<block.words[i] << "\t";
        if(i==7||i==15||i==23||i==31){
            os << endl;
        }
    }
    return os;
}

void Block::addSize(ulong size){
    words[28]= (ushort)(size >> 48);
    words[29]= (ushort)(size >> 32);
    words[30]= (ushort)(size >> 16);
    words[31]= (ushort)(size);
}