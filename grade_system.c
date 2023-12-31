#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CLASSES 9
#define MAX_STUDENTS 60

void enter_grades(int grades[MAX_CLASSES][MAX_STUDENTS], int class, int stud);
void get_grades(int grades[MAX_CLASSES][MAX_STUDENTS], int class, int stud);

int main(void) {
    char ch, s[100];

    int class, stud;
    int grades[MAX_CLASSES][MAX_STUDENTS] = {0}; 

    for (;;) {
        do {
            printf("(E)nter the grades\n");
            printf("(R)eport the grades\n");
            printf("(Q)uit\n");
            fgets(s, sizeof(s), stdin);
            ch = toupper(*s);
        } while (ch != 'E' && ch != 'R' && ch != 'Q');

        switch (ch) {
            case 'E':
                enter_grades(grades, class, stud);
                break;

            case 'R':
                printf("Enter the class:");
                scanf("%d", &class);
                printf("Enter the student's Roll No:");
                scanf("%d", &stud);
                get_grades(grades, class, stud);
                break;

            case 'Q':
                exit(0);
                break;
        }
    }
    return 0;
}

void enter_grades(int grades[MAX_CLASSES][MAX_STUDENTS], int class, int stud) {
    int marks;
    printf("Enter the class:");
    scanf("%d", &class);
    printf("Enter the student's Roll No:");
    scanf("%d", &stud);
    printf("Enter the student's marks:");
    scanf("%d", &marks);

    if (class >= 0 && class < MAX_CLASSES && stud >= 0 && stud < MAX_STUDENTS) {
        grades[class][stud] = marks;
    } else {
        printf("Invalid class or student index\n");
    }
}

void get_grades(int grades[MAX_CLASSES][MAX_STUDENTS], int class, int stud) {
    if (class >= 0 && class < MAX_CLASSES && stud >= 0 && stud < MAX_STUDENTS) {
        printf("The marks of the student of Roll No.%d from class %d is: %d\n", stud, class, grades[class][stud]);
    } else {
        printf("Invalid class or student index\n");
    }
}
