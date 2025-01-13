#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int hash_function(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

void init_table(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

bool insert(Node* table[], int value) {
    int index = hash_function(value);
    Node* current = table[index];

    // if already exist
    while (current != NULL) {
        if (current->value == value) {
            return false;
        }
        current = current->next;
    }

    // add a new node to the beginning of the list
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = table[index];
    table[index] = new_node;

    return true;
}

bool search(Node* table[], int value) {
    int index = hash_function(value);
    Node* current = table[index];

    while (current != NULL) {
        if (current->value == value) {
            return true; // found
        }
        current = current->next;
    }
    return false; // not found
}

void free_table(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        table[i] = NULL;
    }
}

int longestConsecutive(int* nums, int numsSize)
{
    int max_len = 0;
    int len,current_nb,k;
    Node* table[TABLE_SIZE];
    init_table(table);
    
    
    for (int i = 0; i < numsSize;i++) // insert nums
        insert(table,nums[i]);
    
    for(int j = 0;j < numsSize;j++) // check neighbors
    {
        current_nb = nums[j];
        if (!search(table, current_nb -1))//nb-1 not founded
        {
            len = 1;
            k = 1;
            while (search(table, current_nb + k)) // next right neighbors found
            {
                len++;
                k++;
            }
            max_len = len > max_len ? len : max_len;
        }
    }
    return max_len;
}

int main(void) {
    int input[] = {100,4,200,1,3,2};
    int inputSize = sizeof(input) / sizeof(input[0]);
    int output;
    
    output = longestConsecutive(input,inputSize);
    
    printf("%d\n",output);
    
    return 0;
}
