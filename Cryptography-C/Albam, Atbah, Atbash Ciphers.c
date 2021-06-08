#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000

/*
Atbash:
	A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	Z Y X W V U T S R Q P O N M L K J I H G F E D C B A
*/
void bash(char *m, char *at);

/*
Atbam:
	A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	N O P Q R S T U V W X Y Z A B C D E F G H I J K L Z
*/
void bam(char *m, char *at);

/*
Atbah:
	A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
	I H G F N D C B A R Q P O E M L K J Z Y X W V U T S
*/
void bah(char *m, char *at);

int main(){
    char m[max];
    printf("\nInsert the message: ");
    scanf("%[^\n]s", m);
	char at[strlen(m)];
	at[strlen(m)] ^= at[strlen(m)];
	bam(m,at);
    printf("\nTo Albam:\n %s\n", at);
	bah(m,at);
    printf("\nTo Atbah:\n %s\n", at);
	bash(m,at);
    printf("\nTo Atbash:\n %s\n", at);
    return 0;
}

// Reverse letter of alphabet (e.g: a -> z, b -> y)
void bash(char *m, char *at){
	for(int i = 0; m[i] != '\0'; i++){
		if(m[i] > 64 && m[i] < 91)
			at[i] = 155 - m[i]; // max - (letter - min) = max + min - letter
		else if(m[i] > 96 && m[i] < 123)
			at[i] = 219 - m[i]; // max - (letter - min) = max + min - letter
		else
			at[i] = m[i];
	}
}

// Alphabet splited
void bah(char *m, char *at){
	for(int i = 0; m[i] != '\0'; i++){
		if(m[i] > 64 && m[i] < 74 && m[i] != 69)
			at[i] = 138 - m[i]; // min letter of sequence - letter + min letter crypted
		else if(m[i] > 96 && m[i] < 106 && m[i] != 101)
			at[i] = 202 - m[i]; // min letter of sequence - letter + min letter crypted
		else if(m[i] > 73 && m[i] < 83 && m[i] != 78)
			at[i] = 156 - m[i]; // min letter of sequence - letter + min letter crypted
		else if(m[i] > 105 && m[i] < 115 && m[i] != 110)
			at[i] = 220 - m[i]; // min letter of sequence - letter + min letter crypted
		else if(m[i] > 82 && m[i] < 91)
			at[i] = 173 - m[i]; // min letter of sequence - letter + min letter crypted
		else if(m[i] > 114 && m[i] < 122)
			at[i] = 237 - m[i]; // min letter of sequence - letter + min letter crypted
		else if(m[i] == 69 || m[i] == 101)
			at[i] = m[i] + 9;
		else if(m[i] == 78 || m[i] == 110)
			at[i] = m[i] - 9;
		else
			at[i] = m[i];
	}
}

// Split the alphabet in half
void bam(char *m, char *at){
	for(int i = 0; m[i] != '\0'; i++){
		if((m[i] > 64 && m[i] < 78) || (m[i] > 96 && m[i] < 110)) // A - M -> N - Z
			at[i] = 13 + m[i];
		else if((m[i] > 77 && m[i] < 90) || (m[i] > 109 && m[i] < 122)) // N - Y -> A - L
			at[i] = m[i] - 13;
		else
			at[i] = m[i];
	}
}
