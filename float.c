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
#include <stdint.h>

/**
 * Extract the sign from the floating point number (given as an uint32_t).
 *
 * \param number Number to operate on (in IEEE 754 single precision format).
 * \return Value of the sign bit (0 if the sign is positive, 1 otherwise).
 */
static int fpsign(uint32_t number)
{
    uint32_t mask = 1 << 31;

    int result = (number & mask) >> 31;

    return result;
}

/**
 * Extract the mantissa from the floating point number (given as an uint32_t).
 *
 * \param number Number to operate on (in IEEE 754 single precision format).
 * \return Value of the mantisse.
 */
static int fpmantissa(uint32_t number)
{
    uint32_t mask = 0x007fffff;
    int mantissa = number & mask;
    return mantissa;
}

/**
 * Extract the exponent from the floating point number (given as an uint32_t).
 *
 * \param number Number to operate on (in IEEE 754 single precision format).
 * \return Value of the exponent.
 */
static int fpexponent(uint32_t number)
{
    const int bias = 127;
    uint32_t mask = 11111111;

    int characteristic = (number >> 23) & mask;
    return characteristic - bias;
    
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
    float number = 0;
    uint32_t numberuint = 0;
    
    printf("Bitte geben Sie eine Gleitkommazahl ein:\n> ");
    // for visual studio
    // scanf_s("%f", &number);
    scanf("%f", &number);
    
    numberuint = *((uint32_t*)&number);
    
    printf("Vorzeichen: %d\n", fpsign(numberuint));
    printf("Mantisse:   %d\n", fpmantissa(numberuint));
    printf("Exponent:   %d\n", fpexponent(numberuint));

    
    
    return 0;
}
#endif
