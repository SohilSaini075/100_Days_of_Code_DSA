/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations. */

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hashTable[100];

void init(int m) {
    for (int i = 0; i < m; i++)
        hashTable[i] = EMPTY;
}

int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (hashTable[idx] == EMPTY) {
            hashTable[idx] = key;
            return;
        }
    }
}

void search(int key, int m) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (hashTable[idx] == key) {
            printf("FOUND\n");
            return;
        }

        if (hashTable[idx] == EMPTY) {
            break;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    init(m);

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}