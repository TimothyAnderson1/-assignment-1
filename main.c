#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(void);                        //Menu funcion     
void EnRot(void);                       //Encription of rotaion cipher with key, function
void DeRot(void);                       //Decription of rotaion cipher with key, function
void EnSub(void);                       //Encription of substitution cipher with key, function 
void DeSub(void);                       //Decription of substitution cipher with key, function
void DeRot0Key(void);                   //Decription of rotation cipher without key, function
void DeSub0Key(void);                   //Decription of substitution cipher without key, function


int main()
{
   menu();
}

void menu(void) {
    char choice;
    printf("Please select an program to run: \n");
    printf("\n1. Encryption of a message with a rotation cipher given the message text and rotation amount");
    printf("\n2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount");
    printf("\n3. Encryption of a message with a substitution cipher given message text and alphabet substitution");
    printf("\n4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions");
    printf("\n5. Decryption of a message encrypted with a rotation cipher given cipher text only");
    printf("\n6. Decryption of a message encrypted with a substitution cipher given cipher text only\n");
    scanf("%c", &choice);
    switch(choice)  {
        case '1': EnRot(); break;   
        case '2': DeRot(); break;   
        case '3': EnSub(); break;
        case '4': DeSub(); break;
        case '5': DeRot0Key(); break;
        case '6': DeSub0Key();  break;
        default: printf("Unknown option %c\nPlease enter 1, 2, 3, 4, 5, or 6\nPress 0 button to restart\n", choice);
        }
}

/******************************************************************************!!!!!!!MAYBE NEED TO FIX THIS!!!!!!!*/

void EnRot(void)    {
    char str[100];
    int key, i;
    printf("Enter a message to be Encrypted: \n");
    scanf(" %[^\n]%*c",str);
    printf("Enter a key to totate the message:\n");
    scanf("%d", &key);
    
    while( key < 0 || key > 25)   {
        printf("Please enter a key between 0 and 26:");
        scanf("%d", &key);
    }
    
        for(i = 0; i < strlen(str); i++)  {
            if((int)str[i] >= 97 && (int)str[i] <= 122) {
                if((int)str[i] - key < 97) {
                    str[i] += 26;
                }
                str[i] = str[i] - 32 - key;
            }
            else if((int)str[i] >= 65 && (int)str[i] <= 90) {
                if((int)str[i] - key < 65)  {
                    str[i] += 26;
                }
                str[i] = str[i] - key;
            }
        }
        
    printf("Encrypted message: %s\n", str);
}


/******************************************************************************/


void DeRot(void)    {
    char str[100];
    int key, i;
    printf("Enter a message to be Decrypted: \n");
    scanf(" %[^\n]%*c",str);
        printf("Enter the key to reverse the rotation of the message:\n");
    scanf("%d", &key);
    
    while( key < 0 || key > 25)   {
        printf("Please enter a key between 0 and 26:");
        scanf("%d", &key);
    }
    
        for(i = 0; i < strlen(str); i++)  {
            if((int)str[i] >= 97 && (int)str[i] <= 122) {
                if((int)str[i] + key >122) {
                    str[i] -= 26;
                }
                str[i] = str[i] - 32 + key;
            }
            else if((int)str[i] >= 65 && (int)str[i] <= 90) {
                if((int)str[i] + key > 90)  {
                    str[i] -= 26;
                }
                str[i] = str[i] + key;
            }
        }
        
    printf("Decrypted code: %s", str);
    
}


/******************************************************************************/


void EnSub(void)    {
    char str[100], key[100];
    int count = 0, i = 0, x= 65;
    
    printf("Enter a message to be encrypted: \n");
    scanf(" %[^\n]%*c",str);
    for(i = 0; i < strlen(str); i++)    {
        if(str[i] >= 97 && str[i] <=122)    {
            str[i] -= 32;
        }
    } 
    
    printf("Enter the substitution key: \n");
    scanf(" %[^\n]%*c",key);
    for(i = 0; i < strlen(key); i++)    {
        if(key[i] >= 97 && key[i] <=122)    {
            key[i] -= 32;
        }
    }
    
    for(i = 0; i < strlen(str); i++)    {
        count = 0;
        for(x = 65; x < 90; x++)    {
            if(str[i] == x) {
                str[i] = key[count];
                break;
            }
            count++;
        }
    }
    printf("The Decrypted code is: %s", str);
}


/******************************************************************************/


void DeSub(void)    {
    char str[100], key[100];
    int count = 0, i = 0;
        
    printf("Enter a message to be Decrypted: \n");
    scanf(" %[^\n]%*c",str);
    for(i = 0; i < strlen(str); i++)    {
        if(str[i] >= 97 && str[i] <=122)    {
            str[i] -= 32;
        }
    } 
    
    printf("Enter the substitution key: \n");
    scanf(" %[^\n]%*c",key);
    for(i = 0; i < strlen(key); i++)    {
        if(key[i] >= 97 && key[i] <=122)    {
            key[i] -= 32;
        }
    }
    
    for(i = 0; i < strlen(str); i++) {
        for(count = 0; count < strlen(key); count++) {
            if(str[i] == key[count])    {
                str[i] = 65 + count;
                break;
            }
        }
    }
    printf("The encrypted code is: %s", str);
}


/******************************************************************************/


void DeRot0Key(void)    {
    char str[100];
    int i = 0, count;
    printf("Enter a message to be decrypted: \n");
    scanf(" %[^\n]%*c",str);
    for(count = 0; count < 25; count++) {
        for(i = 0; i < strlen(str); i++) {
            str[i] += count;
        }
        printf("%s",str);
    }
}

void DeSub0Key(void)    {
    printf("hello 6");
}



























