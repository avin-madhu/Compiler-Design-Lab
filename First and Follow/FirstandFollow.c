#include <stdio.h>
#include <string.h>
#include <ctype.h>
int n,r,p;
char productions[30][30],nl,input,result[30],already_printed[10];
int already_printed_result(char c)
{
   for(int i=0;i<p;i++)
   {
      if(already_printed[i] == c)
         return 1;
   }
   return 0;
}
void add_to_result(char c)
{
  for(int i=0;i<r;i++)
  {
    if(result[i] == c)
        return;
  }
  result[r++] = c;
}
void first(char c)
{
  if(!isupper(c))
  {
     add_to_result(c);
     return;
  }
  for(int i=0;i<n;i++)
  {
    if(productions[i][0] == c)
    {
      if(productions[i][2] == c)
         continue;
      else if(!isupper(productions[i][2]))
         add_to_result(productions[i][2]);
      else
         first(productions[i][2]);
    }
  } 
}
void follow(char c)
{
  if(productions[0][0] == c)
     add_to_result('$');
  for(int i=0;i<n;i++)
  {
    for(int j=2;j<strlen(productions[i]);j++)
    {
      if(productions[i][j] == c)
      {
        if(productions[i][j+1] == '\0')
           follow(productions[i][0]);
        else if (productions[i][j+1] == c)
           continue;
        else if(!isupper(productions[i][j+1]) && productions[i][j] != '#')
           add_to_result(productions[i][j+1]);
        else
           first(productions[i][j+1]);
      }
    }
  }
}
int main()
{
   printf("Enter the number of productions: ");
   scanf("%d",&n);
   printf("Enter the productions: \n\n");
   for(int i=0;i<n;i++)
   {
    scanf("%s%c", productions[i],&nl);
   }
   printf("\n");
   p=0;
   for(int i=0;i<n;i++)
   {
      input = productions[i][0];
      if(!already_printed_result(input))
      {
         r=0;
         first(input);
         printf("First of %c: ",input);
         for(int i=0;i<n;i++)
         {
            printf("%c ",result[i]);
         }
         already_printed[p++] = input;
         printf("\n");
      }
   }
   p=0;
   printf("==================\n");
   strcpy(result,"");
   for(int i=0;i<n;i++)
   {
      input = productions[i][0];
      if(!already_printed_result(input))
      {
         r=0;
         follow(input);
         printf("Follow of %c: ",input);
         for(int i=0;i<n;i++)
         {
            printf("%c ",result[i]);
         }
         already_printed[p++] = input;
         printf("\n");
      }
   }
   return 0;
}