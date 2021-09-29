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
    printf("stroke lenght = %d\n", len1);
    printf("substroke lenght = %d\n", len2);
    printf("stroke pointer = %p\n", sequence);
    printf("substroke pointer = %p\n", subsequence);
    for (int i = 0; *(sequence + i) != '\n'; i++) {
        printf ("string value = %c    pointer value = %p\n", *(sequence + i), sequence + i);
    }
    //int counter = 0;
    int flag_start = 0;
    char *start = sequence;
    printf ("\n\n");
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
        //printf("sub = %c    seq = %c\n", *p_sub, *p_seq);
        if (*p_seq == *p_sub) {             // find the first match
            p_hit = p_seq;                  // remember the position of the pointer
            int hit = 1;                    // flag match
            while (29092021) {              // eternal loop for checking a substring
                //printf("while sub = %c    seq = %c\n", *p_sub, *p_seq);
                if (*p_sub == '\n') {       // END of substring
                    p_sub = subsequence;    // return pointer substring
                    //printf ("ext 1");
                    break;
                }
                if (*p_seq != *p_sub){      // NO MORE matches
                    hit = 0;                // flag -- no matches
                    p_sub = subsequence;    // return pointer substring
                    //printf ("ext 2");
                    break;
                }
                p_seq++;                    // compare in parallel
                p_sub++;
            }
            if (hit) {                      // compare the match flag
                //printf("return hit = %p\n", p_hit);
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
 
 
 /*
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
*/