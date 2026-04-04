#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure
struct Student {
    int id;
    char name[50];
    float marks;
    struct Student* next;
};

// Head pointer
struct Student* head = NULL;

// CREATE - Add node
void addStudent() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("✅ Student added successfully!\n");
}

// READ - Display
void displayStudents() {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    struct Student* temp = head;
    printf("\n--- Student Records ---\n");

    while (temp != NULL) {
        printf("ID: %d | Name: %s | Marks: %.2f\n",
               temp->id, temp->name, temp->marks);
        temp = temp->next;
    }
}

// SEARCH
struct Student* searchStudent(int id) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// UPDATE
void updateStudent() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    struct Student* student = searchStudent(id);

    if (student == NULL) {
        printf("❌ Student not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", student->name);

    printf("Enter new marks: ");
    scanf("%f", &student->marks);

    printf("✅ Record updated successfully!\n");
}

// DELETE
void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    struct Student *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("✅ Student deleted.\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Student not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("✅ Student deleted.\n");
}

// MENU
void menu() {
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Display Students\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                struct Student* s = searchStudent(id);
                if (s)
                    printf("Found: %s (Marks: %.2f)\n", s->name, s->marks);
                else
                    printf("❌ Not found\n");
                break;
            }
            case 5: displayStudents(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 6);
}

// MAIN
int main() {
    menu();
    return 0;
}
