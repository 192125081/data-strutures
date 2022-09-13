#include<stdio.h>
void main()
{
struct date
{
int day;
int month;
int year;
};
struct details
{
char name[20];
int price;
int code;
int qty;
struct date mfg;
};
struct details item[50];
int n,i;
printf("\n Enter number of items");
scanf("%d",&n);
fflush(stdin);
for(i=0;i<n;i++)
{
fflush(stdin);
printf("\n Item name");
scanf("%s",item[i].name);
fflush(stdin);
printf("\n Item code");
scanf("%d",&item[i].code);
fflush(stdin);
printf("\n Quantity");
scanf("%d",&item[i].qty);
fflush(stdin);
printf("\n Price");
scanf("%d",&item[i].price);
fflush(stdin);
printf("\n Manufacturing date(dd-mm-yyyy");
scanf("%d%d%d",&item[i].mfg.day,&item[i].mfg.month,&item[i].mfg.year);
}
printf("\n********* INVENTORY******");
printf("\n---------------------");
printf("\n S.No. NAME CODE QUANTITY PRICE MFG.DATE");
printf("\n -----------------------");
for(i=0;i<n;i++)
printf("\n%d,%s,%d,%d,%d,%d,%d,%d",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].mfg.day,item[i].mfg.month,item[i].mfg.year);
printf("\n ---------------------------------");
getch();
}

