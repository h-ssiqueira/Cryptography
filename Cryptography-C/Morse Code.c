#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char x[1000];
    printf("\n Insert the message = ");
    scanf("%[^\n]s",x);
    printf("\n\n%s\nMorse code:\n", x);
    for(int i = 0; x[i] != '\0'; i++){
        switch(x[i]){
            case ' ': printf("/ "); break;
            case '!': printf("-.-.-- "); break;
            case '\"': printf(".-..-. "); break;
            case '$': printf("...-..- "); break;
            case '&': printf(".-... "); break;
            case '\'': printf(".----. "); break;
            case '(': printf("-.--. "); break;
            case ')': printf("-.--.- "); break;
            case '+': printf(".-.-. "); break;
            case ',': printf("--..-- "); break;
            case '-': printf("-....- "); break;
            case '.': printf(".-.-.- "); break;
            case '/': printf("-..-. "); break;
            case '0': printf("----- "); break;
            case '1': printf(".---- "); break;
            case '2': printf("..--- "); break;
            case '3': printf("...-- "); break;
            case '4': printf("....- "); break;
            case '5': printf("..... "); break;
            case '6': printf("-.... "); break;
            case '7': printf("--... "); break;
            case '8': printf("---.. "); break;
            case '9': printf("----. "); break;
            case ':': printf("---... "); break;
            case ';': printf("-.-.-. "); break;
            case '=': printf("-...- "); break;
            case '?': printf("..--.. "); break;
            case '@': printf(".--.-. "); break;
			case 'a':
            case 'A': printf(".- "); break;
			case 'b':
            case 'B': printf("-... "); break;
			case 'c':
            case 'C': printf("-.-. "); break;
			case 'd':
            case 'D': printf("-.. "); break;
			case 'e':
            case 'E': printf(". "); break;
			case 'f':
            case 'F': printf("..-. "); break;
			case 'g':
            case 'G': printf("--. "); break;
			case 'h':
            case 'H': printf(".... "); break;
			case 'i':
            case 'I': printf(".. "); break;
			case 'j':
            case 'J': printf(".--- "); break;
			case 'k':
            case 'K': printf("-.- "); break;
			case 'l':
            case 'L': printf(".-.. "); break;
			case 'm':
            case 'M': printf("-- "); break;
			case 'n':
            case 'N': printf("-. "); break;
			case 'o':
            case 'O': printf("--- "); break;
			case 'p':
            case 'P': printf(".--. "); break;
			case 'q':
            case 'Q': printf("--.- "); break;
			case 'r':
            case 'R': printf(".-. "); break;
			case 's':
            case 'S': printf("... "); break;
			case 't':
            case 'T': printf("- "); break;
			case 'u':
            case 'U': printf("..- "); break;
			case 'v':
            case 'V': printf("...- "); break;
			case 'w':
            case 'W': printf(".-- "); break;
			case 'x':
            case 'X': printf("-..- "); break;
			case 'y':
            case 'Y': printf("-.-- "); break;
			case 'z':
            case 'Z': printf("--.. "); break;
            case '_': printf("..--.- "); break;
			case 'ç':
			case 'Ç': printf("-.-.. "); break;
			case 'È':
			case 'è': printf(".-..- "); break;
			case 'ä':
			case 'Ä': printf(".-.- "); break;
			case 'é':
			case 'É': printf("..-.. "); break;
			case 'æ':
			case 'Æ': printf(".-.- "); break;
			case 'ö':
			case 'Ö': printf("---. "); break;
			case 'ü':
			case 'Ü': printf("..-- "); break;
			case 'ø':
			case 'Ø': printf("---. "); break;
			case 'ñ':
			case 'Ñ': printf("--.-- "); break;
			case 'å':
			case 'Å':
			case 'á':
			case 'Á':
			case 'à':
			case 'À': printf(".--.- "); break;
			case 'ð':
			case 'Ð': printf("..--. "); break;
			case 'þ':
			case 'Þ': printf(".--.. "); break;
			case 'û':
			case 'Û': printf("..-- "); break;
            default: printf("..... ");
        }
    }
	printf("\n");
    return 0;
}
