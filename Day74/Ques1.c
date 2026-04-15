/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.*/

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][NAME_LEN];
    char unique[MAX][NAME_LEN];
    int count[MAX] = {0};
    int uniqueCount = 0;

    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);

        int found = -1;

        for(int j = 0; j < uniqueCount; j++) {
            if(strcmp(unique[j], names[i]) == 0) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            count[found]++;
        } else {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    int maxVotes = 0;
    char winner[NAME_LEN];

    for(int i = 0; i < uniqueCount; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}