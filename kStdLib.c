/*
 * kStdLib.c
 *
 *  Created on: 29 de jul de 2020
 *      Author: thiago
 */

#include "kStdLib.h"

int kStrLen(char *str){
	char *tmpStr;

	tmpStr = str;

	while(*tmpStr != 0){
		tmpStr++;
	}
	return tmpStr - str;
}
