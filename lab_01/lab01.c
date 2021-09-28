#include <stdio.h>

//#define SIZE    100
                    // --------     // function
void fill_array (char*);
void print_arr (char *p_sequence);
char* find_substring (char *sequence, char *subsequence);

int main () {
    int SIZE;
    printf ("Введите длину строки для поиска : ");
    scanf ("%d", &SIZE);
    char *p_sequence;                   // variable for pointer to string
    char *p_subsequence;                // variable for pointer to substring   
    char sequence[SIZE] = {0};
    char subsequence[SIZE] = {0};
    p_sequence = sequence;              // pointer to string
    p_subsequence = subsequence;        // pointer to substring
    fill_array (p_sequence);
    fill_array (p_subsequence);
    print_arr (p_sequence);
    print_arr (p_subsequence);
    return 0;
}

void fill_array (char *p_sequence) {
    char *init_p;
    init_p = p_sequence;                //fix the initial value
    for (int i = 0; i < SIZE ; i++, p_sequence++) {
		scanf ("%c", (p_sequence));
		if (*(p_sequence) == '\n') {
			*(p_sequence) = '\0';
			p_sequence = init_p;        // return pointer to initial value
            break;
		}    
    }
    p_sequence = init_p;                // return pointer to initial value
}

void print_arr (char *p_sequence) {
    char *init_p;
    init_p = p_sequence;                //fix the initial value
    for (int i = 0; *(p_sequence) != '\0'; i++, p_sequence++) {
       printf ("%c", *(p_sequence));
    }
    printf("\n");
    p_sequence = init_p;                // return pointer to initial value
}