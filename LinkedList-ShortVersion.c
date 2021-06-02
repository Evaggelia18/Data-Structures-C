#include<stdio.h>
typedef struct node
{
	int val;
	struct node* next;
}node_t;
int  main()
{
	node_t* head = malloc(sizeof(node_t));	
	for(int i = 0; i < 10; i++)
	{
		if( i != 0)
		{
			push(head, i);
		}
		else
		{
			head -> val = i;
			head -> next = NULL;
		}
	}
	pr(head, 10);
	printf("What do you want to perform? \n");
	printf("1: Delete an element \n2: Insert an element\n3: Print list\nInput: ");
	int ans;
	scanf("%d", &ans);

	switch(ans)
	{
		case 1:
			scanf("%d", &ans);
			del(head, ans, 10);
			break;
		case 2:
			scanf("%d", &ans);
			//ins(head, ans, 10);
		case 3:
			pr(head, 9);
	}

pr(head, 9);	

	return 0;
}

int del(node_t* head, int ans, int i)
{
	node_t* current = head, *prev;
	while(current -> val != ans)
	{
		prev = current;
		current = current -> next;
	}
	if(current -> val == ans)
	{
		free(current);
	}
	prev -> next = current -> next;

	return 0 ;
}

int pr(node_t* head,int i)
{
	node_t* current = head;
	for(int j = 0; j < i; j++)
	{
		printf("%d", current->val);
		current = current -> next;
	}
	return 0;
}

int push(node_t* head, int i)
{
	node_t* current = head;
	while(current -> next != NULL)
	{
		current = current -> next;
	}
	current -> next = malloc(sizeof(node_t));
	current -> next -> val = i;
	current -> next -> next = NULL;

	return 0;
}

		
