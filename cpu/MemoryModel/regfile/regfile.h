#ifndef REGFILE_H
#define REGFILE_H


#include<stdint.h>
#include <stdbool.h>


#define reg_addr uint8_t // this should be unsigned at all times!

#define REGFILESIZE (1 << (8 * sizeof(reg_addr))) // This is the number of registers uniquely addressable with reg_addr

void RegFile(reg_addr rs, reg_addr rt, reg_addr rd, uint32_t wrt_data, bool wrt_enb, uint32_t *s_data, uint32_t *t_data);
#endif
