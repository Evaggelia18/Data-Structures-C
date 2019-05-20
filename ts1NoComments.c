#include<stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int val;
    int col;
    int row;
    struct node * next;
} node_t;

int main()
{
	printf("Input Ηeight Αnd Width Of Matrix Α:\n ");
	int h, w;
	int f = 1;
	scanf("%d", &h);
	scanf("%d", &w);
	int b[h][w], c[h][w], a;
	node_t * head = malloc(sizeof(node_t));

	printf("Please input matrix A:\n");
	for (int i = 0; i <h; ++i)
	{
		for(int j=0; j<w; ++j)
		{
			c[i][j] = 0;
			scanf("%d", &a);
			if (a!=0)
			{
				if(f==0)
				{
					push(head, a, i, j);
				}
				else
				{
	                head->val = a;
	                head->col = i;
	                head->row = j;
	                head->next=NULL;
	                f = 0;
				}
			}

		}
	}
	print_list(head);

    f = 1;
	node_t * head2 = malloc(sizeof(node_t));
	
	printf("Please input matrix B: \n");
	for (int i = 0; i <h; ++i)
	{
		for(int j=0; j<w; ++j)
		{
			scanf("%d", &a);
			if (a!=0)
			{
				if(f==0)
				{
					push(head2, a, i, j);
				}
				else
				{
	                head2->val=a;
	                head2->col = i;
	                head2->row = j;
	                head2->next=NULL;
	                f = 0;
				}
			}
		}
	}
	//print_list(head2);
	
	node_t * current = head;
    node_t * current2 = head2;
    int col, row, val;
    while (current != NULL) 
    {
    	col = current->col;
    	row = current->row;
    	val = current->val;

    	c[col][row] = c[col][row] + val;
		current = current->next;
	}

	while (current2 != NULL) 
    {
    	col = current2->col;
    	row = current2->row;
    	val = current2->val;;

    	c[col][row] = c[col][row] + val;
		current2 = current2->next;
	}
	
    printf("------------------------------------\n" );    
    for (int i = 0; i < h; ++i)
    {
    	for (int j = 0; j < w; ++j)
    	{
    		printf("%d",c[i][j] );	
    	}
    	printf("\n");
    }

}


int print_list(node_t * head) 
{
    node_t * current = head;

    while (current != NULL) 
    {
    	printf("%s","Data: " );
        printf("%d\n", current->val);

    	printf("%s","Column: " );
        printf("%d\n", current->col);

    	printf("%s","Row: " );
        printf("%d\n", current->row);
        current = current->next;
    }
    return 0;
}

 
int push(node_t * head, int val, int i, int j) 
{
    node_t * current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->col = i;
    current->next->row = j;
    current->next->next = NULL;
    return 0;  
}