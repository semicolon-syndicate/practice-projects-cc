#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define NUM_OF_CONVERTERS 6


void showConverters(void)
{
    printf("\nAvailable converters:\n");
    printf("1)\t °C to °F\n");
    printf("2)\t °F to °C\n");
    printf("3)\t °C to K\n");
    printf("4)\t K to °C\n");
    printf("5)\t °F to K\n");
    printf("6)\t K to °F\n");
}


float celsiusFahrenheitConverter(float temperature)
{
    return (temperature * 9.0 / 5.0) + 32.0;
}


float fahrenheitCelsiusConverter(float temperature)
{
    return (temperature - 32.0) * 5.0 / 9.0;
}


float celsiusKelvinsConverter(float temperature)
{
    return temperature + 273.15;
}


float kelvinsCelsiusConverter(float temperature)
{
    return temperature - 273.15;
}


float fahrenheitKelvinsConverter(float temperature)
{
    return fahrenheitCelsiusConverter(temperature) + 273.15;
}


float kelvinsFahrenheitConverter(float temperature)
{
    return celsiusFahrenheitConverter(temperature - 273.15);
}


int userSelectConverter(void)
{
    int userChoice;
    int c;
    
    showConverters();
    
    while (1)
    {
        printf("\nPlease select a converter. (1, 2, 3, 4, 5, or 6)\n> ");
        
        int result = scanf("%d", &userChoice);
        
        if (result == EOF)
        {
            return 0;
        }
        
        while ((c = getchar()) != '\n' && c != EOF);
        
        if (result != 1)
        {
            printf("\nInvalid input. Try again.\n");
            continue;
        }
        
        if (userChoice < 1 || userChoice > NUM_OF_CONVERTERS)
        {
            printf("\nPlease enter a number between 1 and %d.\n", NUM_OF_CONVERTERS);
            continue;
        }
        
        return userChoice;
    }
}


bool belowAbsoluteZero(float temperature, int converter)
// check if temperature is below absolute zero
// return true or false
{
    switch (converter)
    {
        case 1:
        case 3:
        {
            return celsiusKelvinsConverter(temperature) < 0;
        }
        case 2:
        case 5:
        {
            return fahrenheitKelvinsConverter(temperature) < 0;
        }
        case 4:
        case 6:
        {
            return temperature < 0;
        }
        default:
        {
            return false;
        }
    }
}


float enterTemp(int converter)
{
    float temp;
    int c;
    
    while (1)
    {
        printf("\nEnter the temperature value for conversion (up to 2 dp):\n>>> ");
        
        int result = scanf("%f", &temp);
        
        if (result == EOF)
        {
            return 0.0f;
        }
        
        while ((c = getchar()) != '\n' && c != EOF);
        
        if (result != 1)
        {
            printf("\nInvalid input.\n");
            continue;
        }
        
        if (belowAbsoluteZero(temp, converter))
        {
            printf("\nThe temperature you entered is below absolute zero. Please enter another value.\n");
            continue;
        }
        
        return temp;
    }
}


void runConverter(void)
{
    char header[] = "TEMPERATURE CONVERTER";
    printf("%s!\n\n", header);
    
    int converter = userSelectConverter();
    
    if (converter == 0) return;
    
    switch (converter) {
        case 1:
        {
            printf("\n°C to °F converter\n\n");
            float temp = enterTemp(converter);
            printf("\n > %.2f °C is equivalent to %.2f °F\n\n", temp, celsiusFahrenheitConverter(temp));
            break;
        }
        case 2:
        {
            printf("\n°F to °C converter\n\n");
            float temp = enterTemp(converter);
            printf("\n > %.2f °F is equivalent to %.2f °C\n\n", temp, fahrenheitCelsiusConverter(temp));
            break;
        }
        case 3:
        {
            printf("\n°C to K converter\n\n");
            float temp = enterTemp(converter);
            printf("\n > %.2f °C is equivalent to %.2f K\n\n", temp, celsiusKelvinsConverter(temp));
            break;
        }
        case 4:
        {
            printf("\nK to °C converter\n\n");
            float temp = enterTemp(converter);
            printf("\n > %.2f K is equivalent to %.2f °C\n\n", temp, kelvinsCelsiusConverter(temp));
            break;
        }
        case 5:
        {
            printf("\n°F to K converter\n\n");
            float temp = enterTemp(converter);
            printf("\n > %.2f °F is equivalent to %.2f K\n\n", temp, fahrenheitKelvinsConverter(temp));
            break;
        }
        case 6:
        {
            printf("\nK to °F converter\n\n");
            float temp = enterTemp(converter);
            printf("\n > %.2f K is equivalent to %.2f °F\n\n", temp, kelvinsFahrenheitConverter(temp));
            break;
        }
        default:
            printf("\nThis converter doesn't exist.\n\n");
    }
}


bool closeConverter(void)
{
    int choice;
    
    while (1)
    {
        printf("\nClose the converter? (y/n)\n > ");
        choice = getchar();
        
        if (choice == EOF)
        {
            return true;
        }
        
        if (choice != '\n')
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
        
        choice = tolower(choice);
        
        if (choice == 'y' || choice == 'n')
        {
            return choice == 'y';
        }
        
        printf("\nInvalid input. Please enter 'y' or 'n'.\n");
    }
}


int main(void)
{
    while (1)
    {
        runConverter();
        
        if (closeConverter()) break;
    }
    printf("\nThanks for using this converter.\n");
    
    return 0;
}
