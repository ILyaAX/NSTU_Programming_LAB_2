#include <stdio.h>

#define SIZE    600

void fill_array (char*);
void print_arr (char *p_sequence);
int find_substring (char *sequence, char *subsequence);

int main () {
    char *p_sequence;
    char sequence[SIZE] = {0};
    p_sequence = sequence;
    fill_array (p_sequence);
    print_arr (p_sequence);
    return 0;
}

void fill_array (char *p_sequence) {
    for (int i = 0; i < SIZE ; i++) {
		scanf ("%c", (p_sequence + i));
		if (*(p_sequence + i) == '\n') {
			*(p_sequence + i) = '\0';
			break;
		}    
    }
}

void print_arr (char *p_sequence) {
    for (int i = 0; *(p_sequence + i) != '\0'; i++)
       printf ("%c", *(p_sequence + i));
    printf("%c", '\n');
}