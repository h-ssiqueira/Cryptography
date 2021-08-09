#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// encrypt = (a * (letter - (65 || 97) + b)) mod 26 + (65 || 97)
// decrypt =

void encrypt(char *msg, int a, int b){
	bool l,L;
	for(int i = 0; msg[i] != '\0'; i++){
		L = msg[i] > 64 && msg[i] < 91;
		l = msg[i] > 96 && msg[i] < 123;
		if(L || l){
			if(L)
				msg[i] = ((msg[i] - 65) * a + b) % 26 + 65;
			else if(l)
				msg[i] = ((msg[i] - 97) * a + b) % 26 + 97;
			if(msg[i] < 0)
				msg[i] *= -1;
		}
	}
	printf("\nEncrypted message:\n%s\n", msg);
}

void decrypt(char *msg, int a, int b){
	bool l, L;
	int inversemod, one;
	for(int i = 0; i < 26; i++){
		one = (a * i) % 26;
		if(one == 1)
			inversemod = i;
	}
	printf("%d ", inversemod);
	for(int i = 0; msg[i] != '\0'; i++){
		L = msg[i] > 64 && msg[i] < 91;
		l = msg[i] > 96 && msg[i] < 123;
		if(L || l){
			msg[i] += ((((26-inversemod) * (msg[i]-'a' + b)) % 26) + 'a');
			if(msg[i] < 0)
				msg[i] *= -1;
			/*if(L)
				msg[i] += 65;
			else if(l)
				msg[i] += 97;*/
		}
	}
	printf("\nDecrypted message:\n%s\n", msg);
}

int main(){
	char message[1024]; // 1 KB
	int op, A, B;
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
		printf("\nInsert the key A and B (number number): ");
		scanf("%d %d", &A, &B);
		op == 1 ? encrypt(message, A, B) : /*decrypt(message, A, B)*/printf("Not ready yet...");
	}
	return 0;
}