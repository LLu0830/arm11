//
// Created by Katarina Kulkova on 24.05.2019.
//
#include <stdio.h>
#include "execute.h"
#include "registers.h"
#include "memory.h"
#include "executeDP.h"
#include "executeSDT.h"
#include "executeMUL.h"
#include "executeBR.h"


#ifndef SRC_EXECUTE_H
#define SRC_EXECUTE_H

enum instructionType;

void executeDP();
void executeMUL();
void executeSDT();
void executeBR();

#endif // SRC_EXECUTE_H