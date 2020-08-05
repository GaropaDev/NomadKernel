/*
 * kernel.c
 *
 *  Created on: 29 de jul de 2020
 *      Author: thiago
 *
 *      Cores
 *     0 - Black, 1 - Blue, 2 - Green, 3 - Cyan, 4 - Red, 5 - Magenta,
 *     6 - Brown, 7 - Light Grey, 8 - Dark Grey, 9 - Light Blue,
 *     10/a - Light Green, 11/b - Light Cyan, 12/c - Light Red,
 *     13/d - Light Magenta, 14/e - Light Brown, 15/f – White.
 */

#define KERNEL_TITLE "Nomad Kernel"
#define KERNEL_VERSION "Stay Forever"

#include "kScreen.h"
#include "kStdLib.h"

void kmain(void){
	K_SCREEN screen;
	unsigned int len;
	const char *strKTitle = KERNEL_TITLE;
	const char *strKVersion = KERNEL_VERSION;

	screen.screenPtr = SCREEN_MEMORY;
	screen.screenPosition = 0;

	kScreenClear(&screen);

	len = kStrLen(KERNEL_TITLE);

	kScreenPrintPos(&screen, KERNEL_TITLE, len, 35, 1);
	kScreenPrintPos(&screen, KERNEL_VERSION, len, 35, 2);

	return;
}

