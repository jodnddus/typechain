import * as CryptoJS from "crypto-js";

class Block {
    public index: number;
    public hash: string;
    public previousHash: string;
    public data: string;
    public timestamp: number;
    
    static calculateBlockHash = (
        index:number,
        previousHash:string, 
        timestamp:number, 
        data:string
    ): string =>
        CryptoJS.SHA256(index + previousHash + timestamp + data).tostring();

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

let blockchain: Block[] = [genesisBlock];

const getBlockchain = (): Block[] => blockchain;

const getLatestBlock = (): Block => blockchain[blockchain.length - 1];

const getNewTimeStamp = (): number => Math.round(new Data().getTime() / 1000);

export{};