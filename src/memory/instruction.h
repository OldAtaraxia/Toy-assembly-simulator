#include<stdlib.h>
#include<stdint.h>

#define NUM_INSTRTYPE 30 

typedef enum OP{
    MOV,
    PUSH,
    CALL,
    add_reg_reg
} op_t;

typedef enum OD_TYPE{
    IMM, REG, MM_IMM, MM_REG, MM_IMM_REG, 
    MM_REG1_REG2, MM_IMM_REG1_REG2, MM_REG2_S,
    MM_IMM_REG2_S,MM_REG1_REG2_S, MM_IMM_REG1_REG2_S
} od_type_t;

// 寻址
typedef struct OD{
    od_type_t type;

    int64_t imm;
    uint64_t scal;
    uint64_t *reg1;
    uint64_t *reg2;

    char code[100];
}od_t;

// 指令
typedef struct INSTRUCT_STRUCT{
    op_t op;
    od_t src;
    od_t dst;
}inst_t;

// pointer pointing to the function
typedef void(*handler_t)(uint64_t, uint64_t);

handler_t handler_table[NUM_INSTRTYPE];

void instruction_cycle();


void add_reg_reg_handler(uint64_t src, uint64_t dst);