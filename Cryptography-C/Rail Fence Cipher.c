#include <stdio.h>
#include <math.h>
#include <string.h>

void encrypt(char *str, int rails);
void decrypt(char *str, int rails);

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
        printf("\nInsert the number of rails: ");
        if(scanf("%d", &n) == -1)
            break;
        if(n < 0)
            n *= -1;
        else if(n == 0)
            break;
        printf("\nOriginal message: \n%s\n", string);
		k == 1 ? encrypt(string, n) : decrypt(string, n);
    }
    return 0;
}

void encrypt(char *str, int rails){
    int len = strlen(str);
    char msg[len];
    int i = 0,j = 0,k = 0;
    while(k < rails){
        for(i = k; i < len; i += rails,j++)
            msg[j] = str[i];
        k++;
    }
    msg[j] ^= msg[j];
    printf("\nEncrypted message:\n%s\n", msg);
}

void decrypt(char *str, int rails){
    int len = strlen(str);
    char msg[len];
    int i = 0,j = 0, k = 0, gap = round((float)len/rails);
    printf("%d\n",gap);
    while(i < rails){
        for(j = i; j < len;j += gap){
            msg[k++] = str[j];
        }
        i++;
    }
    msg[j] ^= msg[j];
    printf("\nDecrypted message:\n%s\n", msg);
}