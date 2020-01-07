#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KernelList.h"

typedef  struct node {
	char	name[20];
	int		age;
	struct list_head list;
}strage;


int main()
{
	strage s[] = {
		{"Bob",20},
		{"Aliy",30},
		{"Mac",22},
		{"Vair",29},
	};
	int	ErroMsg = 0;
	int i = 0;

	INIT_LIST_HEAD(head);
	for (i = 0; i < sizeof s / sizeof s[0]; ++i)
	{
		list_add_tail(&s[i].list, &head);
	}
	list_del(&s[1].list);
	struct list_head* cur;
	list_for_each(cur, &head) {
		strage * pa = container_of(cur, strage, list);
		printf("%s:%d\n", pa->name, pa->age);
	}
	
	return ErroMsg;
}

