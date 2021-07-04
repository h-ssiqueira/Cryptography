#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024 // 1 KB

void strupr(char *t);

void key_message(char *message, char *key, char *enc);

void encrypt(char *msg, char *key);

void decrypt(char *msg, char *key);

void check(char *text);

const char table[][28] = {
						" ABCDEFGHIJKLMNOPQRSTUVWXYZ\0",
						"AABCDEFGHIJKLMNOPQRSTUVWXYZ\0",
						"BBCDEFGHIJKLMNOPQRSTUVWXYZA\0",
						"CCDEFGHIJKLMNOPQRSTUVWXYZAB\0",
						"DDEFGHIJKLMNOPQRSTUVWXYZABC\0",
						"EEFGHIJKLMNOPQRSTUVWXYZABCD\0",
						"FFGHIJKLMNOPQRSTUVWXYZABCDE\0",
						"GGHIJKLMNOPQRSTUVWXYZABCDEF\0",
						"HHIJKLMNOPQRSTUVWXYZABCDEFG\0",
						"IIJKLMNOPQRSTUVWXYZABCDEFGH\0",
						"JJKLMNOPQRSTUVWXYZABCDEFGHI\0",
						"KKLMNOPQRSTUVWXYZABCDEFGHIJ\0",
						"LLMNOPQRSTUVWXYZABCDEFGHIJK\0",
						"MMNOPQRSTUVWXYZABCDEFGHIJKL\0",
						"NNOPQRSTUVWXYZABCDEFGHIJKLM\0",
						"OOPQRSTUVWXYZABCDEFGHIJKLMN\0",
						"PPQRSTUVWXYZABCDEFGHIJKLMNO\0",
						"QQRSTUVWXYZABCDEFGHIJKLMNOP\0",
						"RRSTUVWXYZABCDEFGHIJKLMNOPQ\0",
						"SSTUVWXYZABCDEFGHIJKLMNOPQR\0",
						"TTUVWXYZABCDEFGHIJKLMNOPQRS\0",
						"UUVWXYZABCDEFGHIJKLMNOPQRST\0",
						"VVWXYZABCDEFGHIJKLMNOPQRSTU\0",
						"WWXYZABCDEFGHIJKLMNOPQRSTUV\0",
						"XXYZABCDEFGHIJKLMNOPQRSTUVW\0",
						"YYZABCDEFGHIJKLMNOPQRSTUVWX\0",
						"ZZABCDEFGHIJKLMNOPQRSTUVWXY\0"};

int main(){
	char message[max], key[max];
	int op;
	while(1){
		do{
			printf("\nInsert:\n\t0 to close the program.\n\t1 to encrypt a message.\n\t2 to decrypt a message.\n ->  ");
			scanf("%d", &op);
		}while(op < 0 || op > 2);
		if(op == 0)
			break;
		printf("\nInsert the message: ");
		getchar();
		scanf("%[^\n]s", message);
		getchar();
		printf("\nInsert the key (word): ");
		scanf("%[^\n]s", key);
		strupr(message);
		strupr(key);
		check(message);
		check(key);
		op == 1 ? encrypt(message, key) : decrypt(message, key);
	}
	return 0;
}

void strupr(char *t){
	for(int i = 0; i < strlen(t); i++)
		if(t[i] > 96 && t[i] < 123)
			t[i] -= 32;
}

// Modify the string to store the key in message (e.g.: vigenere (message) code (key) -> codecode)
void key_message(char *message, char *key, char *enc){
	for(int i = 0, j = 0; message[i] != '\0'; i++){
		if(message[i] > 64 && message[i] < 91){
			while(!(key[j] > 64 && key[j] < 91)){
				j++;
				if(j == strlen(key))
					j ^= j;
			}
			enc[i] = key[j];
			j++;
			if(j == strlen(key))
				j ^= j;
		}
		else
			enc[i] = message[i];
	}
	enc[strlen(message)] = '\0';
}

void encrypt(char *msg, char *key){
	char enc[strlen(msg)];
	key_message(msg, key, enc);
	for(int i = 0; msg[i] != '\0'; i++)
		if(enc[i] > 64 && enc[i] < 91)
			enc[i] = table[enc[i]-64][msg[i]-64];
	printf("\nEncrypted message:\n%s\n", enc);

}

void decrypt(char *msg, char *key){
	char dec[strlen(msg)];
	key_message(msg,key,dec);
	for(int i = 0; msg[i] != '\0'; i++){
		if(dec[i] > 64 && dec[i] < 91)
			for(int j = 1; j < 27; j++){
				if(table[dec[i]-64][j] == msg[i]){
					dec[i] = table[0][j];
					break;
				}
			}
	}
	printf("\nDecrypted message:\n%s\n", dec);
}

// Check if the text has letters
void check(char *text){
	for(int i = 0; text[i] != '\0'; i++)
		if(text[i] > 64 && text[i] < 91)
			return;
	printf("\nText don't have letters.\n");
	exit(1);
}

