#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; //HERE
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name, name) == 0)
        {
            candidates[j].votes+=1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int winner_num = candidate_count - 1;

    // Use selection sort
    int temp_votes = 0;
    string temp_name = "0";

    for (int min_num = 0; min_num < candidate_count; min_num++)
    {
        for (int k = min_num+1; k < candidate_count; k++)
        {
            if (candidates[k].votes < candidates[min_num].votes) //swap
            {
                temp_votes = candidates[min_num].votes;
                temp_name = candidates[min_num].name;
                candidates[min_num] = candidates[k];
                candidates[k].votes = temp_votes;
                candidates[k].name = temp_name;

            }
        }
    }
    // printf("%s %d\n", candidates[winner_num].name, candidates[winner_num].votes);
    printf("%s\n", candidates[winner_num].name);
    if (candidates[winner_num].votes == candidates[winner_num - 1].votes)
    {
        for (int m = 1; m < candidate_count; m++)
        {
            if (candidates[winner_num].votes == candidates[winner_num - m].votes)
            {
                //  printf("%s %d\n", candidates[winner_num - m].name, candidates[winner_num - m].votes);
                 printf("%s\n", candidates[winner_num - m].name);
            }
        }
    }
    return;
}
