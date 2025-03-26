#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>

void barcodeValidator(char* barcode);
char* numberConversor(char number, char side);
void barcodeConversor(char* barcode, char* barcodeConverted);
void createImage(int sideSpace, int pixelByArea, int barcodeHeight, char* imageName, char* barcode);
void fileValidation(char* fileName, char* extension, FILE* file);
char numberDesconversor(char* number, char side);
void barcodeExtractor(char* barcodeConverted, char* barcode, char* fileName, FILE* file);

#endif
