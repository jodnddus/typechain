class Block {
    public index: number;
    public hash: string;
    public previousHash: string;
    public data: string;
    public timestamp: number;
    constructor(
        index: number,
        hash: string,
        previousHash: string,
        data: string,
        timestamp: number
    ) {
        this.data = data;
        this.hash = hash;
        this.previousHash = previousHash;
        this.index = index;
        this.timestamp = timestamp;
    }
}

const genesisBlock: Block = new  Block(0, "20202020202", "", "Hello", 123456);

let blockchain: [Block] = [genesisBlock];

console.log(blockchain);

export{};