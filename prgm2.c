#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stk[SIZE];
int sp=-1;
int main()
{
void push(int);
int pop();
void display();
int item,opt;
do
{
printf("\n1.PUSH\n2.POP\n3.EXIT\n4.DISPLAY\n");
printf("Enter your choice:");
scanf("%d",&opt);
switch(opt)
{
case 01:
printf("Enter the value to be pushed:");
scanf("%d",&item);
push(item);
break;

case 02:
item=pop();
if(item!=-1)
printf("The popped item is:%d\n",item);
break;

case 03:
exit(0);

case 04:
display();
break;
}
}
while(9);
return 0;
}
void push(int x)
{
if(sp==SIZE-1)
printf("The stack is full");
else
{
sp++;
stk[sp]=x;
}
}
int pop()
{
int x;
if(sp==-1)
{
printf("The stack is empty");
return -1;
}
else
{
return stk[sp--];
}
}
void display() {
if(sp == -1) {
printf("The stack is empty\n");
}
else
{
printf("Stack elements are:\n");
for(int i = sp; i >= 0; i--) {
printf("%d\n", stk[i]);
}
    }
}

