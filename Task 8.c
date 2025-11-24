#include <stdio.h>

const float METER_TO_KM = 0.001;

float convertToKm(float meters) {
    static int count = 0;
    count++;

    printf("Function called %d times\n", count);

    return meters * METER_TO_KM;
}

int main() {
    float m;
    float km;

    printf("Enter distance in meters: ");
    scanf("%f", &m);

    km = convertToKm(m);
    printf("%.2f meters = %.4f kilometers\n", m, km);

    printf("Enter another value in meters: ");
    scanf("%f", &m);

    km = convertToKm(m);
    printf("%.2f meters = %.4f kilometers\n", m, km);

    return 0;
}




