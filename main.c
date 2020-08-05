
#include <stdio.h>
#include "kScreen.h"
#include "kString.h"

#define KERNEL_TITLE "Nomad Kernel"
#define KERNEL_VERSION "Stay Forever"

void printScreen(char *strPtr){
    int i;
    for (i = 0; i < (SCREEN_COLS * SCREEN_LINES); i++){
        if (i % 80 == 0){
            printf("\n");
        }
        if (strPtr[i * SCREEN_ELEMENT_BYTES] > 31 && strPtr[i * SCREEN_ELEMENT_BYTES] < 127){
            printf("%c", strPtr[i * SCREEN_ELEMENT_BYTES]);
        }else{
            printf("%x", strPtr[i * SCREEN_ELEMENT_BYTES]);
        }
    }    
    printf("\n");
}


int main(int argc, char **argv){
    char screen_mem[SCREEN_COLS * SCREEN_LINES * SCREEN_ELEMENT_BYTES];
    int i;

    for (i = 0; i < SCREEN_COLS * SCREEN_LINES * SCREEN_ELEMENT_BYTES; i++){
        screen_mem[i] = 0;        
    }   

    K_SCREEN screen;
	unsigned int len;
	const char *strKTitle = KERNEL_TITLE;
	const char *strKVersion = KERNEL_VERSION;

	screen.screenPtr = screen_mem;
	screen.screenPosition = 0;

	kScreenClear(&screen);

	len = kStrLen(KERNEL_TITLE);
    
	kScreenPrintPos(&screen, KERNEL_TITLE, len, 35, 1);
	kScreenPrintPos(&screen, KERNEL_VERSION, len, 35, 2);

    printScreen(screen_mem);

    

}