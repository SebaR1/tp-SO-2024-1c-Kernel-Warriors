#ifndef KERNEL_LOGGER_H_
#define KERNEL_LOGGER_H_


#include <commons/log.h>


// Debe ser inicializada usando la funcion log_create de las commons.
extern t_log* kernelLogger;

void initLogger(char* file, char* processName, bool isActiveConsole, t_log_level level);

void destroyLogger();



#endif