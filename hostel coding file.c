#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hostel {
    int studentID;
    char name[50];
    int roomNumber;
    char block[20];
    struct Hostel *next;
};

struct Hostel *head = NULL;

// Remove trailing newline from fgets
void chomp(char *s) {
    if (!s) return;
    size_t n = strlen(s);
    while (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[n - 1] = '\0';
        n--;
    }
}

struct Hostel* createNode(int id, const char name[], int room, const char block[]) {
    struct Hostel *newNode = (struct Hostel*)malloc(sizeof(struct Hostel));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->studentID = id;
    strncpy(newNode->name, name, sizeof(newNode->name)-1);
    newNode->name[sizeof(newNode->name)-1] = '\0';
    newNode->roomNumber = room;
    strncpy(newNode->block, block, sizeof(newNode->block)-1);
    newNode->block[sizeof(newNode->block)-1] = '\0';
    newNode->next = NULL;
    return newNode;
}

void addAllotment() {
    char buf[64], name[50], block[20];
    int id, room;

    printf("Enter Student ID: ");
    fgets(buf, sizeof(buf), stdin); id = atoi(buf);

    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin); chomp(name);

    printf("Enter Room Number: ");
    fgets(buf, sizeof(buf), stdin); room = atoi(buf);

    printf("Enter Block: ");
    fgets(block, sizeof(block), stdin); chomp(block);

    struct Hostel *newNode = createNode(id, name, room, block);
    newNode->next = head;
    head = newNode;

    printf("Allotment added successfully!\n");
}

void removeStudent() {
    char buf[32];
    int id;
    printf("Enter Student ID to remove: ");
    fgets(buf, sizeof(buf), stdin); id = atoi(buf);

    struct Hostel *temp = head, *prev = NULL;
    while (temp != NULL && temp->studentID != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student not found!\n");
        return;
    }
    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Student removed!\n");
}

void searchByName() {
    char name[50];
    printf("Enter Name: ");
    fgets(name, sizeof(name), stdin); chomp(name);

    struct Hostel *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found: %d | %s | %d | %s\n",
                   temp->studentID, temp->name, temp->roomNumber, temp->block);
            return;
        }
        temp = temp->next;
    }
    printf("No student found with name %s\n", name);
}

void searchByRoom() {
    char buf[32];
    int room;
    printf("Enter Room Number: ");
    fgets(buf, sizeof(buf), stdin); room = atoi(buf);

    struct Hostel *temp = head;
    while (temp != NULL) {
        if (temp->roomNumber == room) {
            printf("Found: %d | %s | %d | %s\n",
                   temp->studentID, temp->name, temp->roomNumber, temp->block);
            return;
        }
        temp = temp->next;
    }
    printf("No student found in room %d\n", room);
}

void displayAllotments() {
    struct Hostel *temp = head;
    if (!temp) {
        printf("No allotments found\n");
        return;
    }
    printf("\nAll Allotments:\n");
    while (temp != NULL) {
        printf("%d | %s | %d | %s\n",
               temp->studentID, temp->name, temp->roomNumber, temp->block);
        temp = temp->next;
    }
}

void displayByBlock() {
    char block[20];
    printf("Enter Block: ");
    fgets(block, sizeof(block), stdin); chomp(block);

    struct Hostel *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->block, block) == 0) {
            printf("%d | %s | %d | %s\n",
                   temp->studentID, temp->name, temp->roomNumber, temp->block);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("No students found in block %s\n", block);
}

void reverseDisplay(struct Hostel *node) {
    if (node == NULL) return;
    reverseDisplay(node->next);
    printf("%d | %s | %d | %s\n",
           node->studentID, node->name, node->roomNumber, node->block);
}

void countByBlock() {
    char block[20];
    int count = 0;
    printf("Enter Block: ");
    fgets(block, sizeof(block), stdin); chomp(block);

    struct Hostel *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->block, block) == 0) count++;
        temp = temp->next;
    }
    printf("Total students in Block %s: %d\n", block, count);
}

void cloneList() {
    struct Hostel *cloneHead = NULL, *cloneTail = NULL, *temp = head;
    while (temp != NULL) {
        struct Hostel *newNode = createNode(temp->studentID, temp->name, temp->roomNumber, temp->block);
        if (cloneHead == NULL) {
            cloneHead = cloneTail = newNode;
        } else {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        temp = temp->next;
    }
    printf("\nCloned List:\n");
    temp = cloneHead;
    while (temp != NULL) {
        printf("%d | %s | %d | %s\n",
               temp->studentID, temp->name, temp->roomNumber, temp->block);
        temp = temp->next;
    }
    // Free cloned list
    while (cloneHead != NULL) {
        temp = cloneHead;
        cloneHead = cloneHead->next;
        free(temp);
    }
}

int main() {
    char buf[16];
    int choice;

    while (1) {
        printf("\n--- Hostel Management ---\n");
        printf("1. Add Allotment\n2. Remove Student\n3. Search by Name\n4. Search by Room\n");
        printf("5. Display All\n6. Display by Block\n7. Reverse Display\n");
        printf("8. Count by Block\n9. Clone List\n0. Exit\nChoice: ");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        choice = atoi(buf);

        switch (choice) {
            case 1: addAllotment(); break;
            case 2: removeStudent(); break;
            case 3: searchByName(); break;
            case 4: searchByRoom(); break;
            case 5: displayAllotments(); break;
            case 6: displayByBlock(); break;
            case 7: reverseDisplay(head); break;
            case 8: countByBlock(); break;
            case 9: cloneList(); break;
            case 0: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }
return 0;
}