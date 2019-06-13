#include <iostream>
#include "BlockFactory.hpp"
#include "SHA1.hpp"
#include "SHA1Debug.hpp"
#include "BlockFactoryDebug.hpp"

using namespace std;

int main() {
    string message = "The quick brown fox jumps over the lazy dog";
    cout << "Message" << endl;
    cout << message << endl << endl;
    cout << "Create Block(s)" << endl;
    BlockFactoryDebug b = BlockFactoryDebug(message);
    list<Block> blocks = b.getBlocks();
    cout << "Create Hash" << endl;
    SHA1Debug s = SHA1Debug(&blocks);
    cout << "Hash" << endl;
    cout << s;
}
