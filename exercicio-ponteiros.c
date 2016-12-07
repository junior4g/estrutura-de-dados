#include <stdio.h>
 
int main(void)

{
    int inteiro;
    int *inteiro_ptr = &inteiro;
 
    double double1;
    double *double_ptr = &double1;
 
    printf("Endereco da variariavel 'inteiro': %d\n", &inteiro);
    printf("Endereco armazenado no ponteiro 'inteiro_ptr': %d\n\n", inteiro_ptr);
 
    printf("Endereco da variariavel 'double1': %d\n", &double1);
    printf("Endereco armazenado no ponteiro 'double_ptr': %d\n\n", double_ptr);
 
    printf("Apos o uso dos ponteiros, vamos aponta-los para NULL\n\n");
    inteiro_ptr = NULL;
    double_ptr = NULL;
    printf("Endereco armazenado no ponteiro 'inteiro_ptr': %d\n", inteiro_ptr);
    printf("Endereco armazenado no ponteiro 'double_ptr': %d\n", double_ptr);
    return 0; 
}
