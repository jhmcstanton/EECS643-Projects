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
  //std::queue<uint32_t> tag_queue;
  // These are used, rather than a queue, to just keep an 
  // index of the value to pop next. 
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
