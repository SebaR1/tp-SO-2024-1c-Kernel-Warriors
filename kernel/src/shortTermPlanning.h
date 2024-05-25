#ifndef SHORT_TERM_PLANNING_H_
#define SHORT_TERM_PLANNING_H_

#include "utils/listMutex.h"
#include "utils/utilsGeneral.h"
#include "generalPlanning.h"
#include "utilsKernel/logger.h"
#include "utilsKernel/config.h"
#include "connections/clientKernel.h"
#include <commons/temporal.h>

//Hilo para el estado de ready
void readyState(void);

void execState(void);

//Rotorna la lista de pids de pcbReadyList en formato string
char* _listPids(t_list *list);

//Inicia la planificacion a corto plazo
void initShortTermPlanning(void);

//Controla el limite de quantum y si es que lo pasa manda la interrupcion
void quantumControlInterrupt();
 

#endif