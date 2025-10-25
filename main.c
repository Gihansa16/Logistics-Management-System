#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0
typedef struct{
    char name[20];
    int capacity;
    double ratePerKm,speed,efficiency;
}Vehicle;

typedef struct{
    int source,destination,vehicleType;
    double distance,weight,deliveryCost,fuelUsed,fuelCost,operationalCost,profit,customerCharge,timeHrs;
}Delivery;

void addCities(int maxCities,char cityNames[][30],int *cityCount);
void renameCity(char cityNames[][30],int cityCount);
void removeCity(char cityNames[][30],int *cityCount);
void displayCities(char cityNames[][30],int cityCount);
void inputDistance(int distance[][MAX_CITIES],int cityCount,char cityNames[][30]);
void displayDistanceTable(int distance[][MAX_CITIES],int cityCount,char cityNames[][30]);
void showVehicles(Vehicle vehicles[],int size);
void deliveryEstimation(char cityNames[][30],int cityCount,int distance[][MAX_CITIES],Vehicle vehicles[],int vehicleCount,Delivery deliveries[],int *deliveryCount);
void showReports(Delivery deliveries[],int deliveryCount,char cityNames[][30]);
int main()
{
    char cityNames[MAX_CITIES][30];
    int cityCount=0;
    int distance[MAX_CITIES][MAX_CITIES];
    int deliveryCount=0;
    Delivery deliveries[MAX_DELIVERIES];
    for(int i=0;i<MAX_CITIES;i++){
        for(int j=0;j<MAX_CITIES;j++)
        {
            distance[i][j]=(i==j)?0:-1;
        }
    }

    Vehicle vehicles[3]=
    {
        {"Van",1000,30,60,12},
        {"Truck",5000,40,50,6},
        {"Lorry",10000,80,45,4}
    };
    int choice,c2;
    do
    {
        printf("\n----Logistics Management System----\n");
        printf("1.Manage Cities\n");
        printf("2.Manage Distances\n");
        printf("3.Show Vehicles\n");
        printf("4.Delivery Cost Estimation\n");
        printf("5.Reports\n");
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
                printf("1.Input/Edit Distance\n");
                printf("2.Display Distance Table\n");
                printf("3.Back\n");
                printf("Enter choice: ");
                scanf("%d", &c2);

                switch (c2)
                {
                case 1:
                    inputDistance(distance, cityCount, cityNames);
                    break;
                case 2:
                    displayDistanceTable(distance, cityCount, cityNames);
                    break;
                case 3:
                    break;
                default:
                    printf("Invalid choice!\n");
                }
}
            while (c2 != 3);
            break;
        case 3:
            showVehicles(vehicles, 3);
        case 4:
            deliveryEstimation(cityNames, cityCount, distance, vehicles, 3, deliveries, &deliveryCount);
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

void removeCity(char cityNames[][30],int *cityCount){
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
void displayDistanceTable(int distance[][MAX_CITIES],int cityCount,char cityNames[][30]){
    printf("\n------Distance Table (km)------\n");
    for(int i = 0; i < cityCount; i++){
    printf("%-10s", cityNames[i]);
    printf("\n");
    }
    for(int i = 0; i < cityCount; i++)
    {
        printf("%-5s", cityNames[i]);
        for(int j = 0; j < cityCount; j++)
        {
            if(distance[i][j] == -1) printf("%-10s", "-");
            else
            printf("%-10d", distance[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------\n");
}
void showVehicles(Vehicle vehicles[], int size){
    printf("\n---Vehicles---\n");
    printf("%-5s %-10s %-10s %-10s %-10s %-15s\n","ID", "Type", "Cap(kg)", "Rate/km", "Speed", "FuelEff(km/l)");
    for (int i = 0; i < size; i++)
    {
        printf("%-5d %-10s %-10d %-10.2f %-10.2f %-15.2f\n",i + 1, vehicles[i].name, vehicles[i].capacity,vehicles[i].ratePerKm, vehicles[i].speed, vehicles[i].efficiency);
    }
    printf("---------------------------------\n");
}
void deliveryEstimation(char cityNames[][30], int cityCount, int distance[][MAX_CITIES],Vehicle vehicles[], int vehicleCount, Delivery deliveries[], int *deliveryCount){
    if (cityCount < 2)
    {
        printf("Add at least 2 cities first.\n");
        return;
    }
    if (*deliveryCount >= MAX_DELIVERIES)
    {
        printf("Maximum limit reached.\n");
        return;
    }
    displayCities(cityNames, cityCount);
    int src, dest;
    printf("Enter source city number: ");
    scanf("%d", &src);
    printf("Enter destination city number: ");
    scanf("%d", &dest);
    if (src < 1 || dest < 1 || src > cityCount || dest > cityCount || src == dest)
    {
        printf("Invalid city selection!\n");
        return;
    }
    if (distance[src - 1][dest - 1] == -1)
    {
        printf("Distance not defined between cities.\n");
        return;
    }
    showVehicles(vehicles, vehicleCount);
    int vChoice;
    printf("Select vehicle type: ");
    scanf("%d", &vChoice);
    if (vChoice < 1 || vChoice > vehicleCount)
    {
        printf("Invalid choice!\n");
        return;
    }

    double weight;
    printf("Enter cargo weight (kg): ");
    scanf("%lf", &weight);
    Vehicle v = vehicles[vChoice - 1];
    if (weight > v.capacity)
    {
        printf("Weight exceeds %s capacity (%d kg)!\n", v.name, v.capacity);
        return;
    }

    double D = distance[src - 1][dest - 1];
    double R = v.ratePerKm;
    double S = v.speed;
    double E = v.efficiency;
    double deliveryCost = D * R * (1 + weight / 10000.0);
    double timeHrs = D / S;
    double fuelUsed = D / E;
    double fuelCost = fuelUsed * FUEL_PRICE;
    double operationalCost = deliveryCost + fuelCost;
    double profit = deliveryCost * 0.25;
    double customerCharge = operationalCost + profit;

    deliveries[*deliveryCount] = (Delivery)
    {
        src - 1, dest - 1, D, weight, vChoice - 1,deliveryCost, fuelUsed, fuelCost,operationalCost, profit, customerCharge, timeHrs
    };
    (*deliveryCount)++;

    printf("\n=====================================================\n");
    printf("DELIVERY COST ESTIMATION\n");
    printf("-----------------------------------------------------\n");
    printf("From: %s\nTo: %s\n", cityNames[src - 1], cityNames[dest - 1]);
    printf("Distance: %.2f km\nVehicle: %s\nWeight: %.2f kg\n", D, v.name, weight);
    printf("-----------------------------------------------------\n");
    printf("Base Cost: %.2f LKR\nFuel Used: %.2f L\nFuel Cost: %.2f LKR\n",deliveryCost, fuelUsed, fuelCost);
    printf("Operational Cost: %.2f LKR\nProfit: %.2f LKR\nCustomer Charge: %.2f LKR\n",operationalCost, profit, customerCharge);
    printf("Estimated Time: %.2f hours\n", timeHrs);
    printf("=====================================================\n");
}
void showReports(Delivery deliveries[], int deliveryCount, char cityNames[][30]){
    if (deliveryCount == 0)
    {
        printf("\nNo deliveries.\n");
        return;
    }
    double totalDist = 0, totalTime = 0, totalProfit = 0, totalRevenue = 0;
    double longest = -1, shortest = 1e9;
    int longIdx = -1, shortIdx = -1;
    for (int i = 0; i < deliveryCount; i++)
    {
        totalDist += deliveries[i].distance;
        totalTime += deliveries[i].timeHrs;
        totalProfit += deliveries[i].profit;
        totalRevenue += deliveries[i].customerCharge;
        if (deliveries[i].distance > longest)
        {
            longest = deliveries[i].distance;
            longIdx = i;
        }
        if (deliveries[i].distance < shortest)
        {
            shortest = deliveries[i].distance;
            shortIdx = i;
        }
    }

