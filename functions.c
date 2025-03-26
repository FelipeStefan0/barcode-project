#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Validador de identificador - Realiza as validações necessárias
void barcodeValidator(char* barcode) {
    int sum = 0;
    int verifyDigit = 0;

    // Verifica o tamanho da string
    if (strlen(barcode) != 8) {
        fprintf(stderr, "Identificador nao possui 8 digitos.\n");
        exit(1);
    }

    // Verifica se existe algum caractere alfabético na string
    for (int i = 0;barcode[i] != '\0';i++) {
        if (barcode[i] < '0' || barcode[i] > '9') {
            fprintf(stderr, "Identificador contem valores nao numericos.\n");
            exit(1);
        }
    }

    // Realiza a soma de todos os caracteres
    for (int i = 0;i < 7;i++) {
        int character = barcode[i] - '0';

        if ((i + 1) % 2 == 0) {
            sum += character * 1;
        } else {
            sum += character * 3;
        }
    }

    // Resulta o dígito verificador da soma realizada
    verifyDigit = (10 - (sum % 10)) % 10;

    // Verifica se o dígito obtido e o informado são iguais
    if (verifyDigit != (barcode[7] - '0')) {
        fprintf(stderr, "O digito verificador do identificador e invalido (nao corresponde aos valores anteriores).\n");
        exit(1);
    }
}

// Conversor de números - Converte cada numero do identificador e retorna uma string correspondente
char* numberConversor(char number, char side) {
    if (side == 'L') {
        switch (number) {
            case '0':
                return "0001101";
            case '1':
                return "0011001";
            case '2':
                return "0010011";
            case '3':
                return "0111101";
            case '4':
                return "0100011";
            case '5':
                return "0110001";
            case '6':
                return "0101111";
            case '7':
                return "0111011";
            case '8':
                return "0110111";
            case '9':
                return "0001011";
        }
    } else {
        switch (number) {
            case '0':
                return "1110010";
            case '1':
                return "1100110";
            case '2':
                return "1101100";
            case '3':
                return "1000010";
            case '4':
                return "1011100";
            case '5':
                return "1001110";
            case '6':
                return "1010000";
            case '7':
                return "1000100";
            case '8':
                return "1001000";
            case '9':
                return "1110100";
        }
    }
}

// Conversor de identificador - Concatena em uma string todas as strings retornadas pelo método anterior
void barcodeConversor(char* barcode, char* barcodeConverted) {
    barcodeConverted[0] = '\0';

    strcat(barcodeConverted, "101");

    for (int i = 0; i < 8; i++) {
        if (i < 4)
            strcat(barcodeConverted, numberConversor(barcode[i], 'L'));
        else if (i == 4) {
            strcat(barcodeConverted, "01010");
            strcat(barcodeConverted, numberConversor(barcode[i], 'R'));
        }
        else
            strcat(barcodeConverted, numberConversor(barcode[i], 'R'));
    }

    strcat(barcodeConverted, "101");
}

// Criador de código de barras - Recebe todos os argumentos e monta a imagem em uma matriz, inserindo no arquivo depois
void createImage(int sideSpace, int pixelByArea, int barcodeHeight, char* imageName, char* barcode) {
    int barcodeWidth = (67 * pixelByArea) + (sideSpace * 2);
    barcodeHeight += (sideSpace * 2);
    int image[barcodeHeight][barcodeWidth];

    char answer;

    FILE* file;

    // Insere a cor branca em toda a matriz
    for (int i = 0;i < barcodeHeight;i++) {
        for (int j = 0;j < barcodeWidth;j++) {
            image[i][j] = 0;
        }
    }

    // Constrói a matriz respeitando as margens, informadas ou não, e insere as cores pretas
    for (int i = 0; i < 67; i++) {
        for (int j = sideSpace; j < (barcodeHeight - sideSpace); j++) {
            for (int m = 0; m < pixelByArea; m++) {
                int column = sideSpace + (i * pixelByArea) + m;
                image[j][column] = barcode[i] - '0';
            }
        }
    }

    // Verifica se o arquivo é existente
    file = fopen(strcat(imageName, ".pbm"), "r");
    if (file != NULL) {
        while (answer == NULL) {
            printf("Arquivo ja existe, deseja subscrever(Y/N): ");
            scanf(" %c", &answer);
            printf("\n");
        }
    }
    fclose(file);

    // Validação para ver se o usuário quer subscrever o arquivo existente, caso sim, passa toda a matriz para a imagem
    if (answer == 'Y' || answer == 'y' || answer == NULL) {
        file = fopen(imageName, "w+");
        fprintf(file, "P1\n");
        fprintf(file, "%d %d\n", barcodeWidth, barcodeHeight);

        for (int i = 0;i < barcodeHeight;i++) {
            for (int j = 0;j < barcodeWidth;j++) {
                fprintf(file, "%d", image[i][j]);
            }
            fprintf(file,"\n");
        }

        fclose(file);
        printf("Arquivo criado com sucesso!");
    } else {
       printf("Arquivo resultante ja existe!");
    }
}

// Validador de arquivo - Realiza as validações necessárias
void fileValidation(char* fileName, char* extension, FILE* file) {
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Arquivo nao existe!\n");
       exit(1);
    } else if (strcmp(extension, ".pbm") != 0) {
        printf("Extensao do arquivo difere de '. pbm'\n");
        exit(1);
    }
    fclose(file);
}

// Conversor de números - Converte uma string e retorna um caractere correspondente
char numberDesconversor(char* number, char side) {
    if (side == 'L') {
        if (strcmp(number, "0001101") == 0) return '0';
        if (strcmp(number, "0011001") == 0) return '1';
        if (strcmp(number, "0010011") == 0) return '2';
        if (strcmp(number, "0111101") == 0) return '3';
        if (strcmp(number, "0100011") == 0) return '4';
        if (strcmp(number, "0110001") == 0) return '5';
        if (strcmp(number, "0101111") == 0) return '6';
        if (strcmp(number, "0111011") == 0) return '7';
        if (strcmp(number, "0110111") == 0) return '8';
        if (strcmp(number, "0001011") == 0) return '9';
    } else {
        if (strcmp(number, "1110010") == 0) return '0';
        if (strcmp(number, "1100110") == 0) return '1';
        if (strcmp(number, "1101100") == 0) return '2';
        if (strcmp(number, "1000010") == 0) return '3';
        if (strcmp(number, "1011100") == 0) return '4';
        if (strcmp(number, "1001110") == 0) return '5';
        if (strcmp(number, "1010000") == 0) return '6';
        if (strcmp(number, "1000100") == 0) return '7';
        if (strcmp(number, "1001000") == 0) return '8';
        if (strcmp(number, "1110100") == 0) return '9';
    }
}

// Extrator de código de barras - Extraí o código de barras da imagem recebida
void barcodeExtractor(char* barcodeConverted, char* barcode, char* fileName, FILE* file) {
    int width = 0;
    int height = 0;
    char* line = malloc(50 * sizeof(char));

    file = fopen(fileName, "r");

    // Recuperando a largura e altura da imagem
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d %d", &width, &height) == 2) {
            break;
        }
    }

    // Aumentando o buffer de acordo com a largura da imagem recebida
    line = realloc(line, width);

    // Transferindo os valores do arquivo para a matriz
    int image[height][width];
    int row = 0;
    int col = 0;
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0;line[i] != '\0';i++) {
            if (line[i] == '0' || line[i] == '1') {
                image[row][col] = line[i] - '0';
                col++;
                if (col == width) {
                    col = 0;
                    row++;
                    if (row == height) {
                        break;
                    }
                }
            }
        }
        if (row == height) {
            break;
        }
    }

    fclose(file);

    // Armazenando o tamanho dos espaços laterais
    row = 0;
    col = 0;
    int stop = 0;
    for (int i = 0;i < height;i++) {
        for (int j = 0;j < width;j++) {
            if (image[i][j] == 1) {
                row = i;
                col = j;
                stop++;
                break;
            }
        }
        if (stop == 1) break;
    }

    // Adicionando o valor do código de barras sem os espaços laterais
    barcodeConverted[0] = '\0';
    int pixelByArea = (width - (stop * 2)) / 67;
    int count = 0;
    for (int i = col;i < (width - col);i++) {
        char temporary = image[row][i] + '0';
        if (count == (pixelByArea - 1)) {
            strncat(barcodeConverted, &temporary, 1);
            count = 0;
        } else {
            count++;
        }
    }

    barcode[0] = '\0';
    for (int i = 3;i < 65;) {
        char* temporary = malloc(8 * sizeof(char));
        if (i < 31) {
            snprintf(temporary, sizeof(temporary), "%c%c%c%c%c%c%c", barcodeConverted[i], barcodeConverted[i+1], barcodeConverted[i+2], barcodeConverted[i+3], barcodeConverted[i+4], barcodeConverted[i+5], barcodeConverted[i+6]);
            char value = numberDesconversor(temporary, 'L');
            strncat(barcode, &value, 1);
            i+=7;
        } else if (i > 35) {
            snprintf(temporary, sizeof(temporary), "%c%c%c%c%c%c%c", barcodeConverted[i], barcodeConverted[i+1], barcodeConverted[i+2], barcodeConverted[i+3], barcodeConverted[i+4], barcodeConverted[i+5], barcodeConverted[i+6]);
            char value = numberDesconversor(temporary, 'R');
            strncat(barcode, &value, 1);
            i+=7;
        } else {
            i+=5;
        }
        free(temporary);
    }

    printf("Codigo de barras extraido: %s\n", barcode);
    free(line);
}
