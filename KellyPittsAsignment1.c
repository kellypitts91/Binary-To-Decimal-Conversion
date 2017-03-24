
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bin(char *b);
void dec(char *d);
char num[10], reply[5];
int i, len, total, decreaseValue;
int main() {
	printf("Type in a number (decimal or binary) to convert: ");
	gets(num);
	//printf("%s", num);
	len = strlen(num);
	if ((len > 8) || (num[0] == '-')){
		printf("That is an invalid number!");
		exit(0);
	}
	//Checking to see if input contains any letters.
	for (i = 0; i < len; i ++) {
		if (num[i] >= 'A') {
			printf("That is an invalid number!");
			exit(0);
		}
	}
	if ((num[0] == '0') || (num[0] == '1')) {
		if (num[1] >= '2') {
			dec(num);
			exit(0);
			//checking all the possibilities that could be binary or decimal.
		} else if ((strcmp(num, "1") == 0) ||(strcmp(num, "10") == 0) || 				
								(strcmp(num, "11") == 0) || (strcmp(num, "100") == 0) || (strcmp(num, "101") == 0) ||
								(strcmp(num, "110") == 0) || (strcmp(num, "111") == 0)) {
			printf("Is this number decimal (d) or binary (b)? ");
			gets(reply);
			if ((strcmp(reply, "d") == 0) || (strcmp(reply, "D") == 0)) {
				dec(num);
			}
			if ((strcmp(reply, "b") == 0) || (strcmp(reply, "B") == 0)) {
				bin(num);
			}
		} else if (strcmp(num, "0") != 0) {
			bin(num);
		}
	}
	if ((strcmp(num, "0") == 0) || (num[0] >= '2')) {
		dec(num);
	}	
}

void bin(char *b) { 			//'b' and 'bin' for 'binary'
	total = 0;					//Binary to decimal
	decreaseValue = 1;
	for (i = 0; i < len-1; i ++) {
		decreaseValue *= 2;
	}
	for (i = 0; i < len; i ++) {
		if ((b[i] != '1') && (b[i] != '0')) {
			printf("That is an invalid Number!");
			exit(0);
		}
		if (b[i] == '1') {
			total += decreaseValue;
		}
		decreaseValue /= 2;
	}
	printf("\nConverting binary to decimal. Answer is: %d", total);
}

void dec(char *d) {			//'d' and 'dec' for 'decimal'
	char binaryNum[10];		//Decimal to Binary
	int temp;
	total = 0;
	temp = 128;
	strcpy(binaryNum, "00000000");
	len = strlen(d);
	if ((num[0] == '0') && (num[1] >= '2')) {
		printf("That is an invalid number!");
			return;
	}
	//Converting from String to Integer.
	for (i = 0; i < len; i ++) {
		total = total * 10 + (d[i] - '0');
	}
	if (total > 255) {
		printf("That is an invalid number!");
			return;
	}
	//Replacing 0 with 1 if the number is higher (eg. 128, 64, 32...)
	for (i = 0; i < 8; i ++) {
		if (total >= temp){
			binaryNum[i] = '1';
			total -= temp;
		}
		temp /= 2;
	}
	printf("\nConverting decimal to binary. Answer is: %s", binaryNum);
}