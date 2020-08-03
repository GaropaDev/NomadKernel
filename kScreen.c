/*
 * kScreen.c
 *
 *  Created on: 29 de jul de 2020
 *      Author: thiago
 */


#include "kScreen.h"

void kScreenClear(K_SCREEN *kScreen){
	unsigned int i, j;

	//Loop para limpar o ecran
	//Sao 25 linhas 80 colunas e 2 bytes por elemento
	for (j = 0; j < SCREEN_COLS * SCREEN_LINES * SCREEN_ELEMENT_BYTES; j = j + 2){
		kScreen->screenPtr[j] = ' ';
		kScreen->screenPtr[j + 1] = SCREEN_BACKGROUND_COLOR;
	}
}

int kScreenPrintPos(K_SCREEN *kScreen, char *strPtr, unsigned int len, unsigned int col, unsigned int line){
	unsigned int i, j;
	unsigned int point;

	point = (line * SCREEN_COLS) + col;
	if (point + len >= SCREEN_COLS * SCREEN_LINES){
		return 0;
	}

	//Escreve na tela o titulo do kernel.
	for (j = 0, i = (point * SCREEN_ELEMENT_BYTES); j < len; j++, i = i + 2){
		if (strPtr[j] == '\n'){
			i = i / (SCREEN_COLS * SCREEN_ELEMENT_BYTES);
			i = (i * (SCREEN_COLS + 1) * SCREEN_ELEMENT_BYTES);
		}
		kScreen->screenPtr[i] = strPtr[j];
		kScreen->screenPtr[i + 1] = SCREEN_BACKGROUND_COLOR;
	}
	return 1;
}

int kScreenPrint(K_SCREEN *kScreen, char *strPtr, unsigned int len){
	return 1;
}
