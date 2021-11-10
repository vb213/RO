/**
 * Karlsruher Institut fuer Technologie
 * Institut fuer Technische Informatik (ITEC) 
 * Vorlesung Rechnerorganisation
 *
 * Autor: Valentin Barner   
 * Matrikelnummer: 2360523
 * Tutoriumsnummer: 14
 * Name des Tutors: Jonas Heinle
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int alphabetSize = 26;


/**
 * Returns the length of the given text.
 * \param text
 * \return the length of text
 */
static unsigned int stringLength(char* text)
{
    size_t length = 0;
    while(*text != '\0') {
        length++;
        text++;
    }

    return length;
}


/**
 * create a buffer which is as big as text
 *
 * \param text
 * \return char* buffer
 */
static char* createBuffer(char* text)
{
    // allocate the buffer memory
    // + 1 for the trailing \0
    int bufferSize = stringLength(text) + 1;
    // allocate and set the buffer to 0
    char* buffer = (char*)calloc(bufferSize, sizeof(char));

    return buffer;
}


/**
 * if c is a letter it will be rotated by n
 * \param c the character
 * \param n the rotate offset
 * \return the rotated character
 */
static char rotateChar(char c, int n)
{
    char alphabetStart;

    if(c >= 'a' && c <= 'z'){ 
        // if c is a lowercase, the alphabet starts at 'a'
        alphabetStart = 'a';
    } else if (c >= 'A' && c <= 'Z') {
        // if c is a capital letter, the alphabet starts at 'A'
        alphabetStart = 'A';
    } else {
        //c is not a letter
        return c;
    }

    char result =  alphabetStart + (c - alphabetStart + n) % alphabetSize;

    return result;


}


/**
 * Returns the crypted string of text.
 *
 * encrypt("Valentin Barner", 2360523) returns "Ejunwcrw Kjawna"
 *
 * \param text to encrypt.
 * \param key
 * \return crypted text
 */
static char* encrypt(char* text, int key)
{
    char* result = createBuffer(text);
    int i = 0;
    while(*text != '\0') {
        *(result + i) = rotateChar(*text, key);
        text++;
        i++;
    }
    return result;
}


/**
 * Returns the decrypted string of crypted.
 *
 * \param crypted
 * \param key
 * \return crypted text
 */
static char* decrypt(char* crypted, int key)
{
    encrypt(crypted, alphabetSize - (key % alphabetSize));
}


#ifndef TEST
/**
 * main method
 * Queries the number to use as input parameter for the function calls
 *
 * \param argc unused
 * \param argv unused
 * \return returns 0
 */
int main(int argc, char* argv[])
{

    char plain[256];
    int key;

    printf("Bitte geben Sie einen Text ein:\n> ");
    // for visual studio 
    // scanf_s("%255[^\n]", plain, _countof(plain));
    scanf("%255[^\n]", plain);

    printf("Bitte geben Sie einen Schluessel ein:\n> ");
    // for visual studio
    // scanf_s("%i", &key);
    scanf("%i", &key);

    char* crypted = encrypt(plain, key);
    printf("crypted:   %s\n", crypted);
    char* decrypted = decrypt(crypted, key);
    printf("decrypted: %s\n", decrypted);

    free(crypted);
    free(decrypted);
    return 0;
    
}
#endif
