//
// Created by Katarina Kulkova on 24.05.2019.
//


#ifndef SRC_EXECUTE_H
#define SRC_EXECUTE_H

#include <part1_emulator/emulator_utility/instruction.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "execute.h"
#include "executeDP.h"
#include "executeSDT.h"
#include "executeMUL.h"
#include "executeBR.h"
#include "emulator_utility/instruction.h"
#include "emulator_utility/state.h"

void execute(instruction_type instruction, struct stateOfMachine state);

#endif // SRC_EXECUTE_H
