/*
  Common types that multiple modules may use
 */

#ifndef COMMONTYPES_H
#define COMMONTYPES_H

#include <stdint.h>
#include <stdbool.h>

#define MemWidth uint64_t

struct ALUResult {
  bool is_zero;
  bool is_branch; // indicates if R type or other
  MemWidth alu_result;
};

typedef enum {R, I, J} OPCODE;

/*
  some R-Type and I-Typeinstruction functions
 */
typedef enum {
  /************* R-TYPE **************/
  ADDU, MULT, DIV, AND, OR, NAND, NOR,
  /************* I-TYPE **************/
  BEQ, BGEZ, BGETZ
} FUNC;

#endif
