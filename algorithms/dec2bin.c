#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void bin2dec() {
    char bin[32],rev[32];
    printf("Enter the binary no: ");
    scanf("%s",bin);
    int j = 0;
    for (int i=strlen(bin)-1; i>=0; i--) {
        rev[j] = bin[i];
        j++;
    }
    rev[j] = '\0';
    int dec = 0;
    j = 0;
    for (int i=0; i<strlen(rev); i++) {
        dec += (rev[i]-'0') * pow(2,j);
        j++;
    }
    printf("Decimal format: %d\n",dec);
}

void dec2bin() {
    int dec;
    char bin[32];
    printf("Enter the decimal number: ");
    scanf("%d",&dec);
    itoa(dec,bin,2);
    printf("Binary format: %s\n",bin);
}

void main() {
    bin2dec();
    dec2bin();
}