#ifndef IN_OUT_H_
#define IN_OUT_H_

#include "kernel.h"

// Crea una interfaz con el nombre y el tipo dado.
interface_t *createInterface(char* nameInterface, interfaceType typeInterface);

// Compara el nombre de las interfaces para encontrar la dada globalmente.
bool compareNameInterface(void *data);

// Busca la interfaz solicitada por CPU.
interface_t *foundInterface(char* nameRequestInterface);

// Destruye las interfaces.
void destroyInterfaces();


#endif