//
// Created by Katarina Kulkova on 24.05.2019.
//

#ifndef SRC_EXECUTE_H
#define SRC_EXECUTE_H

enum instructionType {
    'DP',
    'MUL',
    'SDT',
    'BR'
};

void executeDP();
void executeMUL();
void executeSDT();
void executeBR();

#endif // SRC_EXECUTE_H