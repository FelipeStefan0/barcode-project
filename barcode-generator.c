#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

// Constantes com valores padrões para caso o usuário não digite os argumentos
#define DEFAULT_SIDE_SPACE 3
#define DEFAULT_PIXEL_BY_AREA 1
#define DEFAULT_BARCODE_HEIGHT 75

int main() {

    // Instância das variáveis
    int sideSpace = DEFAULT_SIDE_SPACE;
    int pixelByArea = DEFAULT_PIXEL_BY_AREA;
    int barcodeHeight = DEFAULT_BARCODE_HEIGHT;
    char answer;
    char* imageName = malloc(100 * sizeof(char));
    char* barcode = malloc(9 * sizeof(char));
    char* barcodeConverted = malloc(68 * sizeof(char));

    strcpy(imageName, "barcode");

    printf("Digite o codigo de barras: ");
    fgets(barcode, 9, stdin);
    printf("\n");

    barcodeValidator(barcode);

    printf("Deseja digitar os argumentos opcionais(Y/N): ");
    scanf(" %c", &answer);
    printf("\n");

    if (answer == 'Y' || answer == 'y') {
        printf("Espacamento lateral (em pixels), Pixels por area, Altura do codigo de barras (em pixels), Nome da imagem\n");
        printf("Digite os valores(Separados por espacos): ");
        scanf("%d %d %d %s", &sideSpace, &pixelByArea, &barcodeHeight, imageName);
        printf("\n");
    }

    barcodeConversor(barcode, barcodeConverted);

    createImage(sideSpace, pixelByArea, barcodeHeight, imageName, barcodeConverted);

    printf("\nAperte qualquer tecla para finalizar a aplicacao");
    getchar();
    getchar();

    free(imageName);
    free(barcode);
    free(barcodeConverted);

    return 0;
}
