#include <stdio.h>

struct Polynomial {
    int* coefficients;
    int degree;
};

void addPolynomials(struct Polynomial* poly1, struct Polynomial* poly2, struct Polynomial* result) {
    int i;
    result->degree = (poly1->degree > poly2->degree) ? poly1->degree : poly2->degree;
    result->coefficients = (int*) malloc((result->degree + 1) * sizeof(int));
    for (i = 0; i <= result->degree; i++) {
        result->coefficients[i] = (i <= poly1->degree) ? poly1->coefficients[i] : 0;
        result->coefficients[i] += (i <= poly2->degree) ? poly2->coefficients[i] : 0;
    }
}
void printPolynomial(struct Polynomial* poly) {
    int i;
    for (i = poly->degree; i >= 0; i--) {
        if (i == poly->degree) {
            printf("%dx^%d", poly->coefficients[i], i);
        } else {
            if (poly->coefficients[i] != 0) {
                if (poly->coefficients[i] > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                }
                printf("%dx^%d", abs(poly->coefficients[i]), i);
            }
        }
    }
    printf("\n");
}

int main() {
    struct Polynomial poly1, poly2, result;
    poly1.degree = 3;
    poly1.coefficients = (int*) malloc((poly1.degree + 1) * sizeof(int));
    poly1.coefficients[0] = 2;
    poly1.coefficients[1] = -1;
    poly1.coefficients[2] = 1;
    poly1.coefficients[3] = -2;
    poly2.degree = 2;
    poly2.coefficients = (int*) malloc((poly2.degree + 1) * sizeof(int));
    poly2.coefficients[0] = -1;
    poly2.coefficients[1] = 2;
    poly2.coefficients[2] = -3;

    addPolynomials(&poly1, &poly2, &result);

    printf("Polynomial 1: ");
    printPolynomial(&poly1);
    printf("Polynomial 2: ");
    printPolynomial(&poly2);
    printf("Result: ");
    printPolynomial(&result);
    
    free(poly1.coefficients);
    free(poly2.coefficients);
    free(result.coefficients);

    return 0;
}