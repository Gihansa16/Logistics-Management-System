#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0

int main()
{
 int choice,c2;

    do
    {
        printf("\n----Logistics Management System----\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            do
            {
                printf("\n---City Management---\n");
                printf("5.Back\n");
                printf("Enter choice:");
                scanf("%d",&c2);

                switch(c2)
                {
                case 5:
                    break;
                default:
                    printf("Invalid choice!\n");
                }
            }
            while(c2!=5);

        case 6:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    }
    while(choice!=6);

    return 0;
}
