#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0

void addCities(int maxCities,char cityNames[][30],int *cityCount);
void renameCity(char cityNames[][30],int cityCount);
void removeCity(char cityNames[][30],int *cityCount);
void displayCities(char cityNames[][30],int cityCount);
void inputDistance(int distance[][MAX_CITIES],int cityCount,char cityNames[][30]);
int main()
{
    char cityNames[MAX_CITIES][30];
    int cityCount=0;
    int distance[MAX_CITIES][MAX_CITIES];
    int choice,c2;
    do
    {
        printf("\n----Logistics Management System----\n");
        printf("1.Manage Cities\n");
        printf("2. Manage Distances\n");
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
                printf("4.Show Cities\n");
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
                case 4:
                    displayCities(cityNames, cityCount);
                    break;
                case 5:
                    break;
                default:
                    printf("Invalid choice!\n");
                }
            }
            while(c2!=5);
            break;
        case 2:
            if (cityCount < 2)
            {
                printf("\nAdd at least 2 cities first.\n");
                break;
            }
            do
            {
                printf("\n---Distance Management---\n");
                printf("1. Input/Edit Distance\n");
                printf("3. Back\n");
                printf("Enter choice: ");
                scanf("%d", &c2);

                switch (c2)
                {
                case 1:
                    inputDistance(distance, cityCount, cityNames);
                    break;
                case 3:
                    break;
                default:
                    printf("Invalid choice!\n");
                }
}
            while (c2 != 3);
            break;
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
void renameCity(char cityNames[][30],int cityCount){
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
void displayCities(char cityNames[][30],int cityCount){
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
void inputDistance(int distance[][MAX_CITIES],int cityCount,char cityNames[][30]){
    int c1,c2,dist;
    displayCities(cityNames,cityCount);
    printf("Enter city number:");
    scanf("%d",&c1);
    printf("Enter destination city number:");
    scanf("%d",&c2);
    if (c1 < 1 || c1 > cityCount || c2 < 1 || c2 > cityCount || c1 == c2)
    {
        printf("Invalid!\n");
        return;
    }
    printf("Enter distance between %s and %s (km):",cityNames[c1-1],cityNames[c2-1]);
    scanf("%d",&dist);
    if (dist <= 0)
    {
        printf("Distance must be positive.\n");
        return;
    }
    distance[c1 - 1][c2 - 1] = dist;
    distance[c2 - 1][c1 - 1] = dist;
    printf("Distance recorded.\n");
}
