//
// Created by Katarina Kulkova on 24.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "execute.h"
#include "executeDP.h"
#include "executeSDT.h"
#include "executeMUL.h"
#include "executeBR.h"
#include "instruction.h"
#include "state.h"

#ifndef SRC_EXECUTE_H
#define SRC_EXECUTE_H

void execute(instruction_type instruction, struct stateOfMachine state);
bool checkCondition(struct stateOfMachine state, Cond condition);

#endif // SRC_EXECUTE_H