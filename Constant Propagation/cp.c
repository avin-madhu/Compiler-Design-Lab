// constant propagation is basically using a calculated constant instead of actually calculating the constant in the program to avoid unecessary computation.
#include <stdio.h>
int choice;
float r, perimeter;
float PI = ((22.0/7.0)/100)*100*1; //  heavy calculation 
int main()
{ 
  do 
  {
    printf("\n\n");
    printf("1. Perimeter of a circle using constant propagation\n");
    printf("2. Permieter of a circle without using constant propagation\n");
    printf("3. exit\n\n");
    printf("Enter your option: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
      
      printf("\n\nEnter the radius: ");
      scanf("%f",&r);
      perimeter = 2 * PI * r; // used the calculated value 
      printf("Area: %0.2f",perimeter);
      break;
      
      case 2:
      
      printf("\n\nEnter the radius: ");
      scanf("%f",&r);
      perimeter = 2 * 3.14 * r; // used the constant directly 
      printf("Area: %0.2f",perimeter);
      break;
      
      case 3: break;
      
      default: 
      printf("\nInvalid Input!\n");
    }
  
  }while(choice != 3);
  
 return 0;
}
