
#include <stdio.h>
#include "log.h"

int main(void)
{
	int i = -2;
	char* logFileName = "log.txt";

	for (i = 0; i < 5;i++)
	{
		LR_LOG(logFileName,__FILE__, __LINE__, i, i, "test");
	}
	printf("ok\n");
	return 0;
}
