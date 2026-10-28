#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild, *rchild;
};
void main()
{
struct node *insert(struct node*,int);
struct node *search(struct node*,int);
void inorder(struct node *);
struct node *delete(struct node*,int);
struct node *root=0;
struct node *result=0;
int opt,data;
do{
printf("\n1.INSERT\n2.SEARCH\n3.INORDER TRAVERSAL\n4.DELETE\n5.EXIT\n");
printf("Enter your choice:");
scanf("%d",&opt);
switch(opt)
{
case 01:
printf("\nEnter the data to insert:");
scanf("%d",&data);
root=insert(root,data);
break;
case 02:
printf("Enter data to search:");
scanf("%d",&data);
result=search(root,data);
if(result!=NULL)
printf("%d found in the tree",data);
else
printf("%d not found!",data);
break;
case 03:
if(root==0)
printf("\nThe tree is empty!");
else
{
printf("Inorder traversal:");
inorder(root);
}
printf("\n");
break;
case 04:
printf("Enter data to delete:");
scanf("%d",&data);
root=delete(root,data);
break;

case 05:
exit(0);
break;
}}while(opt !=5);
return;
}
struct node *search(struct node *root,int data)
{
while(root!=0 && root->data!=data)
if(data<root->data)
root=root->lchild;
else
root=root->rchild;
return root;
}
struct node *insert(struct node *root,int data)
{
struct node *t,*par=0,*t1;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
t->lchild=t->rchild=0;
if(root==0)
root=t;
else if(search(root,data)!=0)
printf("%d is duplicate",data);
else
{
t1=root;
while(t1!=0)
{
par=t1;
if(data<t1->data)
t1=t1->lchild;
else
t1=t1->rchild;
}
if(data<par->data)
par->lchild=t;
else
par->rchild=t;
}
return root;
}
void inorder(struct node *root)
{
if(root!=0)
{
inorder(root->lchild);
printf("%d ",root->data);
inorder(root->rchild);
}
}
struct node *delete(struct node *root,int data)
{
struct node *t=root,*par=0,*suc,*sucpar;
while(t!=0 && t->data!=data)
{
par=t;
if(data<t->data)
t=t->lchild;
else
t=t->rchild;
}
if(t==0)
printf("%d not found!",data);
else
{
if(t->lchild==0 && t->rchild==0)
{
if(par==0)
root=0;
else if(data<par->data)
par->lchild=0;
else
par->rchild=0;
}
else if(t->lchild==0 || t->rchild==0)
{
if(par==0)
root=root->lchild==0 ? root->rchild:root->lchild;
else if(data<par->data)
par->lchild=t->lchild==0 ? t->rchild:t->lchild;
else
par->rchild=t->lchild==0 ? t->rchild:t->lchild;
}
else
{
sucpar=t;
suc=t->rchild;
while(suc->lchild!=0)
{
sucpar=suc;
suc=suc->lchild;
}
t->data=suc->data;
if(suc->data<sucpar->data)
sucpar->lchild=suc->rchild;
else
sucpar->rchild=suc->rchild;
t=suc;
}
free(t);
}
return root;
}
