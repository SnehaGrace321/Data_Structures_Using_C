#include<stdio.h>
#include<string.h>
#define MAX_EMPLOYEES 100
struct Employee{
    int eno;         
    char ename[50]; 
    float esal;     
    int dno;         
};
void readEmployees(struct Employee emp[], int n) {
	int i;
    for(i=0; i < n; i++) {
        printf("Enter details for employee %d\n");
        printf("Employee Number: ");
        scanf("%d", &emp[i].eno);
        printf("Employee Name: ");
        scanf("%s", emp[i].ename);
        printf("Employee Salary: ");
        scanf("%f", &emp[i].esal);
        printf("Department Number: ");
        scanf("%d", &emp[i].dno);
        printf("\n");
    }
}
void displayEmployees(struct Employee emp[], int n) {
    printf("\nEmployee Details:\n");
    int i;
    for(i = 0; i < n; i++) {
        printf("Employee Number: %d, Name: %s, Salary: %.2f, Department Number: %d\n", 
                emp[i].eno, emp[i].ename, emp[i].esal, emp[i].dno);
    }
}
void searchEmployeeByNo(struct Employee emp[], int n, int eno) {
    int found = 0;
    int i;
    for(i = 0; i < n; i++) {
        if (emp[i].eno == eno) {
            printf("Employee found: Employee Number: %d, Name: %s, Salary: %.2f, Department Number: %d\n", 
                    emp[i].eno, emp[i].ename, emp[i].esal, emp[i].dno);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with number %d not found.\n", eno);
    }
}
void sortEmployeesByName(struct Employee emp[], int n) {
    struct Employee temp;
    int i,j;
    for(i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(emp[i].ename, emp[j].ename) > 0) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}
void sortEmployeesBySalary(struct Employee emp[], int n) {
    struct Employee temp;
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (emp[i].esal > emp[j].esal) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}
int deleteEmployeeByNo(struct Employee emp[], int n, int eno) {
    int found = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (emp[i].eno == eno) {
            found = 1;
            int j;
            // Shift the remaining employees left
            for (j = i; j < n - 1; j++) {
                emp[j] = emp[j + 1];
            }
            n--;  // Reduce the employee count
            break;
        }
    }
    if (!found) {
        printf("Employee with number %d not found.\n", eno);
    } else {
        printf("Employee with number %d deleted successfully.\n", eno);
    }
    return n;  // Return the new number of employees
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int n, choice, eno;

    printf("Enter the number of employees: ");
    scanf("%d", &n);
    readEmployees(employees, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Search employee by number\n");
        printf("2. Sort employees by name\n");
        printf("3. Sort employees by salary\n");
        printf("4. Delete employee by number\n");
        printf("5. Display all employees\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter employee number to search: ");
                scanf("%d", &eno);
                searchEmployeeByNo(employees, n, eno);
                break;
            case 2:
                sortEmployeesByName(employees, n);
                printf("Employees sorted by name.\n");
                displayEmployees(employees, n);
                break;
            case 3:
                sortEmployeesBySalary(employees, n);
                printf("Employees sorted by salary.\n");
                displayEmployees(employees, n);
                break;
            case 4:
                printf("Enter employee number to delete: ");
                scanf("%d", &eno);
                n = deleteEmployeeByNo(employees, n, eno);
                break;
            case 5:
                displayEmployees(employees, n);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

