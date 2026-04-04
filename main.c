#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Structure for Surgery Node
typedef struct Surgery {
    int id;
    char name[50];
    int duration;
    struct Surgery* next;
} Surgery;

// Adjacency matrix for DAG
int graph[MAX][MAX] = {0};

// List head
Surgery* head = NULL;
int count = 0;

// CREATE - Add surgery
void addSurgery() {
    Surgery* newNode = (Surgery*)malloc(sizeof(Surgery));

    printf("Enter Surgery ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Surgery Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Duration (mins): ");
    scanf("%d", &newNode->duration);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Surgery* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    count++;
    printf("✅ Surgery added!\n");
}

// READ - Display surgeries
void displaySurgeries() {
    if (head == NULL) {
        printf("No surgeries scheduled.\n");
        return;
    }

    Surgery* temp = head;
    printf("\n--- Surgery List ---\n");

    while (temp != NULL) {
        printf("ID: %d | Name: %s | Duration: %d mins\n",
               temp->id, temp->name, temp->duration);
        temp = temp->next;
    }
}

// SEARCH
Surgery* searchSurgery(int id) {
    Surgery* temp = head;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// UPDATE
void updateSurgery() {
    int id;
    printf("Enter Surgery ID to update: ");
    scanf("%d", &id);

    Surgery* s = searchSurgery(id);

    if (s == NULL) {
        printf("❌ Not found\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter new duration: ");
    scanf("%d", &s->duration);

    printf("✅ Updated successfully\n");
}

// DELETE
void deleteSurgery() {
    int id;
    printf("Enter Surgery ID to delete: ");
    scanf("%d", &id);

    Surgery *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("✅ Deleted\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("✅ Deleted\n");
}

// ADD DEPENDENCY (EDGE)
void addDependency() {
    int u, v;
    printf("Enter prerequisite surgery ID: ");
    scanf("%d", &u);

    printf("Enter dependent surgery ID: ");
    scanf("%d", &v);

    if (u >= MAX || v >= MAX) {
        printf("Invalid IDs\n");
        return;
    }

    graph[u][v] = 1;
    printf("✅ Dependency added: %d -> %d\n", u, v);
}

// DISPLAY GRAPH
void displayGraph() {
    printf("\n--- Adjacency Matrix ---\n");

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// TOPOLOGICAL SORT (Scheduling Order)
int visited[MAX] = {0};
int stack[MAX], top = -1;

void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < count; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < count; i++)
        visited[i] = 0;

    top = -1;

    for (int i = 0; i < count; i++) {
        if (!visited[i])
            dfs(i);
    }

    printf("\n--- Surgery Schedule Order ---\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

// MENU
void menu() {
    int choice;

    do {
        printf("\n===== HOSPITAL SCHEDULING MENU =====\n");
        printf("1. Add Surgery\n");
        printf("2. Delete Surgery\n");
        printf("3. Update Surgery\n");
        printf("4. Search Surgery\n");
        printf("5. Display Surgeries\n");
        printf("6. Add Dependency (Edge)\n");
        printf("7. Show Graph\n");
        printf("8. Get Schedule (Topological Sort)\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSurgery(); break;
            case 2: deleteSurgery(); break;
            case 3: updateSurgery(); break;
            case 4: {
                int id;
                printf("Enter ID: ");
                scanf("%d", &id);
                Surgery* s = searchSurgery(id);
                if (s)
                    printf("Found: %s (%d mins)\n", s->name, s->duration);
                else
                    printf("❌ Not found\n");
                break;
            }
            case 5: displaySurgeries(); break;
            case 6: addDependency(); break;
            case 7: displayGraph(); break;
            case 8: topologicalSort(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 9);
}

// MAIN
int main() {
    menu();
    return 0;
}
