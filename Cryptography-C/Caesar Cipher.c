#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string[1000];
    int n, k, l;

    //printf("\n Created by Henrique Sartori Siqueira. Copyright %c 2019 Henrique Sartori Siqueira. All rights reserved. \n \n", 184);
    printf("\n Insert:\n 0 to close the program.\n 1 to encrypt a message.\n 2 to decrypt a message.\n ->  ");
    scanf("%d", &k);
    while(k != 0){
        printf("\n Insert the message: ");
        getchar();
        scanf("%[^\n]s",string);
        printf("\n Insert the key: ");
        scanf("%d", &n);
        l = strlen(string);
        system("clear");
        printf("\n Original message: \n%s",string);
        switch(k){
            case 1:
                for(int i = 0; i < l; i++){
                    if(string[i] >= 65 && string[i] <= 90){
                        string[i] += n;
                        if(string[i] > 90)
                            string[i] -= 26;
                    }
                    else if(string[i] >= 97 && string[i] <= 122){
                        string[i] += n;
                        if(string[i] > 122)
                            string[i] -= 26;
                    }
                }
                printf("\n Encrypted message: \n%s",string);
                break;
            case 2:
                for(int i = 0; i < l; i++){
                    if(string[i] >= 65 && string[i] <= 90){
                        string[i] -= n;
                        if(string[i] < 65)
                            string[i] += 26;
                    }
                    else if(string[i] >= 97 && string[i] <= 122){
                        string[i] -= n;
                        if(string[i] < 97)
                            string[i] += 26;
                    }
                }
                printf("\n Decrypted message: \n%s",string);
        }
        printf("\n\n\n Insert:\n 0 to close the program.\n 1 to encrypt a message.\n 2 to decrypt a message.\n ->  ");
        scanf("%d", &k);
    }
    return 0;
}
