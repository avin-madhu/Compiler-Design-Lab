/* A program to read a source code and identify the tokens in it and the print the information, the program ignores single and multiline comments. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int isSpecialSymbol(char ch)
{
    if (ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == ';' || ch == ':' || ch == '"' || ch == '<' || ch == '>' || ch == '#' || ch == '=')
    {
        return 1;
    }
    return 0;
}

int main()
{
    FILE *input;
    input = fopen("input.txt", "r");
    int no_of_tokens = 1;
    int line_number = 1;
    int i = 0;
    int isString = 0;
    int flag = 0; // to check wether keyword or identifiers
    char word[30];
    char ch; // to read each charcter
    char keywords[30][30] = {"int", "main", "stdio", "include", "printf", "while", "for", "return"};

    printf("LineNo:\t\tTokenNo:\t\tToken\t\tLexeme\n");

    while ((ch = fgetc(input)) != EOF)
    {
        i = 0;
        if (isOperator(ch))
        {
            // to check for comments
            if (ch == '/')
            {
                char next = fgetc(input);
                // for single line comments
                if (next == '/')
                {
                    while ((ch = fgetc(input)) != '\n' && ch != EOF)
                    {
                        // skip the characters in the comments
                    }
                }
                // for multine comments
                else if(next == '*')
                {
                    while(1)
                    {
                       ch = fgetc(input);
                       if(ch == '*' && fgetc(input) == '/')
                       {
                          break;
                       }
                       if(ch == '\n')
                       {
                          line_number++;
                       }
                    }
                }
            }
            else
            {
                // for normal / operation
                ungetc(ch, input);
                printf("%d\t\t%d\t\tOperator\t\t%c \n", line_number, no_of_tokens, ch);
                no_of_tokens++;
            }
        }
        else if (isSpecialSymbol(ch))
        {
            // to notify a string has a started 
            if (ch == '"')
            {
                // if 1 it changes to 0 and viceversa
                isString = (1 + isString) % 2;
            }
            printf("%d\t\t%d\t\tSpecial Symbol\t\t%c \n", line_number, no_of_tokens, ch);
            no_of_tokens++;
        }
        else if (isdigit(ch))
        {
            printf("%d\t\t%d\t\tdigit\t\t\t%c \n", line_number, no_of_tokens, ch);
            no_of_tokens++;
        }
        else if (isalpha(ch))
        {
            word[i] = ch;
            while (isalnum(ch) && ch != ' ' && !isSpecialSymbol(ch))
            {
                word[i++] = ch;
                ch = fgetc(input);
            }

            if (isSpecialSymbol(ch))
            {
                ungetc(ch, input);
            }
            word[i] = '\0';
            char temp[30];
            for (int i = 0; word[i] != '\0'; i++)
            {
                if (strcmp(keywords[i], word) == 0)
                {
                    flag = 1;
                    strcpy(temp, keywords[i]);
                    break;
                }
            }

            if (flag)
            {
                printf("%d\t\t%d\t\tKeyword\t\t\t%s\n", line_number, no_of_tokens, temp);
                no_of_tokens++;
                flag = 0;
            }
            else
            {
                if (isString)
                {
                    printf("%d\t\t%d\t\tString\t\t\t%s\n", line_number, no_of_tokens, word);
                    no_of_tokens++;
                }
                else
                {
                    printf("%d\t\t%d\t\tIdentifier\t\t%s\n", line_number, no_of_tokens, word);
                    no_of_tokens++;
                }
            }
        }
        if (ch == '\n')
        {
            line_number++;
        }
    }

    fclose(input);
    return 0;
}
