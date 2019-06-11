//
// Created by MANSHU WANG on 6/4/2019.
//
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "encodeSPECIAL.h"
#include "../assembler_utility/table.h"
#include "../../part1_emulator/emulator_utility/utility.h"
#include "../assembler_utility/assembler_utility.h"
#include "encodeDP.h"

void encodeSPECIAL(assembler_instruction *instruction) {
    /*

       switch (instruction->operationType) {
           case andeq:
               //maybe need to check if operand1,2,3 all = 0;
               if (!strcmp(instruction->arg1, "r0")
                   && !strcmp(instruction->arg2, "r0")
                   && !strcmp(instruction->arg3, "r0")) {
                   instruction->encoded = 0x0;
               }
               break;
           case lsl: {
   //            // case DP: Operand2 is a register, shifted by a constant amount
   //
   //            //cond field set to 1110
   //            uint32_t cond = 0xe;
   //
   //            //set i bit to 0
   //            uint32_t IBit = 0;
   //            //set opcode to mov
   //
   //
   //            //set s bit to 0
   //            uint32_t SBit = 0;
   //
   //            // shifted amount
   //            token shiftAmount = instruction->arg3;
   //            uint32_t shiftA = (uint32_t) strtol(shiftAmount + 1, NULL, 16);
   //
   //            //shift type = lsl 00
   //            uint32_t shiftType = 0;
   //
   //            //get Rn from org2
   //            token rn = instruction->arg2;
   //            uint32_t positionRn = (uint32_t) strtol((rn + 1), NULL, 16);
   //
   //            break;
           }
           default:
               break;
   //=======
   //    Mnemonic type = instruction->operationType;
   //
   //    //halt instruction - returns zero
   //    if (type == andeq) {
   //        instruction->encoded = 0x00000000;
   //>>>>>>> e54bf20660dbad997fde4253f092e719ffc58c79
       }

       //lsl gets converted to move instruction: mov Rn, Rn, lsl <#expression>
       else if (type == lsl) {

           instruction->mnemonic = copy_string("mov");

           char* mov_arg2 = copy_string(instruction->arg1);
           char* mov_arg4 = copy_string(instruction->arg2);

           instruction->arg2 = copy_string(mov_arg2);
           instruction->arg3 = copy_string("lsl");
           instruction->arg4 = copy_string(mov_arg4);

           free(mov_arg2);
           free(mov_arg4);

           encodeDP(instruction);
       }

       //error message
       else {
           perror("Invalid operation type");
           exit(EXIT_FAILURE);
       }

   }

   */
}
