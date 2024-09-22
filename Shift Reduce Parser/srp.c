#include <stdio.h>
#include <string.h>
char input_string[26], action[20], stack[30], act[10];
int input_length, j=0,i=0;
void check();
int main()
{
  puts("GRAMMAR is: \n\nE->E+E\nE->E*E\nE->(E)\nE->id");
  puts("Enter the string: ");
  gets(input_string);
  printf("\n");
  input_length = strlen(input_string);
  strcpy(action, "SHIFT ->");
  puts("Stack\tinput\taction");
  for(i=0;j<input_length;i++,j++)
  {
    if(input_string[j] == 'i' && input_string[j+1] == 'd')
    {
        stack[i] = input_string[j];
        stack[i+1] = input_string[j+1];
        stack[i+2] = '\0';
        input_string[j] = ' ';
        input_string[j+1] = ' ';
        printf("\n$%s\t%s\t%s id", stack, input_string, action); 
        check();
    }
    else
    {
        stack[i] = input_string[j];
        stack[i+1] = '\0';
        input_string[j] = ' ';
        printf("\n$%s\t%s\t%s %c", stack, input_string, action, stack[i]);
        check();
    }
  }
  return 0;
}

void check()
{
    strcpy(act, "REDUCE TO E");
    for(int k=0;k< input_length;k++)
    {
        if(stack[k]=='i' && stack[k+1] == 'd')
        {
            stack[k] = 'E';
            stack[k+1] = '\0';
            printf("\n$%s\t%s\t%s", stack, input_string, act);
            j++;
        }
    }
    for(int k=0;k< input_length;k++)
    {
        if(stack[k]=='E' && stack[k+1] == '+' && stack[k+2] == 'E')
        {
            stack[k] = 'E';
            stack[k+1] = '\0';
            stack[k+2] = '\0';
            printf("\n$%s\t%s\t%s", stack, input_string, act);
            i-=2;
        }
    }
    for(int k=0;k< input_length;k++)
    {
        if(stack[k]=='E' && stack[k+1] == '*' && stack[k+2] == 'E')
        {
            stack[k] = 'E';
            stack[k+1] = '\0';
            stack[k+2] = '\0';
            printf("\n$%s\t%s\t%s", stack, input_string, act);
            i-=2;
        }
    }
    for(int k=0;k< input_length;k++)
    {
        if(stack[k] == '(' && stack[k+1] == 'E' && stack[k+2] == ')')
        {
            stack[k] = 'E';
            stack[k+1] = '\0';
            stack[k+2] = '\0';
            printf("\n$%s\t%s\t%s", stack, input_string, act);
            i-=2;
        }
    }
}