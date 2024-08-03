#include <stdio.h>
#include <string.h>
#include <ctype.h>

int number_of_productions, choice, r=0;
char productions[30][30], ch, result[30];
void first(char c);
void follow(char c);

void add_to_result(char c)
{
   for(int i=0;i<r;i++)
   {
    if(c == result[i])
    {
      return;
    }
   }
   result[r++] = c;
}

void first(char c)
{
  if(islower(c) || c == '#')
  {
    add_to_result(c);
    return;
  }

  for(int i=0;i<number_of_productions;i++)
  {
    if(productions[i][0] == c)
    {
      if(productions[i][2] == '#')
      {
        add_to_result('#');
      }
      else if (productions[i][2] == c)
      {
        return;
      }
      else if(islower(productions[i][2]))
      {
        add_to_result(productions[i][2]);
      }
      else
      {
         first(productions[i][2]);
      }
    }
  }
}

void follow(char c)
{
   if(productions[0][0] == c)
   {
      add_to_result('$');
   }
   for(int i=0;i<number_of_productions;i++)
   {
    for(int j=2;j<strlen(productions[i]);j++)
    {
      if(productions[i][j] == c)
      {
        if(productions[i][j+1] != '\0')
        {
          first(productions[i][j+1]);
        }
        if(productions[i][j+1] == '\0' && productions[i][0] != c)
        {
          follow(productions[i][0]);
        }
      }
    }
   }
}

int main()
{
  int input;
  printf("Enter the number of productions: ");
  scanf("%d", &number_of_productions);

  printf("Enter the productions: \n");
  for(int i=0;i<number_of_productions;i++)
  {
     scanf("%s%c", &productions[i], &ch);
  }
  do
  {
    r = 0;
    printf("Enter the character: ");
    scanf("%c", &input);
    first(input);
    printf("First(%c): {",input);
    for(int i=0;i<r;i++)
    {
      printf("%c,",result[i]);
    }
    printf("}\n");

    strcpy(result, " ");

    r = 0;
    follow(input);
    printf("Follow(%c): {",input);
    for(int i=0;i<r;i++)
    {
      printf("%c,",result[i]);
    }
    printf("}\n");
    printf("Wanna continue? (1/0): ");
    scanf("%d%c", &choice,&ch);
  } while (choice);
  return 0;
}