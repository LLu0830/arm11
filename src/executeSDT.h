//
// Created by Katarina Kulkova on 25.05.2019.
//

#ifndef SRC_EXECUTESDT_H
#define SRC_EXECUTESDT_H

uint32_t loadFrom(uint32_t address);
void storeTo(uint32_t address);
void executeSDT(struct stateOfMachine ARM11_registers, uint32_t fetched);

#endif //SRC_EXECUTESDT_H
