#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

unsigned int hash_function(int key) {
    return (key >= 0 ? key : -key) % TABLE_SIZE;
}

void init_hash_table(Node* hash_table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void insert(Node* hash_table[], int value, int length) {
    unsigned int index = hash_function(value);
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = value;
    new_node->value = length;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int search(Node* hash_table[], int value) {
    unsigned int index = hash_function(value);
    Node* current = hash_table[index];
    while (current != NULL) {
        if (current->key == value) {
            return current->value;
        }
        current = current->next;
    }
    return 0;
}

void free_hash_table(Node* hash_table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hash_table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    Node* hash_table[TABLE_SIZE];
    init_hash_table(hash_table);

    int longest = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (search(hash_table, nums[i]) == 0) // not in table
        {
            int left_len = search(hash_table, nums[i] - 1);  // left len
            int right_len = search(hash_table, nums[i] + 1);  // right len
            int new_len = left_len + right_len + 1;

            insert(hash_table, nums[i], new_len);

            if (left_len > 0) {
                insert(hash_table, nums[i] - left_len, new_len);
            }
            if (right_len > 0) {
                insert(hash_table, nums[i] + right_len, new_len);
            }

            longest = (new_len > longest) ? new_len : longest;
        }
    }

    free_hash_table(hash_table);
    return longest;
}

// Fonction principale pour tester
int main(void)
{
	int input[] = {100,4,200,1,3,2};
    	int inputSize = sizeof(input) / sizeof(input[0]);
    	int output;
    
    	output = longestConsecutive(input,inputSize);
    
    	printf("%d\n",output);
    
    	return 0;
}
