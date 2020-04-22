#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
int main(){
    char bash[max] = {"\0"}, bah[max] = {"\0"}, bam[max] = {"\0"}, m[max];

    //printf("\n Created by Henrique Sartori Siqueira. Copyright %c 2019 Henrique Sartori Siqueira. All rights reserved. \n \n", 184);
    printf("\n Insert the message: ");

    scanf("%[^\n]s",m);

    system("clear");

    printf("\n %s\n", m);

    for(int i = 0; m[i] != '\0'; i++){
        switch(m[i]){
        case 32:
            bash[i] = 32;
            bam[i] = 32;
            bah[i] = 32;
            break;
        //upper cases
        case 65:
            bash[i] = 90;
            bam[i] = 78;
            bah[i] = 73;
            break;
        case 66:
            bash[i] = 89;
            bam[i] = 79;
            bah[i] = 72;
            break;
        case 67:
            bash[i] = 88;
            bam[i] = 80;
            bah[i] = 71;
            break;
        case 68:
            bash[i] = 87;
            bam[i] = 81;
            bah[i] = 70;
            break;
        case 69:
            bash[i] = 86;
            bam[i] = 82;
            bah[i] = 78;
            break;
        case 70:
            bash[i] = 85;
            bam[i] = 83;
            bah[i] = 68;
            break;
        case 71:
            bash[i] = 84;
            bam[i] = 84;
            bah[i] = 67;
            break;
        case 72:
            bash[i] = 83;
            bam[i] = 85;
            bah[i] = 66;
            break;
        case 73:
            bash[i] = 82;
            bam[i] = 86;
            bah[i] = 65;
            break;
        case 74:
            bash[i] = 81;
            bam[i] = 87;
            bah[i] = 82;
            break;
        case 75:
            bash[i] = 80;
            bam[i] = 88;
            bah[i] = 81;
            break;
        case 76:
            bash[i] = 79;
            bam[i] = 89;
            bah[i] = 80;
            break;
        case 77:
            bash[i] = 78;
            bam[i] = 90;
            bah[i] = 79;
            break;
        case 78:
            bash[i] = 77;
            bam[i] = 65;
            bah[i] = 69;
            break;
        case 79:
            bash[i] = 76;
            bam[i] = 66;
            bah[i] = 77;
            break;
        case 80:
            bash[i] = 75;
            bam[i] = 67;
            bah[i] = 76;
            break;
        case 81:
            bash[i] = 74;
            bam[i] = 68;
            bah[i] = 75;
            break;
        case 82:
            bash[i] = 73;
            bam[i] = 69;
            bah[i] = 74;
            break;
        case 83:
            bash[i] = 72;
            bam[i] = 70;
            bah[i] = 90;
            break;
        case 84:
            bash[i] = 71;
            bam[i] = 71;
            bah[i] = 89;
            break;
        case 85:
            bash[i] = 70;
            bam[i] = 72;
            bah[i] = 88;
            break;
        case 86:
            bash[i] = 69;
            bam[i] = 73;
            bah[i] = 87;
            break;
        case 87:
            bash[i] = 68;
            bam[i] = 74;
            bah[i] = 86;
            break;
        case 88:
            bash[i] = 67;
            bam[i] = 75;
            bah[i] = 85;
            break;
        case 89:
            bash[i] = 66;
            bam[i] = 76;
            bah[i] = 84;
            break;
        case 90:
            bash[i] = 65;
            bam[i] = 77;
            bah[i] = 83;
            break;
        //lower case
        case 97:
            bash[i] = 122;
            bam[i] = 110;
            bah[i] = 105;
            break;
        case 98:
            bash[i] = 121;
            bam[i] = 111;
            bah[i] = 104;
            break;
        case 99:
            bash[i] = 120;
            bam[i] = 112;
            bah[i] = 103;
            break;
        case 100:
            bash[i] = 119;
            bam[i] = 113;
            bah[i] = 102;
            break;
        case 101:
            bash[i] = 118;
            bam[i] = 114;
            bah[i] = 110;
            break;
        case 102:
            bash[i] = 117;
            bam[i] = 115;
            bah[i] = 100;
            break;
        case 103:
            bash[i] = 116;
            bam[i] = 116;
            bah[i] = 99;
            break;
        case 104:
            bash[i] = 115;
            bam[i] = 117;
            bah[i] = 98;
            break;
        case 105:
            bash[i] = 114;
            bam[i] = 118;
            bah[i] = 97;
            break;
        case 106:
            bash[i] = 113;
            bam[i] = 119;
            bah[i] = 114;
            break;
        case 107:
            bash[i] = 112;
            bam[i] = 120;
            bah[i] = 113;
            break;
        case 108:
            bash[i] = 111;
            bam[i] = 121;
            bah[i] = 112;
            break;
        case 109:
            bash[i] = 110;
            bam[i] = 122;
            bah[i] = 111;
            break;
        case 110:
            bash[i] = 109;
            bam[i] = 97;
            bah[i] = 101;
            break;
        case 111:
            bash[i] = 108;
            bam[i] = 98;
            bah[i] = 109;
            break;
        case 112:
            bash[i] = 107;
            bam[i] = 99;
            bah[i] = 108;
            break;
        case 113:
            bash[i] = 106;
            bam[i] = 100;
            bah[i] = 107;
            break;
        case 114:
            bash[i] = 105;
            bam[i] = 101;
            bah[i] = 106;
            break;
        case 115:
            bash[i] = 104;
            bam[i] = 102;
            bah[i] = 122;
            break;
        case 116:
            bash[i] = 103;
            bam[i] = 103;
            bah[i] = 121;
            break;
        case 117:
            bash[i] = 102;
            bam[i] = 104;
            bah[i] = 120;
            break;
        case 118:
            bash[i] = 101;
            bam[i] = 105;
            bah[i] = 119;
            break;
        case 119:
            bash[i] = 100;
            bam[i] = 106;
            bah[i] = 118;
            break;
        case 120:
            bash[i] = 99;
            bam[i] = 107;
            bah[i] = 117;
            break;
        case 121:
            bash[i] = 98;
            bam[i] = 108;
            bah[i] = 116;
            break;
        case 122:
            bash[i] = 97;
            bam[i] = 109;
            bah[i] = 115;
            break;
        }
    }
    printf("\n To Albam:\n %s\n", bam);
    printf("\n To Atbah:\n %s\n", bah);
    printf("\n To Atbash:\n %s\n", bash);

    return 0;
}
