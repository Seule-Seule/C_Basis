
//SOCKETCLENT_H
#ifndef _SOCKETCLENT_H
#define _SOCKETCLENT_H

/* API 1  */
//socket init 
int SocketInit(void **handle);
//socket send
int SocketSend(void **handle, unsigned char *buf, int bufLen);
//socket Recv
int SocketRecv(void **handle, unsigned char *buf, int *bufLen);
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

//技术点
//1集指针
//2级指针
//封装

#endif
