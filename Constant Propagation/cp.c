// constant propagation is basically using a calculated constant instead of actually calculating the constant in the program to avoid unecessary computation.

#include <stdio.h>
#include <math.h>

int main()
{

    int choice;
    float r,pi = floor((22.0/7.0));

    do {
    
    printf("\n");
    printf("\n1. Find the perimeter and Area of a circle without constant propagation");
    printf("\n2. Find the perimeter and Area of a circle with constant propagation");
    printf("\n3. Exit");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: 

        printf("Enter th radius: ");
        scanf("%f", &r);
        printf("Perimeter: %0.2f\n", 2 * pi * r);
        printf("Area: %0.2f", pi * r * r);
        break;

        case 2: 

        printf("Enter th radius: ");
        scanf("%f", &r);
        printf("Perimeter: %0.2f\n", 2 * 3.14 * r);
        printf("Area: %0.2f", 3.14 * r * r);
        break;

    }

    }while (choice != 3);

    return 0;
}