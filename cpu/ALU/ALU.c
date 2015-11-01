#include<ALU.h>
#include<stdbool.h>

struct ALUResult ALU(OPCODE op, FUNC func, MemWidth r1, MemWidth r2){
  struct ALUResult result;

  result.is_zero    = false;
  result.is_branch  = false;
  result.alu_result = 0;

  switch(op){
  case(I): 
    switch(func){
    case(BEQ):
      result.is_zero = r1 - r2;
      result.is_branch = true;
      break;
    case(BGEZ):
      result.is_zero   = r1 >= 0;
      result.is_branch = true;
      break;
    case(BGETZ):
      result.is_zero   = r1 > 0;
      result.is_branch = true;
      break;
    }
    break;
  case(J): 
    result.is_branch = true;
    break;
  
  case(R): 
    switch(func){
    case(ADDU): 
      result.alu_result = r1 + r2;
      break;
    
    case(MULT):
      result.alu_result = r1 * r2; //unsigned - is this right?
      break;
    
    case(DIV):
      result.alu_result = r1 / r2;
      break;
    
    case(AND):
      result.alu_result = r1 & r2;
      break;
    
    case(OR):
      result.alu_result = r1 | r2;
      break;
    
    case(NAND):
      result.alu_result = ~(r1 & r2);
      break;

    case(NOR):
      result.alu_result = ~(r1 | r2);
      break;
    }
    break;
  }

  return result;
}
