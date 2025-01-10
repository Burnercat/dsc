include <stdio.h> 
#define MAX_TERMS 101 
typedef struct { 
    int col; 
    int row; 
    int value; 
} Term; 
Term a[MAX_TERMS]; 
Term b[MAX_TERMS]; 
void fastTranspose(Term a[], Term b[]) { 
    int rowTerms[a[0].col], startingPos[a[0].col]; 
    int i, j, numCols = a[0].col, numTerms = a[0].value; 
    b[0].row = numCols; 
    b[0].col = a[0].row; 
    b[0].value = numTerms; 
    if (numTerms > 0) { 
        for (i = 0; i < numCols; i++) 
            rowTerms[i] = 0; 
        for (i = 1; i <= numTerms; i++) 
            rowTerms[a[i].col]++; 
        startingPos[0] = 1; 
        for (i = 1; i < numCols; i++) 
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1]; 
        for (i = 1; i <= numTerms; i++) { 
            j = startingPos[a[i].col]++; 
            b[j].row = a[i].col; 
            b[j].col = a[i].row; 
            b[j].value = a[i].value; 
        } 
    } 
} 
void simpleTranspose(Term a[], Term b[]) { 
    int numTerms = a[0].value; 
    b[0].row = a[0].col; 
    b[0].col = a[0].row; 
    b[0].value = numTerms; 
    if (numTerms > 0) { 
        int currentB = 1; 
        for (int c = 0; c < a[0].col; ++c) { 
            for (int i = 1; i <= numTerms; ++i) { 
                if (a[i].col == c) { 
                    b[currentB].row = a[i].col; 
                    b[currentB].col = a[i].row; 
                    b[currentB].value = a[i].value; 
                    ++currentB; 
                } 
            } 
        } 
    } 
} 
int main() { 
    int i; 
    printf("Enter the number of rows and columns\n"); 
    scanf("%d%d", &a[0].row, &a[0].col); 
    printf("Enter the number of values\n"); 
    scanf("%d", &a[0].value); 
    for (i = 1; i <= a[0].value; i++) { 
        printf("Enter the %dth row, column and element values\n", i); 
        scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].value); 
    } 
    printf("\nOriginal Matrix\n"); 
    for (i = 1; i <= a[0].value; i++) { 
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value); 
    } 
    Term simpleTransposed[MAX_TERMS]; 
    simpleTranspose(a, simpleTransposed); 
    printf("\nSimple Transpose Matrix\n"); 
    for (i = 1; i <= simpleTransposed[0].value; i++) { 
        printf("%d\t%d\t%d\n", simpleTransposed[i].row, 
simpleTransposed[i].col, simpleTransposed[i].value); 
    } 
    Term fastTransposed[MAX_TERMS]; 
    fastTranspose(a, fastTransposed); 
    printf("\nFast Transpose Matrix\n"); 
    for (i = 1; i <= fastTransposed[0].value; i++) { 
        printf("%d\t%d\t%d\n", fastTransposed[i].row, fastTransposed[i].col, 
fastTransposed[i].value); 
    } 
    return 0; 
}