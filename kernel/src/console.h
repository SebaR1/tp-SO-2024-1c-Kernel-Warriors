#ifndef KERNEL_CONSOLE_H_
#define KERNEL_CONSOLE_H_

#include <readline/readline.h>
#include <commons/string.h>
#include "logger.h"
#include <stdlib.h>

//Inicia la consola interactiva de kernel
void readKernelConsole(void);

//Verifica si lo que ingresa es una instruccion posible
bool _isAnInstruction(char* instruction);

//Atiende la instruccion validada
//void attendInstruction(char* instruction);






#endif