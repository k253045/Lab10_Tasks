#include <stdio.h>

struct Salary {
    float basic;
    float bonus;
    float deduction;
};

struct Employee {
    int id;
    char name[50];
    struct Salary salary;
};

float calculateNetSalary(struct Salary s) {
    return s.basic + s.bonus - s.deduction;
}

void displayEmployee(struct Employee e) {
    float net = calculateNetSalary(e.salary);
    printf("Employee ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Basic Pay: %.2f\n", e.salary.basic);
    printf("Bonus: %.2f\n", e.salary.bonus);
    printf("Deductions: %.2f\n", e.salary.deduction);
    printf("Net Salary: %.2f\n", net);
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar();

    struct Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Employee ID: ");
        scanf("%d", &employees[i].id);
        getchar();

        printf("Enter Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);

        printf("Enter Basic Pay: ");
        scanf("%f", &employees[i].salary.basic);

        printf("Enter Bonus: ");
        scanf("%f", &employees[i].salary.bonus);

        printf("Enter Deduction: ");
        scanf("%f", &employees[i].salary.deduction);
        getchar();
    }

    printf("Employee Salary Details\n");
    for (int i = 0; i < n; i++) {
        displayEmployee(employees[i]);
    }

    return 0;
}



