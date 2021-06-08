#include <stdio.h>
#include <string.h>

int main(){
    int key;
    char msg[1000];

    printf("Insert the key: ");
    scanf("%d", &key); // key == 32 convert case of letter
    printf("\nInsert the message: ");
    scanf("\n%[^\n]s",msg);
    printf("\nEN/DEcrypted: \n");
    for(int i = 0; msg[i] != '\0'; i++)
        msg[i] > 64 && msg[i] < 91 || msg[i] > 96 && msg[i] < 123 ? printf("%c", msg[i]) : printf("%c", key ^ msg[i]);
	printf("\n");
    return 0;
}
