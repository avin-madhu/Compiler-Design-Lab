#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int n;

void input();
void check();
void change(int p, char *res);
void output();

struct expression{
    char op1[10],op[2],op2[10],res[10];
    int folded;
}arr[10];

int main(){
    input(); check(); output();
    return 0;
}

void input(){
    printf("Enter the number of expression: ");
    scanf("%d", &n);
    printf("Enter the expression: \n");
    for(int i=0;i<n;i++){
        scanf("%s %s %s %s", arr[i].op1, arr[i].op, arr[i].op2, arr[i].res);
        arr[i].folded = 0;
    }
}
void check(){
    for(int i=0;i<n;i++){
        if((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || strcmp("=", arr[i].op) == 0){
            int result;
            int operand1 = atoi(arr[i].op1);
            int operand2 = atoi(arr[i].op2);
            char operand = arr[i].op[0];
            switch(operand){
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break; 
            }
            arr[i].folded = 1;
            char res_char[5];
            sprintf(res_char, "%d", result);
            change(i,res_char);
        }
    }
}

void change(int p, char *res){
    for(int i=p+1;i<n;i++){
        if(strcmp(arr[i].op1, arr[p].res)==0)
            strcpy(arr[i].op1, res);
        if(strcmp(arr[i].op2, arr[p].res)==0)
            strcpy(arr[i].op2, res);
    }
}

void output(){
    printf("\noptimized code: \n");
    for(int i=0;i<n;i++){
        if(arr[i].folded == 0)
            printf("%s %s %s %s\n", arr[i].op1, arr[i].op, arr[i].op2, arr[i].res);
    }
}