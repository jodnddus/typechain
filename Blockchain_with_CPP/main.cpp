#include "blockchain.hpp"

int main()
{
    blockchain.push_back(genesisblock);
    cout << "no insert>>>" << blockchain.size() << endl;
    createNewBlock("hi");
    cout << "1st insert>>>" << blockchain.size() << endl;
    createNewBlock("my name is");
    cout << "2nd insert>>>" << blockchain.size() << endl;
    createNewBlock("jodnddus");
    cout << "3rd insert>>>" << blockchain.size() << endl;

    PRINT_BLOCKCHAIN();
    //cout << Block::calculateBlockHash(1234, "previousHash", 4567, "data");
    return 0;
}