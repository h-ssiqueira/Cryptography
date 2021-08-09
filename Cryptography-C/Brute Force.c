#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#define SIZE_KEY 8
#define THREAD_MAX 4

/*
* Complexity:
*   Number of tries per thread = (Possible Characters ^ Range Of Password) / Number Of Threads
*   In the case with only numbers -> 10^8 / 4 = 25 000 000 (25 million tries)
*   In the case with only lower/upper case letters -> 26^8 / 4 = 52 206 766 144 tries (52.2 billion tries)
*   In the case with only letters -> 52^8 / 4 = 1.336493213 . 10^13 (~ 13.365 trillion tries)
*   In the case with only letters and numbers -> 62^8 / 4 = 5.45850264 . 10^13 (~ 54.585 trillion tries)
*
* Command to unzip "unzip <file> -P <password>"
*/

static unsigned char secret_key[SIZE_KEY];
static const unsigned char characters[] =
"0123456789"
//"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//"abcdefghijklmnopqrstuvwxyz"
//"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
//"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
;
static const int len = sizeof(characters) - 1;
bool found = false;

typedef struct thread{
    pthread_t id;
    int num;
    unsigned char *start_end;
}thread;

void print_thread(thread t);
void GenerateSecretKey(unsigned char *k);
bool SecretKeyTest(unsigned char *key);
void *SecretKeySearch(void *args);


int main(){
	srand(time(NULL));
	GenerateSecretKey(secret_key);
	thread *threads = calloc(THREAD_MAX,sizeof(thread)), *i;
    int j;
    j ^= j;
    if(!threads){
        printf("Fail to allocate the thread array\n");
        exit(1);
    }
    for(i = threads; i < threads + THREAD_MAX; i++){
        i->start_end = calloc(3,sizeof(unsigned char));
        if(!i->start_end){
            printf("Fail to allocate the thread string\n");
            exit(1);
        }
        if(i == threads){
            *(i->start_end) = *characters;
            *(i->start_end + 1) = ceil(len / THREAD_MAX) + *(i->start_end);
            if(*(i->start_end + 1) > 57 && *(i->start_end + 1) < 65){
                *(i->start_end + 1) -= 57;
                *(i->start_end + 1) += 65;
            }
            else if(*(i->start_end + 1) > 90 && *(i->start_end + 1) < 97){
                *(i->start_end + 1) -= 90;
                *(i->start_end + 1) += 97;
            }
        }
        else{
            *(i->start_end) = *((i-1)->start_end + 1) + 1;
            if(*(i->start_end) > 57 && *(i->start_end) < 65)
                *(i->start_end) = 65;
            else if(*(i->start_end) > 90 && *(i->start_end) < 97)
                *(i->start_end) = 97;
		    *(i->start_end + 1) = *((i-1)->start_end + 1) + 1 + ceil(len / THREAD_MAX);
            if(*(i->start_end + 1) > 57 && *(i->start_end + 1) < 65)
                *(i->start_end + 1) += 8;
            else if(*(i->start_end + 1) > 90 && *(i->start_end + 1) < 97)
                *(i->start_end + 1) += 7;
            if(i == threads + THREAD_MAX - 1 && *(i->start_end + 1) != *(characters + len - 1))
                *(i->start_end + 1) = *(characters + len - 1);
        }
        i->num = ++j;
        //print_thread(*i); // For debug
        pthread_create(&(i->id), NULL, SecretKeySearch, (void *)i);
        sleep(1);
    }
	for(i = threads; i < threads + THREAD_MAX; i++)
		pthread_join(i->id, NULL);
    for(i = threads; i < threads + THREAD_MAX; i++)
        free(i->start_end);
    free(threads);
	return 0;
}

void GenerateSecretKey(unsigned char *k){
	for(unsigned char *i = k; i < k + SIZE_KEY; i++)
		*i = characters[rand() % len];
	*(k + SIZE_KEY) ^= *(k + SIZE_KEY);
}

bool SecretKeyTest(unsigned char *key){
	if(strcmp(key, secret_key) != 0)
		return false;
	printf("Congratulations, you discovered the secret key: %s\n",key);
	return true;
}

void *SecretKeySearch(void *args){
    thread *info;
    long count;
	unsigned char *key = calloc(SIZE_KEY,sizeof(unsigned char)), *i;
    if(!key){
        printf("Failed to allocate the string\n");
        exit(1);
    }
    info = (thread *) args;
    count ^= count;
	*key = *(info->start_end);
    //print_thread(*info); // For debug
    for(i = key + SIZE_KEY-1; i > key; i--)
        *i = *characters;
	while(!SecretKeyTest(key) && !found){
		i = SIZE_KEY - 1 + key;
		(*i)++;
		while(*i > 57 && *i < 65 || *i > 90 && *i < 97 || *i > 122){
            if(*i == 58){
                if(len == 10)
                    *i-- = 48;
                else if(len > 10)
                    *i-- = 65;
            }
            else if(*i == 91){
                if(len == 52 || len == 62)
                    *i-- = 97;
                else if(len == 26)
                    *i-- = 65;
                else if(len == 10)
                    *i-- = 48;
            }
            else if(*i == 123){
                if(len == 26)
                    *i-- = 97;
                else if(len == 52)
                    *i-- = 65;
                else if(len == 10 || len == 62)
                    *i-- = 48;
            }
            (*i)++;
		}
		if(*key == *(info->start_end + 1) + 1 || *key >= *(characters + len-1) + 1){
            free(key);
            return 0;
        }
		count++;
		if(count % 1000000000 == 0)
			printf("Thread %d: %ld hundred million tries done\n", info->num, count / 1000000000);
	}
    free(key);
    found = true;
	return 0;
}

// Function to print the information of the thread struct for debug
void print_thread(thread t){
    printf("Thread num = %d\nStart-end = %s\n\n", t.num, t.start_end);
}