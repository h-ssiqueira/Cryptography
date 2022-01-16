#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// encrypt = Kx mod 26 + (65 || 97)
// decrypt =

void encrypt(char *msg, int k){
	bool l,L;
	for(int i = 0; msg[i] != '\0'; i++){
		L = msg[i] > 64 && msg[i] < 91;
		l = msg[i] > 96 && msg[i] < 123;
		if(L || l){
			msg[i] = (msg[i] * k) % 26;
			if(msg[i] < 0)
				msg[i] *= -1;
			if(L)
				msg[i] += 65;
			else if(l)
				msg[i] += 97;
		}
	}
	printf("\nEncrypted message:\n%s\n", msg);
}

void decrypt(char *msg, int k){
	bool l, L;
	int inversemod, one;
	for(int i = 0; i < 26; i++){
		one = (k * i) % 26;
		if(one == 1)
			inversemod = i;
	}
	for(int i = 0; msg[i] != '\0'; i++){
		L = msg[i] > 64 && msg[i] < 91;
		l = msg[i] > 96 && msg[i] < 123;
		if(L || l){
			msg[i] = (inversemod * msg[i]+97) % 26;
			if(msg[i] < 0)
				msg[i] *= -1;
			if(L)
				msg[i] += 65;
			else if(l)
				msg[i] += 97;
		}
	}
	printf("\nDecrypted message:\n%s\n", msg);
}


int main(){
	char message[1024]; // 1 KB
	int op, key;
	while(1){
		printf("\nInsert:\n\t0 to close the program.\n\t1 to encrypt a message.\n\t2 to decrypt a message.\n ->  ");
		if(scanf("%d", &op) == -1)
			break;
		if(op < 0 || op > 2)
			break;
		printf("\nInsert the message: ");
		getchar();
		scanf("%[^\n]s", message);
		getchar();
		printf("\nInsert the key (number): ");
		if(scanf("%d", &key) == -1)
			break;
		op == 1 ? encrypt(message, key) : /*decrypt(message, key)*/printf("Not ready yet...");
	}
	return 0;
}