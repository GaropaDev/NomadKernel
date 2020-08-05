/*
 * kString.c
 *
 *  Created on: 5 de ago de 2020
 *      Author: thiago
 */


#include "kString.h"

int kStrLen(char *str){
	char *tmpStr;

	tmpStr = str;

	while(*tmpStr != 0){
		tmpStr++;
	}
	return tmpStr - str;
}

void kMemset(char *str, char byte, unsigned int len){
	unsigned int i;

	for(i = 0; i < len; i++){
		*str = 0;
		str++;
	}
}

void kBzero(char *str, unsigned int len){
	kMemset(str, 0, len);
}
