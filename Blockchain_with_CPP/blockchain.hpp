#include <iostream>
#include <typeinfo>
#include <ctime>
#include <boost/functional/hash.hpp>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

using namespace std;

class Block
{
private:
    int index;
    string hash;
    string previousHash;
    string data;
    int timestamp;
public:
    Block(int index_, string hash_, string previousHash_, string data_, int timestamp_);
    Block();
    static string calculateBlockHash(const int number, const string previousHash, const int timestamp, const string data);
    static bool validateStructure(Block* anyBlock);
    //getter들 정의
    const int get_index() { return index; }
    const int get_timestamp() { return timestamp; }
    const string get_hash() { return hash; }
    const string get_previousHash() { return previousHash; }
    const string get_data() { return data; }
};

vector<Block*> blockchain;
Block* genesisblock = new Block(0, "20202020202020", "", "Hello", 12345);

//blcokchain 핸들링 메서드
Block* getBlockchain();
Block* getLatesBlock();
int getNewTimeStamp();
std::string getHashforBlock(Block* anyBlock);
bool isBlockValid(Block* candidateBlock, Block* previousBlock);
void addBlock(Block* candidateBlock);
Block* createNewBlock(string data);
void PRINT_BLOCKCHAIN();
