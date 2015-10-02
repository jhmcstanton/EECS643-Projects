#include "cache.h"

#define NumLines (1<<9) // this could be a field in Cache
#define L1CCs 4 // super arbitrary
#define MMCCs 100

Cache::Cache(uint8_t assoc) {
  this->associativity = assoc;
  this->totalCCs      = 0;
  this->num_hits      = 0;
  this->num_accesses  = 0;
  // Allocate the rows
  this->cache = new Set[NumLines] ; 

  for(int i = 0; i < NumLines; i++){
    // allocate the set (presumably 1, 2, 4, or 8)
    Set set;
    set.oldest_tag_index  = 0;
    set.num_used_elements = 0;
    AddrInfo *blocks = new AddrInfo[assoc];
    for(int j = 0; j < assoc; j++){
      //      blocks[j].tag   = NULL;
      blocks[j].valid = false;
    }
    set.blocks = blocks;
    this->cache[i] = set;
  }
}

// Returns true if there is a successful hit
bool Cache::access(Line line, Tag tag) {
  this->num_accesses++;
  Set set = this->cache[line]; 
  AddrInfo *blocks = set.blocks;
  for(int i = 0; i < set.num_used_elements; i++){
    // printf("inside access, line: %d, tag: %d\n", line, tag);
    //printf("Block => valid: %d, tag: %d\n",
    //	   blocks[i].valid, blocks[i].tag);
    if(blocks[i].valid && (blocks[i].tag == tag)){
      //      printf("HIT INSIDE ACCESS!\n");
      this->num_hits++;
      this->totalCCs += L1CCs;
      return true;      
    }
  }
  this->totalCCs += MMCCs;
  return false;
}

// this is called when there is a miss, so hopefully searching
// is mostly unnecessary
void Cache::push(Line line, Tag tag) {
  Set& set = this->cache[line];
  AddrInfo *blocks = set.blocks;
  
  if(set.num_used_elements < this->associativity){
    // Still initializing cache from cold boot!
    AddrInfo block;  
    block.tag = tag;
    block.valid = true;
    blocks[set.num_used_elements] = block;
    set.num_used_elements++;   
  } else {
    // TRASHING DATA HERE
    AddrInfo& block = blocks[set.oldest_tag_index];
    block.tag = tag;
    if(set.oldest_tag_index == this->associativity - 1){
      set.oldest_tag_index = 0;
    } else {
      set.oldest_tag_index++;
    }
  } 
     
}

Cache::~Cache() {
  for(int i = 0; i < NumLines; i++){
    delete cache[i].blocks;
  }
  delete cache;
}
