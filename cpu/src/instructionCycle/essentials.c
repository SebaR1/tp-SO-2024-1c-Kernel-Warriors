#include "essentials.h"



int PID;



sem_t semaphoreWaitInstruction;

sem_t semCheckInterrupt;

sem_t semContinueInstructionCycle;

sem_t semWaitDataFromMemory;

sem_t semWaitConfirmationFromMemory;





void setCurrentPID(int value)
{
    PID = value;
}

int getCurrentPID()
{
    return PID;
}