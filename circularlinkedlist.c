#include<stdio.h>

typedef struct node{
	int info;
	struct node *next;
}node;

node * getnode(int);
void traverse(node *);
node * addfirst(node *,int);
node * addlast(node *,int);
node * addbefore(node *,int,int);
node * addafter(node *,int,int);

int main()
{
	int item,num,ch;
	node *start=NULL;
	do
	{
		printf("\n1. ADDFIRST\n 2. ADDLAST\n 3. ADDBEFORE\n 4. ADDAFTER\n 5. DELNODE\n 6. TRAVERSE\n 7. COUNT\n 8. SUM\n\
9. MAX\n 10. EXIT\nEnter a choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\nEnter the item that you want to add first\n");
			scanf("%d",&item);
			start=addfirst(start,item);
			break;
		case 2:
			printf("\nEnter the item that you want to add last\n");
			scanf("%d",&item);
			start=addlast(start,item);
			break;
		case 3:
			printf("\nEnter the item that you want to add and the number before which you want to add.\n");
			scanf("%d %d",&item,&num);
			start=addbefore(start,item,num);
			break;
		case 4:
			printf("\nEnter the item that you want to add and the number after which you want to add.\n");
			scanf("%d %d",&item,&num);
			start=addafter(start,item,num);
		case 6:
			traverse(start);
			break;	
		default:
			printf("\nInvalid Choice\n");
		}
		
	}while(ch!=10);
	return 0;
}
node *getnode(int item)
{
	node *t=(node *)malloc(sizeof(node));
	t->info=item;
	return t;
}
void traverse(node *start)
{
	printf("Lined List is\n");
	node *ptr=start->next;
	do
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}while(ptr!=start->next);
	printf("\n");
}
node *addfirst(node *start,int item)
{
	node *newnode;
	newnode=getnode(item);
	if(start==NULL)
	{
		newnode->next=newnode;
		start=newnode;
	}
	else{
	newnode->next=start->next;
	start->next=newnode;
	}
	return start;
}
node *addlast(node *start,int item)
{
	node *newnode;
	newnode=getnode(item);
	if(start==NULL)
	{
		newnode->next=newnode;
		start=newnode;
	}
	else{
		newnode->next=start->next;
		start->next=newnode;
		start=newnode;
	}
	return start;
}
node *addbefore(node *start,int item,int num)
{
	node *newnode,*ptr,*preptr;
	ptr=start->next;
	preptr=start;
	if(start==NULL)
	{
		printf("\nNumber %d not found in the list\n",num);
	}
	newnode=getnode(item);
	do
	{
		if(ptr->info==num)
		break;
		preptr=ptr;
		ptr=ptr->next;
	}while(ptr!=start->next);
	if(ptr->info!=num)
	{
		printf("\nNumber %d not found\n",num);
	}
	newnode->next=ptr;
	preptr->next=newnode;
	return start;
}
node *addafter(node *start,int item,int num)
{
	node *newnode,*ptr;
	ptr=start->next;
	if(start==NULL)
	{
		printf("\nNumber %d not found in the list\n",num);
	}
	newnode=getnode(item);
	do
	{
		if(ptr->info==num)
		break;
		ptr=ptr->next;
	}while(ptr!=start);
	if(ptr->info!=num)
	{
		printf("\nNumber %d not found\n",num);
	}
	newnode->next=ptr->next;
	ptr->next=newnode;
	if(ptr==start)
	{
		start=newnode;
	}
	return start;
	
}

