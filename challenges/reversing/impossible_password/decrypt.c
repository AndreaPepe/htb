#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(){
	char *pass = "t18k?1k;0o0=0k9=rK]A";
	char c;
	int i;

	for (i=strlen(pass) - 1; i >=0; i--){
		printf("%c", pass[i] ^ 9);
	} 

	printf("\n");
}
