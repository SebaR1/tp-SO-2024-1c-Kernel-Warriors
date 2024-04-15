#include "utils.h"


int initServer(t_log* logger, char* port)
{
	struct addrinfo hints,*servinfo;


	memset(&hints, 0, sizeof(hints));

	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, port, &hints, &servinfo);

	// creamos el socket
	int socketServer = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	if (socketServer == -1) 
	{
        log_error(logger, "Error al crear el socket del servidor");
        freeaddrinfo(servinfo);
        return -1;
    }

	// Asociamos el socket a un puerto
	if (bind(socketServer, servinfo->ai_addr, servinfo->ai_addrlen) == -1) 
	{
        log_error(logger, "Error al enlazar el socket del servidor");
        close(socketServer);
        freeaddrinfo(servinfo);
        return -1;
    }

	// Escuchamos las conexiones entrantes
	if(listen(socketServer, SOMAXCONN)==-1)
	{
		log_error(logger, "Error al escuchar las conexiones entrantes");
        close(socketServer);
        freeaddrinfo(servinfo);
        return -1;
	}

	freeaddrinfo(servinfo);

	log_info(logger, "Listo para escuchar a mi cliente");

	return socketServer;
}

int waitClient(t_log* logger, int socketServer)
{
	// Aceptamos un nuevo cliente
    int socketClient = accept(socketServer, NULL, NULL);
    if (socketClient == -1) {
        log_error(logger, "Error al aceptar la conexión del cliente");
        return -1;
    }

    log_info(logger, "Se conectó un cliente!");
    return socketClient;
}

operationCode getOperation(int socketClient)
{
	operationCode opCode;
	if(recv(socketClient, &opCode, sizeof(int), MSG_WAITALL) > 0)
		return opCode;
	else
	{
		close(socketClient);
		return ERROR;
	}

}

void* getBuffer(int* size, int socketClient)
{
	void * buffer;

	recv(socketClient, size, sizeof(int), MSG_WAITALL);
	buffer = malloc(*size);
	recv(socketClient, buffer, *size, MSG_WAITALL);

	return buffer;
}

void getMessage(t_log* logger, int socketClient)
{
	int size;
	char* buffer = getBuffer(&size, socketClient);
	log_info(logger, "Me llego el mensaje %s", buffer);
	free(buffer);
}

t_list* getPackage(int socketClient)
{
	int totalSize;
	int offset = 0;
	void * buffer;
	t_list* values = list_create();
	int eachSize;

	buffer = getBuffer(&totalSize, socketClient);
	while(offset < totalSize)
	{
		memcpy(&eachSize, buffer + offset, sizeof(int));
		offset+=sizeof(int);
		char* value = malloc(eachSize);
		memcpy(value, buffer+offset, eachSize);
		offset+=eachSize;
		list_add(values, value);
	}
	free(buffer);
	return values;
}
