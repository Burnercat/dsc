#include <stdio.h> 
#include <string.h> 
int pmatch(char *string, char *pat, int *failure) { 
int i = 0, j = 0; 
int lens = strlen(string); 
int lenp = strlen(pat); 
while (i < lens && j < lenp) { 
if (string[i] == pat[j]) { 
            i++; 
            j++; 
        } else if (j == 0) { 
            i++; 
        } else { 
            j = failure[j - 1] + 1; 
        } 
    } 
    return ((j == lenp) ? (i - lenp) : -1); 
} 
void fail(char *pat, int *failure) { 
    int i, j, n = strlen(pat); 
    failure[0] = -1; 
    for (j = 1; j < n; j++) { 
        i = failure[j - 1]; 
        while ((pat[j] != pat[i + 1]) && (i >= 0)) 
            i = failure[i]; 
        if (pat[j] == pat[i + 1]) 
            failure[j] = i + 1; 
        else 
            failure[j] = -1; 
    } 
} 
int nfind(char *string, char *pat) { 
    int i, j, start = 0; 
    int lasts = strlen(string) - 1; 
    int lastp = strlen(pat) - 1; 
    int endmatch = lastp; 
    for (i = 0; endmatch <= lasts; endmatch++, start++) { 
        if (string[endmatch] == pat[lastp]) { 
            for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, 
j++); 
            if (j == lastp) 
                return start; 
        } 
    } 
    return -1; 
} 
int main() { 
    char string[1000], pat[1000]; 
    printf("Enter a string: "); 
    scanf("%s", string); 
    printf("Enter a pattern to check if it's present in the entered string:"); 
    scanf("%s", pat); 
    int failure[strlen(pat)]; 
    fail(pat, failure); 
    int kmpIndex = pmatch(string, pat, failure); 
    int nfindIndex = nfind(string, pat); 
    printf("KMP Pattern Match: "); 
    if (kmpIndex != -1) 
        printf("Pattern found at index: %d\n", kmpIndex); 
    else 
        printf("Pattern not found\n"); 
    printf("n_find Match: "); 
    if (nfindIndex != -1) 
        printf("Pattern found at index: %d\n", nfindIndex); 
    else 
        printf("Pattern not found\n"); 
    return 0; 
} 