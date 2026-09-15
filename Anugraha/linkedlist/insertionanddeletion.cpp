#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;       
    printf("Inserted %d at the beginning.\n", value);
}

// 2. Insert at the End
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = newNode; // Link the last node to the new node
    printf("Inserted %d at the end.\n", value);
}

// 3. Insert at a Specific Position (1-based index)
void insertAtPosition(struct Node** head, int value, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    struct Node* temp = *head;
    // Traverse to the node right before the desired position
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next; // Link new node to the next node
    temp->next = newNode;       // Link previous node to new node
    printf("Inserted %d at position %d.\n", value, position);
}

// --- DELETION OPERATIONS ---

// 1. Delete from the Beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head; // Keep track of the old head
    *head = (*head)->next;     // Move head to the next node
    free(temp);                // Free the memory of the old head
    printf("Deleted node from the beginning.\n");
}

// 2. Delete from the End
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    // If there is only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Deleted the last remaining node.\n");
        return;
    }

    struct Node* temp = *head;
    // Traverse to the second-to-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);   // Free the last node
    temp->next = NULL;  // Set the second-to-last node's next to NULL
    printf("Deleted node from the end.\n");
}

// 3. Delete from a Specific Position (1-based index)
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid operation or list is empty!\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    struct Node* temp = *head;
    // Traverse to the node right before the target node to delete
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    struct Node* targetNode = temp->next; // The node to be deleted
    temp->next = targetNode->next;        // Skip over the target node
    free(targetNode);                     // Free memory
    printf("Deleted node at position %d.\n", position);
}

// Helper function to print the linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the operations
int main() {
    struct Node* head = NULL;

    // Test Insertions
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 3); // Inserts 15 at position 3
    printList(head); // Expected: 5 -> 10 -> 15 -> 20 -> NULL

    // Test Deletions
    deleteFromBeginning(&head);
    printList(head); // Expected: 10 -> 15 -> 20 -> NULL

    deleteFromEnd(&head);
    printList(head); // Expected: 10 -> 15 -> NULL

    deleteFromPosition(&head, 2);
    printList(head); // Expected: 10 -> NULL

    return 0;
}
