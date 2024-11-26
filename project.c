#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICLES 100

typedef struct {
    char name[50];
    char type[30];
    int capacity;
} Vehicle;

Vehicle vehicles[MAX_VEHICLES];
int vehicleCount = 0;

void addVehicle() {
    if (vehicleCount >= MAX_VEHICLES) {
        printf("Vehicle limit reached!\n");
        return;
    }
    
    Vehicle v;
    printf("Enter vehicle name: ");
    scanf("%s", v.name);
    printf("Enter vehicle type: ");
    scanf("%s", v.type);
    printf("Enter vehicle capacity: ");
    scanf("%d", &v.capacity);
    
    vehicles[vehicleCount++] = v;
    printf("Vehicle added successfully!\n");
}

void displayVehicles() {
    if (vehicleCount == 0) {
        printf("No vehicles available.\n");
        return;
    }
    
    printf("\nList of Vehicles:\n");
    for (int i = 0; i < vehicleCount; i++) {
        printf("Name: %s, Type: %s, Capacity: %d\n", vehicles[i].name, vehicles[i].type, vehicles[i].capacity);
    }
}

void searchVehicle() {
    char name[50];
    printf("Enter vehicle name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < vehicleCount; i++) {
        if (strcmp(vehicles[i].name, name) == 0) {
            printf("Vehicle found: Name: %s, Type: %s, Capacity: %d\n", vehicles[i].name, vehicles[i].type, vehicles[i].capacity);
            return;
        }
    }
    
    printf("Vehicle not found.\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\nTransportation System Menu:\n");
        printf("1. Add Vehicle\n");
        printf("2. Display Vehicles\n");
        printf("3. Search Vehicle\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                displayVehicles();
                break;
            case 3:
                searchVehicle();
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}