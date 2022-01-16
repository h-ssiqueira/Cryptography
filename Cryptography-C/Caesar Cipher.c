#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(unsigned char string[], int key);
void decrypt(unsigned char string[], int key);

int main(){
    unsigned char string[1024];
    int n, k = 1;

    while(1){
		printf("\nInsert:\n\t0 to close the program.\n\t1 to encrypt a message.\n\t2 to decrypt a message.\n -> ");
		if(scanf("%d", &k) == -1)
            break;
        if(k < 1 || k > 2)
			break;
        printf("\nInsert the message: ");
        getchar();
        scanf("%[^\n]s",string);
        printf("\nInsert the key: ");
        scanf("%d", &n);
		n %= 26;
        printf("\nOriginal message: \n%s\n", string);
		k == 1 ? encrypt(string, n) : decrypt(string, n);
    }
    return 0;
}

void encrypt(unsigned char string[], int key){
	for(int i = 0; string[i] != '\0'; i++){
        if(string[i] >= 65 && string[i] <= 90){
            string[i] += key;
            if(string[i] > 90)
                string[i] -= 26;
        }
        else if(string[i] >= 97 && string[i] <= 122){
            string[i] += key;
            if(string[i] > 122)
                string[i] -= 26;
        }
    }
    printf("\nEncrypted message: \n%s\n", string);
}

void decrypt(unsigned char string[], int key){
	for(int i = 0; string[i] != '\0'; i++){
        if(string[i] >= 65 && string[i] <= 90){
            string[i] -= key;
            if(string[i] < 65)
                string[i] += 26;
        }
        else if(string[i] >= 97 && string[i] <= 122){
            string[i] -= key;
            if(string[i] < 97)
                string[i] += 26;
        }
    }
    printf("\nDecrypted message: \n%s\n", string);
}