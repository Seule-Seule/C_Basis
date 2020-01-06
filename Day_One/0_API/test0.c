#include "stdlib.h"
#include "string.h"
#include "stdio.h"


/* API 1  */
//socket init 
int SocketInit(void **handle);
//socket send
int SocketSend(void **handle, unsigned char *buf, int bufLen);
//socket Recv
int SocketRecv(void **handle, unsigned char *buf, int *bufLen);
int SocketRecv(void **handle, unsigned char *buf, int *bufLen);
int SocketFree(void **handle);
//socket resete
int SocketResete(void *handle);

/* API 2  */
//socket init 
int SocketInit2(void **handle);
//socket send
int SocketSend2(void **handle, unsigned char *buf, int bufLen);
//socket Recv
int SocketRecv2(void **handle, unsigned char **buf, int *bufLen);
//socket resete
int SocketResete2(void **handle);



void main(){



	printf("Hello World! \n");
	return ;
}
