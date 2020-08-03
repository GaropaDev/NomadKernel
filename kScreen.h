/*
 * kScreen.h
 *
 *  Created on: 29 de jul de 2020
 *      Author: thiago
 */

#ifndef KSCREEN_H_
#define KSCREEN_H_

#define SCREEN_COLS 80
#define SCREEN_LINES 25
#define SCREEN_ELEMENT_BYTES 2
#define SCREEN_BACKGROUND_COLOR 0x07
#define SCREEN_MEMORY 0xb8000

typedef struct kScreen{
	char *screenPtr;
	unsigned int screenPosition;

}K_SCREEN;

void kScreenClear(K_SCREEN *kScreen);

int kScreenPrintPos(K_SCREEN *kScreen, char *strPtr, unsigned int len, unsigned int col, unsigned int line);

int kScreenPrint(K_SCREEN *kScreen, char *strPtr, unsigned int len);

#endif /* KSCREEN_H_ */
