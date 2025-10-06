#include<stdio.h>
#include<stdlib.h>
void insertion();
void deletion();
void searching();
void sorting();
void display();
int ar[100];
int num;
int n;
int main()
{
printf("enter the number of elements");
scanf("%d",&num);
for(int i=0;i<num;i++)
{
scanf("%d",&array[i]);
}
printf("the array elements are:");
for(int i=0;i<num;i++)
{
printf("%d\n",array[i]);
}
while(i)
{
printf("enter a option:\n1.insertion\n2.deletion\n3.searching\n4.sorting\n5.display\n6.exit\n");
scanf("%d",&n);
switch(n)
{
case1:
     insertion();
     break;
case2:
     deletion();
     break;
case3:
     searching();
     break;
case4:
     sorting();
     break;
case5:
     display();
     break;
case6:
     exit();
     break;
default:
     printf("invalid option\n");
     break;
}
}
return 0;
}
void insertion()
{
int number;
printf("enter the number to be inserted\n");
scanf("%d",&number);
array[num]=number);
num=num+1;
printf("the array elements are:\n");
for(int i=0;i<num;i++)
{
printf("%d\n"array[i];
}
}


void deletion()
int i,int j;
if(num>0)
{
printf("\n enter the index of the element\n");
scanf("%d",&int);
for(j=int;j<num;j++)
array[j]=array[j]+1;
num=num-1	;
}
else
{
printf("\n array is empty/n");
}
printf("the array elements are:");
for(int i=0;i<num;i++)
{
printf("%d\n",array[i]);
}
}


void searching
{
int num, to search,found,i;
 printf("\n enter element to search:");
scanf("%d",&to search);
found=0;
for(i=0;i<num;i++)
{
if (array[i]==to search)
{
  found=1;
  break;
}
}
if (found==1)
{
printf("\n%d is not found in the array\n",to search);
}
}


void sorting()
{
int i,a,j;
for(i=0;i<num;++i)
{
for(j=i+1;j<num;++j)
{
if(array[i]>array[j])
{
a=array[i];
array[i]=array[j];
array[j]=a;
}
}
}
printf("the numbers arranged in ascending order the given velow\n");
for(i=0;i<num;i++)
{
printf("%d",array[i]);
}
}
void display()
{
int i;
printf("the array elements are:");
for(int i=0;i<num;i++)
{
printf("%d\n",array[i]);
}
}


                                                                            
