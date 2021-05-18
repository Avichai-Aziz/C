//Avichai Aziz & Asaf Ben Shabat. 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int hash_arr(const char* str){ //hash func using array
    int c = 0;
    unsigned long h = 5381;
    for (int i =0; str[i] != '\0'; i++){
        c = str[i];
        h = h*33+c;
    }
    return h; //return the ascii value + h of the string
}

int hash_ptr(const char* str){ //hash func using pointers
    int c = 0;
    unsigned long h = 5381;
    while (*str != '\0'){
        int c = *str;
        h = h*33+c;
        str++;
    }
    return h; //return the ascii value + h of the string
}

bool is_legal_word(const char* words){ //checks if the string has letter only
    int len = strlen(words); //the length of the string
    for (int i = 0; i<len;i++){
        if(!(words[i] >= 'a' && words[i] <= 'z' || words[i] >= 'A' && words[i] <= 'Z'))
        return false; // 0
    }
    return true; /// 1  
}

void word_tolower(char* str){ //lowercase the string using pointers
    while (*str != '\0') {   
        if(*str >='A' && *str<='Z'){
            *str = *str + 32;
    }
      str++; //promotes the pointer by 1
   }
}
    
int main(){
    char word_hash[500000] = {0};
    char cmd[10] = {}; //the command input
    char str[64] = {}; //the string input
    while (true){
        unsigned long i = 0;
        printf("$ ");
        scanf("%s",cmd); //the command input of the user
        if (!strcmp(cmd,"EXIT")) //compare between cmd and "EXIT"
        {
            break;
        }

        scanf("%s",str); //the str input of the user
        if (!strcmp(cmd,"ADD") && (is_legal_word(str))){ //compare between cmd and "ADD" and check if the string is legal
            word_tolower(str); //lowcase the string
            i = hash_arr(str); //the index of the string in the array -with hash_arr func
            word_hash[i%500000] = 1;        
        }

        else if (!strcmp(cmd,"CHECK") && (is_legal_word(str))){
            word_tolower(str); //lowcase the string
            i = hash_ptr(str); //the index of the string in the array -with hash_ptr func
            (word_hash[i%500000] == 1)? printf("exists\n") : printf("does not exist\n");
        }

        else
        {
            printf("illegal command\n");
            fflush(stdin); //clean the input channel
        }  

    }
    return 0;
}
