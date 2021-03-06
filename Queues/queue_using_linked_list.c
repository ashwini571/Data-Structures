# include <stdio.h>
# include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

typedef struct node node;

node *front = NULL, *rear = NULL;

int isEmpty()
{
	if(front == NULL)
		return 1;
	else
		return 0;
}

void enqueue(int data)
{
	node *tmp = (node *) malloc(sizeof(node));
	tmp->data = data;
	tmp->next = NULL;
	if(front == NULL)
	{
		front = tmp;
		rear = tmp;
		return;
	}
	rear->next = tmp;
	rear = tmp;
	return;
}

int dequeue()
{
	if(isEmpty())
	{
		printf("\n Underflow");
		exit(1);
	}
	int data;
	node *tmp = front;
	data = tmp->data;
	front = tmp->next;
	free(tmp);
	return data;
}

void display()
{
	node *p = front;
	system("clear");
	printf("\n The queue is as follows : \n");
	while(p != NULL)
	{
		printf(" %d, ",p->data);
		p = p->next;
	}
	printf("\n");
	return;
}

int peek()
{
	if(isEmpty())
	{
		printf("\n Underflow");
		exit(1);
	}
	return front->data;
}

int main()
{
	system("clear");
	int choice, data;
	while(1)
	{
		printf("\n 1. Insert element\n 2. Delete element\n 3. Peek\n 4. Show queue \n 5. Exit\n");
		printf(" Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\n Enter the data to be inserted to the queue : ");
				scanf("%d", &data);
				enqueue(data);
				break;
			case 2:
				data = dequeue();
				printf("\n The deleted data is : %d\n", data);
				break;
			case 3:
				data = peek();
				printf("\n The data at the front of the queue is : %d\n", data);
				break;
			case 4:
				display();
				break;
			case 5: 
				exit(1);
			default:
				printf("\n Enter a valid choice \n");
		}
	}
}