/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * 
 * @author jdiegodelgado
 * @date 23.05.2021
 *
 */

#include "../include/common/course1.h"
#include "../include/common/memory.h"
#include "../include/common/stats.h"
#include "../include/common/data.h"
#include "../include/common/platform.h"

void main (void){

    #ifdef COURSE1
    course1();
    #endif
}
