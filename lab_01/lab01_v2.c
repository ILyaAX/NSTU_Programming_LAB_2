#include <stdio.h>
#include <stdlib.h>

int find_substring (char *, char *);

int main () {
    char *sequence = NULL;                  // variable for pointer to string
    char *subsequence = NULL;               // variable for pointer to substring   
    size_t ln_seq = 0;
    size_t ln_sub = 0;
    int counter;                            // variable for hit counter
    int *index = NULL;                      // variable for pointer hit indices
    getline (&sequence, &ln_seq, stdin);
    getline (&subsequence, &ln_sub, stdin);
    counter = find_substring (sequence, subsequence);
    printf ("%s", sequence);
    printf ("%s", subsequence);
    free (sequence);
    free (subsequence);
    free (index);
    return 0;
}

int find_substring (char *sequence, char *subsequence) {
    char * p_seq = sequence;
    char * p_sub = subsequence;
    int counter = 0;
    

long index = 0;
    char symbol;
    char *string = (char *)malloc(sizeof(char));
    while((symbol = getchar()) != '\n')
    {
        string [index] = symbol;
        string = (char *)realloc(string,(1 + (index++))*sizeof(char));
    }
    string [index] = '\0';
    return string;

    return counter;
}