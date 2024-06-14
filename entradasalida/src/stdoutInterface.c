#include "stdoutInterface.h"

void executeIOStdoutWriteAndSendResults()
{
    executeIOStdoutWrite();

    sendIOStdoutWriteResultsToKernel();

    free(resultsForStdout.resultsForWrite);
    resultsForStdout.resultsForWrite = NULL;

    interfaceData.currentOperation.operation = IO_NULL;
    free(interfaceData.currentOperation.params);
    interfaceData.currentOperation.pid = -1;
}

void executeIOStdoutWrite()
{   
    log_info(getLogger(), "PID: %d - Operacion: IO_STDOUT_WRITE", (int)interfaceData.currentOperation.pid);
    sendIOReadRequestToMemory();
    
    sem_wait(&semaphoreForStdout);

    printf("%s", resultsForStdout.resultsForWrite);
}