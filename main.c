#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0

void addCities(int maxCities,char cityNames[][30],int *cityCount);
void renameCity(char cityNames[][30],int cityCount);
void removeCity(char cityNames[][30],int *cityCount);
int main()
{
    char cityNames[MAX_CITIES][30];
    int cityCount=0;
    int choice,c2;
    do
    {
        printf("\n----Logistics Management System----\n");
        printf("1.Manage Cities\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
    switch(choice){
        case 1:
            do
            {
                printf("\n---City Management---\n");
                printf("1.Add City\n");
                printf("2.Rename City\n");
                printf("3.Remove City\n");
                printf("5.Back\n");
                printf("Enter choice:");
                scanf("%d",&c2);
        switch(c2)
                {
                case 1:
                    addCities(MAX_CITIES,cityNames,&cityCount);
                    break;
                case 2:
                    renameCity(cityNames,cityCount);
                    break;
                case 3:
                    removeCity(cityNames,&cityCount);
                    break;
                case 5:
                    break;
                default:
                    printf("Invalid choice!\n");
                }
            }
            while(c2!=5);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    while(choice!=6);
    return 0;
}
void addCities(int maxCities,char cityNames[][30],int *cityCount){
    char newCity[30];
    int i=0;

    if(*cityCount>=maxCities)
    {
        printf("\nCannot add more cities. Maximum limit reached.\n");
        return;
    }

    printf("\nEnter city name: ");
    scanf(" %[^\n]",newCity);


    while (newCity[i]!='\0')
    {
        cityNames[*cityCount][i] = newCity[i];
        i++;
    }
    cityNames[*cityCount][i] = '\0';
    (*cityCount)++;

    printf("City added successfully!\n");
}

void displayCities(char cityNames[][30], int cityCount)
{
    if (cityCount == 0)
    {
        printf("\nNo cities available.\n");
        return;
    }

    printf("\n------City List------\n");
    for (int i = 0; i < cityCount; i++)
    {
        printf("%d. %s\n", i + 1, cityNames[i]);
    }
    printf("-----------------------\n");
}

void renameCity(char cityNames[][30], int cityCount)
{
    if (cityCount == 0)
    {
        printf("No cities to rename.\n");
        return;
    }

    int index;
    printf("Enter city number to rename: ");
    scanf("%d", &index);

    if (index < 1 || index > cityCount)
    {
        printf("Invalid city number!\n");
        return;
    }

    char newName[30];
    printf("Enter new name: ");
    scanf(" %[^\n]", newName);

    int i = 0;
    while (newName[i] != '\0')
    {
        cityNames[index - 1][i] = newName[i];
        i++;
    }
    cityNames[index - 1][i] = '\0';

    printf("Renamed successfully!\n");
}

void removeCity(char cityNames[][30], int *cityCount)
{
    if (*cityCount == 0)
    {
        printf("No cities to remove.\n");
        return;
    }

    displayCities(cityNames, *cityCount);

    int index;
    printf("Enter city number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > *cityCount)
    {
        printf("Invalid city number!\n");
        return;
    }


    for (int i = index - 1; i < *cityCount - 1; i++)
    {
        int j = 0;
        while (cityNames[i + 1][j] != '\0')
        {
            cityNames[i][j] = cityNames[i + 1][j];
            j++;
        }
        cityNames[i][j] = '\0';
    }

    (*cityCount)--;

    printf("Removed successfully!\n");
}
