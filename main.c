#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(void);                        //Menu funcion     

void EnRot(void);                       //Encription of rotaion cipher with key, function
void DeRot(void);                       //Decription of rotaion cipher with key, function
void EnSub(void);                       //Encription of substitution cipher with key, function 
void DeSub(void);                       //Decription of substitution cipher with key, function
void EnRot0Key(void);                   //Encription of rotation cipher without key, function
void DeSub0Key(void);                   //Decription of substitution cipher without key, function
int main()
{
   menu();
}

void menu(void) {
    char choice;
    printf("Please select an program to run: \n");
    printf("\n1. Encryption of a message with a rotation cipher given the message text and rotation amount\n");
    printf("\n2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("\n3. Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
    printf("\n4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions\n");
    printf("\n5. Decryption of a message encrypted with a rotation cipher given cipher text only\n");
    printf("\n6. Decryption of a message encrypted with a substitution cipher given cipher text only\n");
    scanf("%c", &choice);
    switch(choice)  {
        case '1': EnRot(); break;   
        case '2': DeRot(); break;   
        case '3': EnSub(); break;
        case '4': DeSub(); break;
        case '5': EnRot0Key(); break;
        case '6': DeSub0Key();  break;
        default: printf("Unknown option %c\nPlease enter 1, 2, 3, 4, 5, or 6\nPress 0 button to restart\n", choice);
        }
}

void EnRot(void)    {
    char str[100];
    printf("Enter a message to be encrypted: \n");
    scanf("%s", str);
    str[0] = 
    
    //scanf("%[^\n]s",str);
    //fgets(str, 100, stdin);
    printf("Reads: %s\n", str);
    
}


void DeRot(void)    {
    printf("hello 2");
}


void EnSub(void)    {
    printf("hello 3");
}


void DeSub(void)    {
    printf("hello 4");
}


void EnRot0Key(void)    {
    printf("hello 5");
}


void DeSub0Key(void)    {
    printf("hello 6");
}
































