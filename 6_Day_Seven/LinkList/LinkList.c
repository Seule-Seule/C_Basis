#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"

#define LOGNAME  "log/log.log"


typedef struct node {
	int	data;
	struct node* next;
}List;

//创建带头结点的单向链表
List* CreateList()  
{
	int		ErroMsg = 0;
	List*	pHead, * pCurrent, * pTmp;
	int		data_tmp = 0;
	pHead = (List*)malloc(sizeof(List));
	if (pHead == NULL)
	{
		ErroMsg = -1;
		LOG(LOGNAME, __FILE__, __LINE__, 4, ErroMsg, "%s", "Func molloc pHead fail! ");
		goto END;
	}
	pHead->data = 0;
	pHead->next = NULL;
	pCurrent = pHead;


	while (1)
	{
		printf("Please input data:");
		scanf("%d", &data_tmp);
		if (-1 == data_tmp)
		{
			break;
		}

		pTmp = (List*)malloc(sizeof(List));
		if (pTmp == NULL)
		{
			ErroMsg = -2;
			LOG(LOGNAME, __FILE__, __LINE__, 4, ErroMsg, "%s", "Func molloc pTmp fail! ");
			goto END;
		}

		pTmp->next = NULL;
		pTmp->data = data_tmp;

		pCurrent->next = pTmp;
		pCurrent = pTmp;

	}
END:
	if (-1 == ErroMsg)
	{
		return NULL;
	}
	if (-2 == ErroMsg)
	{
		ErroMsg = FreeList(pHead);
		if (0 != ErroMsg)
		{
			ErroMsg = -3;
			LOG(LOGNAME, __FILE__, __LINE__, 4, ErroMsg, "%s", "Func molloc pTmp fail and free has node fail!");
			return NULL;
		}
	}
	return pHead;
}
//在链表_insert_list_name的_insert_addrss处插入_insert_data
int InsertList(List* _insert_list_pHead, int _insert_addrss, int _insert_data) 
{
	List*	pCurrent, * pTmp;
	int		Tcount = 0;
	
	if (_insert_list_pHead == NULL)
	{
		return -1;
	}
	pCurrent = _insert_list_pHead->next;
	while (pCurrent)
	{
		Tcount++;
		if (Tcount == _insert_addrss)
		{
			break;
		}
		pCurrent->next = pCurrent->next;
	}

	pTmp = (List*)malloc(sizeof(List));
	if (pTmp == NULL)
	{
		LOG(LOGNAME, __FILE__, __LINE__, 4, -2, "%s", "molloc pTmp fail! ");
		return NULL;
	}

	pTmp->next = pCurrent->next;
	pTmp->data = _insert_data;
	pCurrent->next = pTmp;

	return 0;
}

// 链表打印
void  PrintList(List* _list_pHead) 
{
	List* pTmp = NULL;
	if (_list_pHead == NULL)
	{
		return;
	}
	pTmp = _list_pHead->next;

	printf("\nLinked List:\t");
	while (pTmp)
	{
		printf("%-4d", pTmp->data);
		pTmp = pTmp->next;
	}
	printf("End\n");
	return ;
}

//销毁链表
int FreeList(List* _list_pHead)
{
	if (_list_pHead == NULL)
	{
		return -1;
	}
	List* pHead, *pTmp;
	pHead = _list_pHead;
	pTmp  = _list_pHead;
	while (pHead)
	{
		pHead = pTmp->next;
		free(pTmp);
		pTmp = pHead;
	}
	return 0;
}


int main()
{
	int	ErroMsg = 0;
	List* pHade = NULL;

	pHade = CreateList();
	if (pHade == NULL)
	{
		LOG(LOGNAME, __FILE__, __LINE__, 4, -1, "%s", "CreateList() fail!");
		return -1;
	}

	PrintList(pHade);

	ErroMsg = InsertList(pHade, 2, 2);
	if (0 != ErroMsg)
	{
		LOG(LOGNAME, __FILE__, __LINE__, 4, ErroMsg, "%s", "Free Linked List fail!");
		return ErroMsg;
	}

	PrintList(pHade);


	ErroMsg = FreeList(pHade);
	if (0 != ErroMsg)
	{
		LOG(LOGNAME, __FILE__, __LINE__, 4, ErroMsg, "%s", "Free Linked List fail!");
		return ErroMsg;
	}
	
	return ErroMsg;
}