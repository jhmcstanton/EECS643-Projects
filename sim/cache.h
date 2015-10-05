/*
 EECS 643
 Jim Stanton, Pete Koehn, Brandon Teh
 
 This class keeps track of set-associative caches.
 */

#include<stdint.h>
#include<queue>

#define Address uint32_t
#define Line uint32_t
#define Tag  uint32_t
#define Valid bool
  
struct AddrInfo {
  Tag tag;
  Valid valid;
};

struct Set {
  AddrInfo *blocks;
  uint8_t oldest_tag_index;
  // This is used to indicate when to start popping
  // items from the set
  uint8_t num_used_elements; 
};

class Cache {
 private:
  Set *cache;
  uint8_t associativity;
 public:
  Cache(uint8_t); // set the associativity
  ~Cache();
  void print_results();
  bool access(Line, Tag);
  void push(Line, Tag);
  uint64_t num_hits;
  uint64_t num_accesses;
  uint64_t totalCCs;
};
