"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class Block {
    constructor(index, hash, previousHash, data, timestamp) {
        this.data = data;
        this.hash = hash;
        this.previousHash = previousHash;
        this.index = index;
        this.timestamp = timestamp;
    }
}
const genesisBlock = new Block(0, "20202020202", "", "Hello", 123456);
let blockchain = [genesisBlock];
console.log(blockchain);
//# sourceMappingURL=index.js.map