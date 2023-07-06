#include <stdio.h>

#define MAX_CANDIDATES 10

// Structure to represent a candidate
typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

// Function to display the menu
void displayMenu() {
    printf("----- Voting System -----\n");
    printf("1. Add Candidate\n");
    printf("2. Display Candidates\n");
    printf("3. Vote\n");
    printf("4. Exit\n");
    printf("-------------------------\n");
    printf("Enter your choice: ");
}

// Function to add a candidate
void addCandidate(Candidate candidates[], int* numCandidates) {
    if (*numCandidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    Candidate candidate;
    candidate.id = *numCandidates + 1;

    printf("Enter candidate name: ");
    scanf("%s", candidate.name);

    candidate.votes = 0;

    candidates[*numCandidates] = candidate;
    (*numCandidates)++;

    printf("Candidate added successfully.\n");
}

// Function to display all candidates
void displayCandidates(Candidate candidates[], int numCandidates) {
    if (numCandidates == 0) {
        printf("No candidates found.\n");
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

// Function to cast a vote
void vote(Candidate candidates[], int numCandidates) {
    if (numCandidates == 0) {
        printf("No candidates found.\n");
        return;
    }

    int candidateId;
    printf("Enter the candidate ID to vote for: ");
    scanf("%d", &candidateId);

    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].id == candidateId) {
            candidates[i].votes++;
            printf("Vote casted successfully.\n");
            return;
        }
    }

    printf("Invalid candidate ID.\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate(candidates, &numCandidates);
                break;
            case 2:
                displayCandidates(candidates, numCandidates);
                break;
            case 3:
                vote(candidates, numCandidates);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}
