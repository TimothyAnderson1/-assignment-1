#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(void);                                                                    //Menu funcion     
void EnRot(void);                                                                   //Encription of rotaion cipher with key, function
void DeRot(void);                                                                   //Decription of rotaion cipher with key, function
void EnSub(void);                                                                   //Encription of substitution cipher with key, function 
void DeSub(void);                                                                   //Decription of substitution cipher with key, function
void DeRot0Key(void);                                                               //Decription of rotation cipher without key, function
void DeSub0Key(void);                                                               //Decription of substitution cipher without key, function


int main()
{
   menu();                                                                          //menu fucntion allows user to choose which program to run
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
    switch(choice)  {                                                               //switch case allows individual functions to be chosen
        case '1': EnRot(); break;   
        case '2': DeRot(); break;   
        case '3': EnSub(); break;
        case '4': DeSub(); break;
        case '5': DeRot0Key(); break;
        case '6': DeSub0Key();  break;
        default: printf("Unknown option %c\nPlease enter 1, 2, 3, 4, 5, or 6\n", choice);
        }
}



void EnRot(void)    {
    char str[1000];                                                                 //inroducing an input string(str) of up to 1000 characters long
    int key, i;                                                                     //introducing rotation key(key) and count variable(i)
    printf("Enter a message to be Encrypted: \n");                                  
    scanf(" %[^\n]%*c",str);                                                        //scaning input string with white spaces and assigning to str
    printf("Enter a key to totate the message:\n");
    scanf("%d", &key);                                                              //scaning rotation key
    
    while( key < 0 || key > 25)   {                                                 //if key is not between 26 and 0 key will need to be re entered
        printf("Please enter a key between 0 and 26:");
        scanf("%d", &key);
    }
    
        for(i = 0; i < strlen(str); i++)  {                                         //rotating through each character in message
            if((int)str[i] >= 97 && (int)str[i] <= 122) {                           //checking if character is lowercase letter
                if((int)str[i] - key < 97) {                                        // if letter with key is not in lowercase range
                    str[i] += 26;                                                   //brings key back to lowercase range
                }
                str[i] = str[i] - 32 - key;                                         //rotate letter and change to uppercase
            }
            else if((int)str[i] >= 65 && (int)str[i] <= 90) {                       //checking if character is upprecase letter
                if((int)str[i] - key < 65)  {                                       //checking that the letter with key is still in uppercase range
                    str[i] += 26;                                                   //if not brings letter to uppercase range
                }
                str[i] = str[i] - key;                                              //rotates letter
            }
        }
        
    printf("Encrypted message: %s\n", str);                                         //prints encrypted message
}


/******************************************************************************/


void DeRot(void)    {
    char str[1000];                                                                  //introducing an input string(str) of up to 1000 characters
    int key, i;                                                                     //introducing rotation key(key) and counter(i) variables
    printf("Enter a message to be Decrypted: \n");
    scanf(" %[^\n]%*c",str);                                                        //scaning input string with white spaces and assigning to str
    printf("Enter the key to reverse the rotation of the message:\n");
    scanf("%d", &key);                                                              //scaning rotation key
    
    while( key < 0 || key > 25)   {                                                 //checking if key is not inside range 25-0
        printf("Please enter a key between 0 and 26:");                             //if so key must be re entered
        scanf("%d", &key);
    }
    
        for(i = 0; i < strlen(str); i++)  {                                         //rotating through each letter in message
            if((int)str[i] >= 97 && (int)str[i] <= 122) {                           //cheacking if character is a lowercase letter
                if((int)str[i] + key >122) {                                        //if letter with key is not in lowercase range, adjust by 26
                    str[i] -= 26;
                }
                str[i] = str[i] - 32 + key;                                         //rotate letter and change to uppercase
            }
            else if((int)str[i] >= 65 && (int)str[i] <= 90) {                       //checking if character is a uppercase letter  
                if((int)str[i] + key > 90)  {                                       // if letter with key is not in upperaes range, adjust by 26
                    str[i] -= 26;
                }
                str[i] = str[i] + key;                                              //rotate letter
            }
        }
        
    printf("Decrypted code: %s", str);                                              //print decrypted string
    
}


/******************************************************************************/


void EnSub(void)    {
    char str[1000], key[100];                                                       //introducing an input string(str) and a string key(key)
    int count = 0, i = 0, x= 65;                                                    //introducing three counter variables(count, i, and x)
    
    printf("Enter a message to be encrypted: \n");
    scanf(" %[^\n]%*c",str);                                                        //scaning input string with white spaces and assigning to str
    for(i = 0; i < strlen(str); i++)    {                                           //rotaing though each character
        if(str[i] >= 97 && str[i] <=122)    {                                       //if caharcter is a lowercase letter, adjust to uppercase
            str[i] -= 32;
        }
    } 
    
    printf("Enter the substitution key: \n");
    scanf(" %[^\n]%*c",key);                                                        //scaning ipunt key with whitespoace and assiging to key
    for(i = 0; i < strlen(key); i++)    {                                           //rotaing thorugh key charcters
        if(key[i] >= 97 && key[i] <=122)    {                                       //if character is a lowercase letter, adjust to uppercase
            key[i] -= 32;
        }
    }
    
    for(i = 0; i < strlen(str); i++)    {                                           //rotaing through input string characters
        count = 0;                                          
        for(x = 65; x < 90; x++)    {                                               //checing through every uppercase letter, each time adding 1 to n
            if(str[i] == x) {                                                       //if charcter is equal to letter change charcter to nth key letter
                str[i] = key[count];                                                
                break;                                                              //break loop to start next input character rotation
            }
            count++;                                                                //repeat for next input character
        }
    }
    printf("The Encrypted code is: %s\n", str);                                     //print encrypted string(str)
}


/******************************************************************************/


void DeSub(void)    {
    char str[1000], key[100];                                                       //introducing an input string(str) and a string key(key)
    int count = 0, i = 0;                                                           //intoducing two counter variables(count and i)
    printf("Enter a message to be Decrypted: \n");
    scanf(" %[^\n]%*c",str);                                                        //scaning input string with white spaces and assigning to str
    for(i = 0; i < strlen(str); i++)    {                                           //rotaing through each character in the string
        if(str[i] >= 97 && str[i] <=122)    {                                       //if character is a lowercase letter, adjust to uppercase
            str[i] -= 32;
        }
    } 
    
    printf("Enter the substitution key: \n");           
    scanf(" %[^\n]%*c",key);                                                        //scaning ipunt key with whitespoace and assiging to key
    for(i = 0; i < strlen(key); i++)    {                                           //rotaing through each key character
        if(key[i] >= 97 && key[i] <=122)    {                                       //if character is a lowercase letter, adjust to uppercase
            key[i] -= 32;
        }
    }
    
    for(i = 0; i < strlen(str); i++) {                                              //rotaing through input string characters
        for(count = 0; count < strlen(key); count++) {                              //incrementng a counter variable(count) to rotate through key characters
            if(str[i] == key[count])    {                                           //if the input character is equal to the key character, adgust the input by 65 + counter
                str[i] = 65 + count;
                break;                                                              //break loop to start next input character rotation
            }
        }
    }
    printf("The Decrypted code is: %s", str);                                       //print decrypted string(str)
}


/******************************************************************************/


/***************************!!!NOT FINISHED!!!*********************************/
void DeRot0Key(void)    {
   char str[100];
   char strWord[10][10];
  
    printf("Enter a message to be decrypted: \n");
    scanf(" %[^\n]%*c",str);
    int k,j,ctr; 
    j=0; 
    ctr=0;
    for(k=0;k<=(strlen(str));k++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(str[k]==' '||str[k]=='\0')
        {
            strWord[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            strWord[ctr][j]=str[k];
            j++;
        }
    }
    printf("%s\n",strWord[0]);
    printf("%s\n",strWord[1]);
    
   
    
    
    FILE *input;
    input = fopen("input.txt", "r");
    char word[100];
    char indvWord[10][10];
    fscanf(input," %[^\n]%*c",word);
    int k1,j1,ctr1; 
    j1=0; 
    ctr1=0;
    for(k1=0;k1<=(strlen(word));k1++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(word[k1]==' '||word[k1]=='\0')
        {
            indvWord[ctr1][j1]='\0';
            ctr1++;  //for next word
            j1=0;    //for next word, init index to 0
        }
        else
        {
            indvWord[ctr1][j]=word[k1];
            j++;
        }
    }
    printf("%s\n",indvWord[0]);
    printf("%s\n",indvWord[2]);
    
    /*for(count = 0; count < 25; count++)  {

        for(i = 0; i < strlen(str); i++)  {
            if(str[i] >= 65 && str[i] <= 90)    {
                if(str[i] + 1 > 90) {
                    str[i] = str[i] - 26;
                }
                str[i] = str[i] + 1;
            }
        }
        printf("%s\n", str);
    }
    */
    
    
}


/******************************************************************************/


void DeSub0Key(void)    {

/*************************NOT STARTED******************************************/
   
}


