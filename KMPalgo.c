//1.) Write a program in C that implements the following: - 
//i) A String & pattern is taken as input from the user. 
//ii) Module KMP() when called searches for the pattern and prints whether the 
//pattern is found or not and also the index if found.


#include <stdio.h>
#include <string.h>

#define MAX 1000

// Function to compute the Longest Prefix Suffix (LPS) array
void computeLPSArray(char pattern[], int M, int lps[]) {
    int length = 0; // length of the previous longest prefix suffix
    lps[0] = 0;     // lps[0] is always 0
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
                // Note: we do not increment i here
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMP(char text[], char pattern[]) {
    int N = strlen(text);
    int M = strlen(pattern);
    int lps[MAX]; // Fixed-size array for LPS

    computeLPSArray(pattern, M, lps);

    int i = 0; // index for text[]
    int j = 0; // index for pattern[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            return; // Stop after first match
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    printf("Pattern not found.\n");
}

int main() {
    char text[MAX], pattern[MAX];

    printf("Enter the text: ");
    fgets(text, MAX, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline

    printf("Enter the pattern: ");
    fgets(pattern, MAX, stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove newline

    KMP(text, pattern);

    return 0;
}