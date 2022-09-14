#include<stdio.h>
#include<string.h>
int alpha(char a);
int oper(char b);
int prior(char a);
void main()
{
char infix[25],postfix[25],stack[25];
int in=-1,tops=-1,topp=-1,len;
clrscr();
printf("Enter the INFIX expression:");
scanf("%s",&infix);
printf("\n\nstack\t\tpostfix\n");
stack[++tops]='(';
len=strlen(infix);
infix[len]='#';
while(infix[++in]!='#')
{
if(alpha(infix[in]))
{
postfix[++topp]=infix[in];
}
else if(oper(infix[in]))
{
if(prior(infix[in])<prior(stack[tops]))
{
while(stack[tops]!='(')
{
postfix[++topp]=stack[tops--];
}
}
stack[++tops]=infix[in];
}
else if(infix[in]==')')
{
while(stack[tops]!='(')
{
postfix[++topp]=stack[tops--];
}
tops--;
}
else if(infix[in]=='(')
{
stack[++tops]=infix[in];
}
postfix[++topp]='\0';
stack[++tops]='\0';
printf("%s\t\t%s\n",stack,postfix);
--topp;
--tops;
}
while(stack[tops]!='(')
{
postfix[++topp]=stack[tops--];
}
postfix[++topp]='\0';
stack[tops]='\0';
printf("THE POSTFIX EXPRESSION IS:%s\n",postfix);
getch();
}
int alpha(char ch)
{
if((ch>='a'&&(ch)<='z')||((ch)>='A'&&(ch)<='Z'))
{
return 1;
}
return 0;
}
int oper(char a)
{
int b=0;
switch(a)
{
case'+':
case'-':
case'*':
case'/':
b=1;
break;
}
return b;
}
int prior(char a)
{
int b=0;
switch(a)
{
case'+':
case'-':
b=1;
break;
case'*':
case'/':
b=2;
break;
}
return b;
}
