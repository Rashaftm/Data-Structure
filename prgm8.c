#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct node{
int data;
int status;
struct node *next,*point;
};
struct topsort{
int n;
struct topsort *next;
};
struct node *q[SIZE];
int front=0,rear=0;
struct node *g=0;
struct topsort *tsort=0;
void addvertex(int n)
{
struct node *t=(struct node *)malloc(sizeof(struct node));
t->data=n;
t->status=0;
t->point=0;
t->next=g;
g=t;
}
struct node *find(int n)
{
struct node *t=g;
while (t!=0 && t->data!=n)
t=t->next;
return t;
}
void addedge(int u,int v)
{
struct node *v1,*v2,*t;
v1=find(u);
v2=find(v);
if(v1==0 || v2==0)
{
printf("Vertex not Found\n");
return;
}
t=(struct node *)malloc(sizeof(struct node));
t->next=v1->point;
v1->point=t;
t->point=v2;
return;
}
void printgraph()
{
struct node *t1,*t2,*t3;
printf("\nVertex\tEdge List\n");
t1=g;
while(t1!=0)
{
printf("\n%d..\t",t1->data);
t2=t1->point;
while(t2!=0)
{
t3=t2->point;
printf("%d,",t3->data);
t2=t2->next;
}
t1=t1->next;
}
}
void topsorting(int n)
{
struct topsort *z=(struct topsort *)malloc(sizeof(struct topsort));
z->n=n;
z->next=tsort;
tsort=z;
}
void topsortout()
{
struct topsort *t=tsort;
while(t!=0)
{
printf("%d,",t->n);
t=t->next;
}
}
void dfs_visit(struct node * u)
{
struct node *t,*t1;
u->status=1;
printf("%d,",u->data);
t=u->point;
while(t!=0)
{
t1=t->point;
if(t1->status==0)
dfs_visit(t1);
t=t->next;
}
topsorting(u->data);
return;
}
void dfs(struct node *g1)
{
struct node *t=g;
while(t!=0)
{
t->status=0;
t=t->next;
}
if(g1==0)
{
printf("Vertex not found");
return;
}
tsort=0;
dfs_visit(g1);
}
void enque(struct node *s)
{
int r1=rear;
r1=(r1+1)%SIZE;
if(front==r1)
{
printf("Queue is full..");
exit(1);
}
rear=r1;
q[rear]=s;
}
int emptyq()
{
if (front==rear)
return 1;
else
return 0;
}
struct node *deque()
{
if(emptyq())
{
printf("Empty Queue..");
exit(2);
}
front=(front+1)%SIZE;
return q[front];
}
void bfs(struct node *s)
{
struct node *t=g,*t1,*u;
while(t!=0)
{
t->status=0;
t=t->next;
}if(s==0)
{
printf("Vertex not found");
return;
}
front=0;
rear=0;
s->status=1;
printf("%d,",s->data);
enque(s);
while(!emptyq())
{
u=deque();
t=u->point;
while(t!=0)
{
t1=t->point;
if(t1->status==0)
{
printf("%d,",t1->data);
t1->status=1;
enque(t1);
}
t=t->next;
}
}
}
int main()
{
int ch,n,u,v;
do
{
printf("\n1.Add Vertex\n2.Add Edge\n3.Display Graph\n4.DFS Traversal\n5.BFS Traversal\n6.Topological Sorting\n7.Exit");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 01:
printf("Enter vertex:");
scanf("%d",&n);
if(find(n)!=0)
printf("Vertex already exist!");
else
{
addvertex(n);
}
break;
case 02:
printf("Enter starting vertex:");
scanf("%d",&u);
scanf("%d",&v);
addedge(u,v);
break;
case 03:
printf("\nThe graph is:\n");
printgraph();
break;
case 04:
printf("\nEnter starting vertex for DFS:");
scanf("%d",&n);
printf("DFS Traversal:");
dfs(find(n));
break;
case 05:
printf("\nEnter starting vertex for BFS:");
scanf("%d",&n);
printf("BFS Traversal:");
bfs(find(n));
break;
case 06:
printf("\nEnter starting vertex for Topological Sort:");
scanf("%d",&n);
dfs(find(n));
printf("\nTopological Sort Order:");
topsortout();
break;
case 07:
printf("\nExiting program...");
break;
}
}
while(ch!=7);
return 0;
}
