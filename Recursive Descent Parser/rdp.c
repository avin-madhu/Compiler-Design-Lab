// C program to Construct a recursive descent parsing for
// the following grammar
// E->TE’
// E’->+TE'/@
// T->FT’
// T’->*FT’/@
// F->(E)/id 

//where @ represents null character

#include <stdio.h>
char input[100];
int i=0;

int E();
int T();
int EP();
int TP();
int F();

int main()
{
    printf("Enter the input string: ");
    scanf("%s", input);

    if(E() && input[i] == '\0')
       printf("The string is accepted!");
    else
       printf("The string is rejected!");
    return 0;
}


int E()
{
   if(T())
   {
     return EP();
   }
   else
     return 0;
}

int T()
{
  if(F())
  {
    return TP();
  }
  else
    return 0;
}

int TP()
{
   if(input[i] == '*')
   {
     i++;
     if(F())
        return TP();
     else
        return 0;
   }
   else
     return 1;
}

int EP()
{
   if(input[i] == '+')
   {
     i++;
     if(T())
        return EP();
     else
        return 0;
   }
   else
     return 1;
}

int F()
{
    if(input[i] == '(')
    {
        i++;
        if(E())
        {
            if(input[i] == ')')
            {
                i++;
                return 1;
            }
            else
              return 0;
        }
        else 
           return 0;
    }
    else if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
    {
       i++;
       return 1;
    }
    else
       return 0;
}