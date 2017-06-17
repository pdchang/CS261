/* CS261- Assignment 1 - Q.5*/
/* Name:Philip Chang
 * Date:January 22, 2017
 * Solution description:user inputs word, word is then modified to have alternating upper case
 * then lower case characters otherwise known as "sticky keys" or studlykeys, the prints out
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
    int i = 0;
    do{
        if(i % 2 == 0 && word[i] >= 'a'){
            word[i] = toUpperCase(word[i]);
        }
        else if(i % 2 == 1 && word[i] < 'a'){
            word[i] = toLowerCase(word[i]);
        }
        i++;
    }while(word[i] != '\0');
}


int main(){
    char word[256];
    printf("Please enter one word to convert to sticky keys\n");
    /*Read word from the keyboard using scanf*/
    scanf("%s", word);
    /*Call sticky*/
    sticky(word);
    /*Print the new word*/
    printf("%s\n", word);
    return 0;
}
