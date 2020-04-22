#include <stdio.h>
#include <string.h>

int main() {
    int key, l;
    char msg[1000];

    printf("Insert the key: ");
    scanf("%d", &key);
    printf("\nInsert the message: ");
    getchar();
    scanf("%[^\n]s",msg);
    l = strlen(msg);
    printf("\nEN/DEcrypted: \n");
    for (int i = 0; i < l; i++)
        msg[i] == 32 ? printf(" ") : printf("%c", key ^ msg[i]);

    return 0;
}
