#include <iostream>
#include "BlockFactory.hpp"
#include "SHA1.hpp"

using namespace std;

int main() {
    string message = "The quick brown fox jumps over the lazy dog";

    SHA1 s = SHA1(message);
    cout << s;
}
