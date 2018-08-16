////g++ -o cryptoppTest cryptoppTest.cpp -l:libcryptopp.a
#include "blockchain.hpp"

string Block::calculateBlockHash(const int number, const string previousHash, const int timestamp, const string data)  
{
        //hash function
    const string number_ = std::to_string(number);
    const string timestamp_ = std::to_string(timestamp);
    /*all arguments is std::string types*/
    string new_hash_string = number_ + previousHash + timestamp_ + data;
    string digest;

    CryptoPP::SHA256 hash;
        
    CryptoPP::StringSource s(new_hash_string, true,
		new CryptoPP::HashFilter(hash,
			new CryptoPP::HexEncoder(
				new CryptoPP::StringSink(digest))));
        
    return digest;
}

bool Block::validateStructure(Block* anyBlock)
{
    return 
    (typeid(anyBlock->index) == typeid(int)) && 
    (typeid(anyBlock->hash) == typeid(std::string)) && 
    (typeid(anyBlock->previousHash) == typeid(std::string)) &&
    (typeid(anyBlock->timestamp) == typeid(int)) &&
    (typeid(anyBlock->data) == typeid(std::string));
}

Block::Block(int index_, string hash_, string previousHash_, string data_, int timestamp_):
        index(index_), 
        hash(hash_), 
        previousHash(previousHash_),
        data(data_),
        timestamp(timestamp_) {}
    
Block::Block(): 
    index(0),
    hash(""),
    previousHash(""),
    data(""),
    timestamp(0) {}

Block* getBlockchain()
{
    return genesisblock;
}

Block* getLatesBlock()
{
    return blockchain.back();
}

int getNewTimeStamp()
{
    time_t now = time(0);
    return now;
}

string getHashforBlock(Block* anyBlock)
{
    return anyBlock->calculateBlockHash(anyBlock->get_index(), anyBlock->get_previousHash(), anyBlock->get_timestamp(), anyBlock->get_data());
}

bool isBlockValid(Block* candidateBlock, Block* previousBlock)
{
    if(!Block::validateStructure(candidateBlock))
        return false;
    else if(previousBlock->get_index() + 1 != candidateBlock->get_index())
        return false;
    else if(previousBlock->get_hash() != candidateBlock->get_previousHash())
        return false;
    else if(getHashforBlock(candidateBlock) != candidateBlock->get_hash())
        return false;
    else
        return true;
}

void addBlock(Block* candidateBlock)
{
    if(isBlockValid(candidateBlock, getLatesBlock()))
        blockchain.push_back(candidateBlock);
}

Block* createNewBlock(string data)
{
    Block* previousBlock = getLatesBlock();
    int newIndex = previousBlock->get_index() + 1;
    int newTimestamp = getNewTimeStamp();
    string newHash = Block::calculateBlockHash(newIndex, previousBlock->get_hash(), newTimestamp, data);
    Block* newBlock = new Block(newIndex, newHash, previousBlock->get_hash(), data, newTimestamp);
    addBlock(newBlock);
    return newBlock;
}

void PRINT_BLOCKCHAIN()
{
    vector<Block*>::iterator iter = blockchain.begin();

    for(size_t t = 0; t < blockchain.size(); ++t)
    {
        cout << "Block {\n";
        cout << '\t' << "data: " << iter[t]->get_data() << ",\n";
        cout << '\t' << "hash: " << iter[t]->get_hash() << ",\n";
        cout << '\t' << "previousHash: " << iter[t]->get_previousHash() << ",\n";
        cout << '\t' << "index: " << iter[t]->get_index() << ",\n";
        cout << '\t' << "timestamp: " << iter[t]->get_timestamp() << ",\n";
    }
}