#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *next;
};
struct node *sp=NULL;
struct node *push(struct node *,int);
struct node *pop(struct node *,int *);
void display(struct node *);
int search(struct node *,int);
int main()
{
int opt,data,found;
for(;;)
{
printf("1.PUSH\n2.POP\n3.DISPLAY\n4.SEARCH\n5.EXIT\n");
printf("Enter your choice:");
scanf("%d",&opt);
switch(opt)
{
case 01:
printf("Enter element to insert:");
scanf("%d",&data);
sp=push(sp,data);
break;
case 02:
if(sp==NULL)
{
printf("Stack is empty\n");
}
else
{
sp=pop(sp,&data);
printf("Popped element is:%d\n",data);
}
break;
case 03:
display(sp);
break;
case 04:
printf("Enter the element to be searched:");
scanf("%d",&data);
found=search(sp,data);
if(found!=0)
printf("The element is %d\n",data);
else
printf("Not found\n");
break;
case 05:
exit(0);
break;
}
}
return 0;
}
struct node *push(struct node *sp,int data)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->next=sp;
sp=temp;
return sp;
}
struct node *pop(struct node *sp,int *x)
{
struct node *temp;
if(sp!=NULL)
{
temp=sp;
*x=sp->data;
sp=sp->next;
free(temp);
}
return sp;
}
void display(struct node *sp)
{
if(sp==NULL)
{
printf("Stack is empty\n");
return;
}
printf("Stak elements are:\n");
while(sp!=NULL)
{
printf("%d\n",sp->data);
sp=sp->next;
}
}
int search(struct node *sp,int data)
{
while(sp!=NULL)
{
if(sp->data==data)
return 1;
sp=sp->next;
}
return 0;
}
