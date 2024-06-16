#include "mathMemory.h"



int getInternalFragmentation(int pageSize, int bytesAllocated)
{
    return (  pageSize - (  bytesAllocated % pageSize  )  ) % pageSize;
}

int getAmountOfBytesInTheLastPage(int pageSize, int internalFragmentation)
{
    return pageSize - internalFragmentation;
}

int getAmountOfBytesAllocated(int pageSize, int amountOfPages, int internalFragmentation)
{
    return amountOfPages * pageSize - internalFragmentation;
}

int getAmountOfPagesAllocated(int pageSize, int bytesAllocated)
{
    return ceil(bytesAllocated / pageSize);
}

int getAmountOfPagesToFree(int pageSize, int bytesToFree)
{
    return floor(bytesToFree / pageSize) + 1;
}