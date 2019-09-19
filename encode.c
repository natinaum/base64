#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * example ="Alle Meine Entchen";
char * table="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
int main(int nargs, char ** cargs) {
	example=cargs[1];
	char * output=malloc(sizeof(char)*(strlen(example)*8/6));
	int j=0;
	int padding=strlen(example)%3;
	if(padding==2){padding=1;}
	if(padding==1){padding=2;}
	int i;
	if(strlen(example)>3){
		for(i=0;i<strlen(example)-3;i=i+3){
			output[j]=(example[i] & 0b11111100)>>2;
			j++;
			output[j]=((example[i] & 0b00000011)<<4)|((example[i+1]&0b11110000)>>4);
			j++;
			output[j]=((example[i+1]&0b00001111)<<2)|((example[i+2]&0b11000000)>>6);
			j++;
			output[j]=example[i+2]&0b00111111;
			j++;
		}
	}
	switch(padding){
		case 1:
			output[j]=(example[i] & 0b11111100)>>2;
			j++;
			output[j]=((example[i] & 0b00000011)<<4)|((example[i+1]&0b11110000)>>4);
			j++;
			output[j]=((example[i+1]&0b00001111)<<2);
			j++;
			output[j]=64;
			j++;
			break;
		
		case 2:
			output[j]=(example[i] & 0b11111100)>>2;
			j++;
			output[j]=((example[i] & 0b00000011)<<4);
			j++;
			output[j]=64;
			j++;
			output[j]=64;
			j++;
			break;
		default:
			output[j]=(example[i] & 0b11111100)>>2;
			j++;
			output[j]=((example[i] & 0b00000011)<<4)|((example[i+1]&0b11110000)>>4);
			j++;
			output[j]=((example[i+1]&0b00001111)<<2)|((example[i+2]&0b11000000)>>6);
			j++;
			output[j]=example[i+2]&0b00111111;
			printf("\n");
			j++;
			output[j]=-1;
			break;
	}
	for(int k=0;k<strlen(output);k++){
		if(output[k]==-1){
			break;
		}
		printf("%c",table[output[k]]);
	}
	printf("\n");
}


