#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char x[1000];
    int l,z;
    //printf("\n Created by Henrique Sartori Siqueira. Copyright %c 2019 Henrique Sartori Siqueira. All rights reserved. \n \n", 184);
    do{
        printf("\n Insert the message = ");
        scanf("%[^\n]s",x);
        system("clear");
        printf("\n %s\n\n", x);
        l = strlen(x);
        for(int i = 0; i < l; i++) {
            switch(x[i]){
                case 32:printf("  ");
                    break;
                case 33:
                    printf(" -.-.-- ");
                    break;
                case 34:
                    printf(" .-..-. ");
                    break;
                case 36:
                    printf(" ...-..- ");
                    break;
                case 38:
                    printf(" .-... ");
                    break;
                case 39:
                    printf(" .----. ");
                    break;
                case 40:
                    printf(" -.--. ");
                    break;
                case 41:
                    printf(" -.--.- ");
                    break;
                case 43:
                    printf(" .-.-. ");
                    break;
                case 44:
                    printf(" --..-- ");
                    break;
                case 45:
                    printf(" -....- ");
                    break;
                case 46:
                    printf(" .-.-.- ");
                    break;
                case 47:
                    printf(" -..-. ");
                    break;
                case 48:
                    printf(" ----- ");
                    break;
                case 49:
                    printf(" .---- ");
                    break;
                case 50:
                    printf(" ..--- ");
                    break;
                case 51:
                    printf(" ...-- ");
                    break;
                case 52:
                    printf(" ....- ");
                    break;
                case 53:
                    printf(" ..... ");
                    break;
                case 54:
                    printf(" -.... ");
                    break;
                case 55:
                    printf(" --... ");
                    break;
                case 56:
                    printf(" ---.. ");
                    break;
                case 57:
                    printf(" ----. ");
                    break;
                case 58:
                    printf(" ---... ");
                    break;
                case 59:
                    printf(" -.-.-. ");
                    break;
                case 61:
                    printf(" -...- ");
                    break;
                case 63:
                    printf(" ..--.. ");
                    break;
                case 64:
                    printf(" .--.-. ");
                    break;
                case 65:
                    printf(" .- ");
                    break;
                case 66:
                    printf(" -... ");
                    break;
                case 67:
                    printf(" -.-. ");
                    break;
                case 68:
                    printf(" -.. ");
                    break;
                case 69:
                    printf(" . ");
                    break;
                case 70:
                    printf(" ..-. ");
                    break;
                case 71:
                    printf(" --. ");
                    break;
                case 72:
                    printf(" .... ");
                    break;
                case 73:
                    printf(" .. ");
                    break;
                case 74:
                    printf(" .--- ");
                    break;
                case 75:
                    printf(" -.- ");
                    break;
                case 76:
                    printf(" .-.. ");
                    break;
                case 77:
                    printf(" -- ");
                    break;
                case 78:
                    printf(" -. ");
                    break;
                case 79:
                    printf(" --- ");
                    break;
                case 80:
                    printf(" .--. ");
                    break;
                case 81:
                    printf(" --.- ");
                    break;
                case 82:
                    printf(" .-. ");
                    break;
                case 83:
                    printf(" ... ");
                    break;
                case 84:
                    printf(" - ");
                    break;
                case 85:
                    printf(" ..- ");
                    break;
                case 86:
                    printf(" ...- ");
                    break;
                case 87:
                    printf(" .-- ");
                    break;
                case 88:
                    printf(" -..- ");
                    break;
                case 89:
                    printf(" -.-- ");
                    break;
                case 90:
                    printf(" --.. ");
                    break;
                case 95:
                    printf(" ..--.- ");
                    break;
                case 97:
                    printf(" .- ");
                    break;
                case 98:
                    printf(" -... ");
                    break;
                case 99:
                    printf(" -.-. ");
                    break;
                case 100:
                    printf(" -.. ");
                    break;
                case 101:
                    printf(" . ");
                    break;
                case 102:
                    printf(" ..-. ");
                    break;
                case 103:
                    printf(" --. ");
                    break;
                case 104:
                    printf(" .... ");
                    break;
                case 105:
                    printf(" .. ");
                    break;
                case 106:
                    printf(" .--- ");
                    break;
                case 107:
                    printf(" -.- ");
                    break;
                case 108:
                    printf(" .-.. ");
                    break;
                case 109:
                    printf(" -- ");
                    break;
                case 110:
                    printf(" -. ");
                    break;
                case 111:
                    printf(" --- ");
                    break;
                case 112:
                    printf(" .--. ");
                    break;
                case 113:
                    printf(" --.- ");
                    break;
                case 114:
                    printf(" .-. ");
                    break;
                case 115:
                    printf(" ... ");
                    break;
                case 116:
                    printf(" - ");
                    break;
                case 117:
                    printf(" ..- ");
                    break;
                case 118:
                    printf(" ...- ");
                    break;
                case 119:
                    printf(" .-- ");
                    break;
                case 120:
                    printf(" -..- ");
                    break;
                case 121:
                    printf(" -.-- ");
                    break;
                case 122:
                    printf(" --.. ");
                    break;
				case 128:
					printf(" -.-.. ");
					break;
				case 129:
					printf(" ..-- ");
					break;
				case 130:
					printf(" ..-.. ");
					break;
				case 132:
					printf(" .-.- ");
					break;
				case 133:
					printf(" .--.- ");
					break;
				case 134:
					printf(" .--.- ");
					break;
				case 135:
					printf(" -.-.. ");
					break;
				case 138:
					printf(" .-..- ");
					break;
				case 142:
					printf(" .-.- ");
					break;
				case 143:
					printf(" .--.- ");
					break;
				case 144:
					printf(" ..-.. ");
					break;
				case 145:
					printf(" .-.- ");
					break;
				case 146:
					printf(" .-.- ");
					break;
				case 148:
					printf(" ---. ");
					break;
				case 150:
					printf(" ..-- ");
					break;
				case 153:
					printf(" ---. ");
					break;
				case 154:
					printf(" ..-- ");
					break;
				case 155:
					printf(" ---. ");
					break;
				case 157:
					printf(" ---. ");
					break;
				case 160:
					printf(" .--.- ");
					break;
				case 164:
					printf(" --.-- ");
					break;
				case 165:
					printf(" --.-- ");
					break;
				case 181:
					printf(" .--.- ");
					break;
				case 183:
					printf(" .--.- ");
					break;
				case 208:
					printf(" ..--. ");
					break;
				case 209:
					printf(" ..--. ");
					break;
				case 212:
					printf(" .-..- ");
					break;
				case 231:
					printf(" .--.. ");
					break;
				case 232:
					printf(" .--.. ");
					break;
				case 234:
					printf(" ..-- ");
					break;
                default:
                    printf(" ..... ");
            }
        }
        printf("\n\nAgain? (1 - y || 0 - n): ");
        scanf("%d", &z);
        getchar();
    }while(z != 0);
    return 0;
}
