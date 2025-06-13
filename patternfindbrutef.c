//Write a program in C that implements the following:-

//i) A String( like “Techno International New Town”) & pattern( like “Town”) is taken as input 

//from the user.

//ii) Bruteforce() module when called informs whether the pattern is found or not, & if found the 

//corresponding index and the number of comparisons incurred.

#include<stdio.h>

#include<string.h>

char s[100];

char p[100];

int flag = 0;

int comp = 0;

void Bruteforce() {

    int ls = strlen(s);

    int lp = strlen(p);

    int j;



    for(int i=0; i<=ls-lp; i++) {

        j = 0;

        while(j<lp && s[i+j] == p[j] ) {

            j++;

            comp++;

        }

        if(j == lp) {

            printf("The position is: %d\n", i);

            flag = 1;

        }

    }

    if(!flag) {

        printf("Pattern not found.\n");

    }

    printf("Number of comparisons: %d\n", comp);

}

int main() {

    printf("Enter the main string: ");

    fgets(s, sizeof(s), stdin);

    s[strcspn(s, "\n")] = 0;



    printf("Enter the pattern: ");

    fgets(p, sizeof(p), stdin);

    p[strcspn(p, "\n")] = 0;



    Bruteforce();

    return 0;

}