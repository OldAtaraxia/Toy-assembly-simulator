#include "ass.h"

int main(){
    cpu_t cpu;
    cpu.rax = 0x1234abcd5678ffff;

}

uint64_t decode_od(od_t od){
    if(od.type == IMM){
        return od.imm;
    }else if(od.type == REG){
        return *(uint64_t *)od.reg;
    }else{
        uint64_t addr;

        return mm[addr % MM_LEN];
    }
}