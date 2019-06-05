//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "readLabels.h"
#include "../assembler_utility/table.h"
#include "../emulator_utility/DefinedTypes.h"

uint32_t* readLable(label_address_list* table, FILE *filepointer){
    table=
    uint32_t lineNum=0,currentLabel=0;
    char *currentLabel=calloc(512, sizeof(char));
    char *temp=currentLabel;
    while(fgets(temp,512,filepointer)!=NULL){
        temp=cleanDelimiter(temp,"\n");
        if(charExist(temp,':')==0&&*temp!='\0'){
            lineNum++
        }else{
            label_address_list *list initialize_pair();
            pair.label=stripString(temp,":");

        }
    }
}