#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Flight {
    char flightNumber[10];
    char departureCity[30];
    char destinationCity[30];
    struct Date date;
    int availableSeats;
};

int main() {
    struct Flight f;

    printf("Enter flight number: ");
    scanf("%s", f.flightNumber);

    printf("Enter departure city: ");
    scanf("%s", f.departureCity);

    printf("Enter destination city: ");
    scanf("%s", f.destinationCity);

    printf("Enter date: ");
    scanf("%d %d %d", &f.date.day, &f.date.month, &f.date.year);

    printf("Enter available seats: ");
    scanf("%d", &f.availableSeats);

    printf("Flight Details \n");
    printf("Flight Number: %s\n", f.flightNumber);
    printf("From: %s\n", f.departureCity);
    printf("To: %s\n", f.destinationCity);
    printf("Date: %02d/%02d/%04d\n", f.date.day, f.date.month, f.date.year);
    printf("Available Seats: %d\n", f.availableSeats);

    if (f.availableSeats > 0) {
        f.availableSeats--;
        printf("Seat booked successfully!\n");
    } else {
        printf("No seats available!\n");
    }

    printf("Seats left: %d\n", f.availableSeats);

    return 0;
}



