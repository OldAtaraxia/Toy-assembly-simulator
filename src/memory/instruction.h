#include<stdlib.h>
#include<stdint.h>

#define NUM_INSTRTYPE 30 

typedef enum OP{
    mov_reg_reg,
    mov_reg_mem,
    mov_mem_reg,
    push_reg,
    pop_reg,
    call,
    ret,
    add_reg_reg
} op_t;

typedef enum OD_TYPE{
    EMPTY,
    IMM, REG, MM_IMM, MM_REG, MM_IMM_REG, 
    MM_REG1_REG2, MM_IMM_REG1_REG2, MM_REG2_S,
    MM_IMM_REG2_S,MM_REG1_REG2_S, MM_IMM_REG1_REG2_S
} od_type_t;

// 操作数
typedef struct OD{
    od_type_t type;

    int64_t imm;
    uint64_t scal;
    uint64_t *reg1;
    uint64_t *reg2;
}od_t;

// 指令
typedef struct INSTRUCT_STRUCT{
    op_t op;
    od_t src;
    od_t dst;

    char code[100];
}inst_t;

// pointer pointing to the function
typedef void(*handler_t)(uint64_t, uint64_t);

handler_t handler_table[NUM_INSTRTYPE] = {
    &move_reg_reg_handler,
};

void instruction_cycle();

void move_reg_reg_handler(uint64_t src, uint64_t dst);
void add_reg_reg_handler(uint64_t src, uint64_t dst);