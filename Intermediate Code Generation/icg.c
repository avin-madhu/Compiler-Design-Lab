#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int i = 1, j = 0, no = 0, tmpch = 90;

char str[100], left[15], right[15];

void find_operator();
void process();
void find_left_operand(int);
void find_right_operand(int);

struct exp {
    int pos;
    char op;
} k[15];

void clear(char arr[])
{
    for(int i=0;i<sizeof(arr);i++)
    {
       arr[i] = '\0';  
    }
}

int main() {
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression :");
    scanf("%s", str);
    printf("The intermediate code:\n");
    find_operator();
    process();
    return 0;
}

void find_operator() {
    
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '*' || str[i] == '/')
        {
            k[j].pos = i;
            k[j++].op = str[i];
            no++;
        }

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '+' || str[i] == '-')
        {
            k[j].pos = i;
            k[j++].op = str[i];
            no++;
        }
}

void process() {
    i = 0;
    while (i < j) {
        find_left_operand(k[i].pos);
        find_right_operand(k[i].pos);
        str[k[i].pos] = tmpch--; 
        printf("\t%c := %s%c%s\t\t", str[k[i].pos], left, k[i].op, right);
        printf("\n");
        i++;
    }
}

void find_left_operand(int x) {
    clear(left);
    int w = 0, flag = 0;
    x--;

    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' &&
           str[x] != '\0' && str[x] != '-' && str[x] != '/' && str[x] != ':') {
        if (str[x] != '$' && flag == 0) {
            left[w++] = str[x];
            left[w] = '\0';
            str[x] = '$'; 
            flag = 1;
        }
        x--;
    }
}

void find_right_operand(int x) {
    clear(right);
    int w = 0, flag = 0;
    x++;

    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '\0' &&
           str[x] != '=' && str[x] != ':' && str[x] != '-' && str[x] != '/' && j != strlen(str)+1) {
        if (str[x] != '$' && flag == 0) {
            right[w++] = str[x];
            right[w] = '\0';
            str[x] = '$';  
            flag = 1;
        }
        x++;
    }
}
