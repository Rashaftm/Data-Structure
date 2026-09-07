//Read two arrays sort them and merge it into a single array
#include<stdio.h>
void main()
{
void read(int[],int);
void print(int[],int);
void sort(int[],int);
void merge(int[],int[],int[],int,int);
int a[20],b[20],c[40],n1,n2;
printf("\nNumber of elements in first array[1-20]:");
scanf("%d",&n1);
read(a,n1);
printf("\nNumber of elements in second array[1-20]:");
scanf("%d",&n2);
read(b,n2);
sort(a,n1);
sort(b,n2);
merge(a,b,c,n1,n2);
printf("\nFirst array sorted:\n");
print(a,n1);
printf("\nSecond array sorted:\n");
print(b,n2);
printf("\nIn merged array:\n");
print(c,n1+n2);
}
void read(int ar[],int n)
{
int i;
printf("\nEnter %d elements:",n);
for(i=0;i<n;i++)
scanf("%d,",&ar[i]);
return;
}
void sort(int ar[],int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
if(ar[i]>ar[j])
{
temp=ar[i];
ar[i]=ar[j];
ar[j]=temp;
}
return;
}
void merge(int ar1[],int ar2[],int ar3[],int n1,int n2)
{
int i=0,j=0,k=0;
while(i<n1 && j<n2)
if(ar1[i]<ar2[j])
ar3[k++]=ar1[i++];
else
ar3[k++]=ar2[j++];
while(i<n1)
ar3[k++]=ar1[i++];
while(j<n2)
ar3[k++]=ar2[j++];
return;
}
void print(int ar[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d,",ar[i]);
return;
}
