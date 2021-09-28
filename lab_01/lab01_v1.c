#include <stdio.h>
#include <stdlib.h>

                    // --------------   // function
char* fill_array (void);
char* find_substring (char *sequence, char *subsequence);

int main () {
    char *p_sequence = NULL;                   // variable for pointer to string
    char *p_subsequence = NULL;                // variable for pointer to substring   
    p_sequence = fill_array ();
    p_subsequence = fill_array ();
    printf ("%s\n", p_sequence);
    printf ("%s\n", p_subsequence);
    return 0;
}

char* fill_array (void) {
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
}