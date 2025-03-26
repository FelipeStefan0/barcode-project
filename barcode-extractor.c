#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main () {

    char* fileName = malloc(100 * sizeof(char));
    char* barcodeConverted = malloc(68 * sizeof(char));
    char* barcode = malloc(8 * sizeof(char));
    FILE* file;

    printf("Digite o nome do arquivo: ");
    fgets(fileName, 100, stdin);

    // Trocando a quebra de linha por nulo
    fileName[strlen(fileName) - 1] = '\0';

    // Armazenando extensão do arquivo
    char* extension = strrchr(fileName, '.');

    fileValidation(fileName, extension, file);
    barcodeExtractor(barcodeConverted, barcode, fileName, file);

    printf("\nAperte qualquer tecla para finalizar a aplicacao");
    getchar();
    getchar();

    free(fileName);
    free(extension);
    free(barcodeConverted);
    free(barcode);

    return 0;
}
