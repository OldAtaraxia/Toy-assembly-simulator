#include <stdint.h>
#include "../cpu/mmu.h"
#include "../cpu/register.h"
#include "instruction.h"

// 指令解码
static uint64_t decode_od(od_t od){
    if(od.type == IMM){
        return od.imm;
    }else if(od.type == REG){
        return (uint64_t)od.reg1; 
    }else{
        // memory
        uint64_t vaddr = 0;
        if(od.type == MM_IMM){
            vaddr = od.imm;
        }else if(od.type == MM_REG){
            vaddr = *(od.reg1);
        }else if(od.type == MM_IMM_REG){
            vaddr = od.imm + *(od.reg1);
        }else if(od.type == MM_REG1_REG2){
            vaddr = *(od.reg1) + *(od.reg2);
        }else if(od.type == MM_IMM_REG1_REG2){
            vaddr = *(od.reg1) + *(od.reg2) + od.imm;
        }else if(od.type == MM_REG2_S){
             vaddr = (*(od.reg2)) * (od.scal);
        }else if(od.type == MM_IMM_REG2_S){
            vaddr = od.imm + (*(od.reg2)) * (od.scal);
        }else if(od.type == MM_REG1_REG2_S){
            vaddr = *(od.reg1) + (*(od.reg2)) * (od.scal);
        }else if(od.type == MM_IMM_REG1_REG2_S){
            vaddr = od.imm + *(od.reg1) + (*(od.reg2)) * (od.scal);
        }

        return va2pa(vaddr);
    }
}

void instruction_cycle(){
    inst_t *instr = (inst_t *)reg.rip; // PC

    uint64_t src = decode_od(instr->src);
    uint64_t dst = deconde_od(instr->src);
     handler_t handler = handler_table[instr->op];
     handler(src, dst);
}

void init_handler_table(){
    handler_table[add_reg_reg] = &add_reg_reg_handler;
}


void add_reg_reg_handler(uint64_t src, uint64_t dst){
    *(uint64_t *)dst = *(uint64_t *) dst = *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}