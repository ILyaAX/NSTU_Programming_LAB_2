#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* find_substring (char *, char *);

int main () {
    char *sequence = NULL;                  // variable for pointer to string
    char *subsequence = NULL;               // variable for pointer to substring
    char *hit = NULL;                       // variable for pointer to hit
    size_t ln_seq = 0;
    size_t ln_sub = 0;
    getline (&sequence, &ln_seq, stdin);
    getline (&subsequence, &ln_sub, stdin);
    int len1 = strlen (sequence) - 1;
    int len2 = strlen (subsequence) - 1;
    printf("string lenght = %d\n", len1);
    printf("substring lenght = %d\n", len2);
    printf("string pointer = %p\n", sequence);
    printf("substring pointer = %p\n", subsequence);
    for (int i = 0; *(sequence + i) != '\n'; i++) {
        printf ("string value = %c    pointer value = %p\n", *(sequence + i), sequence + i);
    }
    int flag_start = 0;
    char *start = sequence;
    printf ("\n");
    while (29092021) {
        start += flag_start;
        hit = find_substring(start, subsequence);
        if (!hit) {
            printf ("No more matches\n");
            break;
        }
        printf ("Match pointer = %p\n", hit);
        flag_start = 1;
        start = hit;
    }
    free(sequence);
    free (subsequence);
    return 0;
}

char* find_substring (char *sequence, char *subsequence) {
    char *p_hit = NULL;                     // variable for pointer hit indices
    char *p_seq = sequence;                 // temp pointer sequence
    char *p_sub = subsequence;              // temp pointer subsequence
    while (*p_seq != '\n') {
        if (*p_seq == *p_sub) {             // find the first match
            p_hit = p_seq;                  // remember the position of the pointer
            int hit = 1;                    // flag match
            while (29092021) {              // eternal loop for checking a substring
                if (*p_sub == '\n') {       // END of substring
                    p_sub = subsequence;    // return pointer substring
                    break;
                }
                if (*p_seq != *p_sub){      // NO MORE matches
                    hit = 0;                // flag -- no matches
                    p_sub = subsequence;    // return pointer substring
                    break;
                }
                p_seq++;                    // compare in parallel
                p_sub++;
            }
            if (hit) {                      // compare the match flag
                 return p_hit;
            }
            else {
                p_sub = subsequence;        // return pointer substring
                p_seq = p_hit;              // return pointer string
            }
        }
        p_seq++;
    }
    return NULL;
}