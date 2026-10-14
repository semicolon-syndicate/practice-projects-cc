 #include <stdio.h>


void showConverters()
{
    printf("\nAvailable converters:\n");
    printf("1)\t °C to °F\n");
    printf("2)\t °F to °C\n");
    printf("3)\t °C to K\n");
    printf("4)\t K to °C\n");
    printf("5)\t °F to K\n");
    printf("6)\t K to °F\n");
}


int userSelectConverter()
{
    int userChoice;
    
    showConverters();
    
    while (1)
    {
        printf("\nPlease select a converter. (1, 2, 3, 4, 5, or 6)\n> ");
        
        if (scanf(" %d", &userChoice) != 1)
        {
            while (getchar() != '\n');
            userChoice = 0;
        }
        
        if (userChoice >= 1 && userChoice <= 6)
        {
            while (getchar() != '\n');
            return userChoice;
        }
        else
        {
            printf("\nInvalid choice. Please enter a number between 1 and 6.\n");
        }
    }
}


float enterTemp()
{
    float temp;
    
    while (1)
    {
        printf("\nEnter the temperature value for conversion (up to 2 dp):\n>>> ");
        if (scanf(" %f", &temp) == 1)
        {
            while (getchar() != '\n');
            return temp;
        }
        
        while (getchar() != '\n');
        printf("\nInvalid input.\n");
    }
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


int main()
{
    char header[] = "TEMPERATURE CONVERTER";
    printf("%s!\n\n", header);
    
    int converter = userSelectConverter();
    
    switch (converter) {
        case 1:
        {
            printf("\n°C to °F converter\n\n");
            float temp = enterTemp();
            printf(" > %.2f °C is equivalent to %.2f °F\n\n", temp, celsiusFahrenheitConverter(temp));
            break;
        }
        case 2:
        {
            printf("\n°F to °C converter\n\n");
            float temp = enterTemp();
            printf(" > %.2f °F is equivalent to %.2f °C\n\n", temp, fahrenheitCelsiusConverter(temp));
            break;
        }
        case 3:
        {
            printf("\n°C to K converter\n\n");
            float temp = enterTemp();
            printf(" > %.2f °C is equivalent to %.2f K\n\n", temp, celsiusKelvinsConverter(temp));
            break;
        }
        case 4:
        {
            printf("\nK to °C converter\n\n");
            float temp = enterTemp();
            printf(" > %.2f K is equivalent to %.2f °C\n\n", temp, kelvinsCelsiusConverter(temp));
            break;
        }
        case 5:
        {
            printf("\n°F to K converter\n\n");
            float temp = enterTemp();
            printf(" > %.2f °F is equivalent to %.2f K\n\n", temp, fahrenheitKelvinsConverter(temp));
            break;
        }
        case 6:
        {
            printf("\nK to °F converter\n\n");
            float temp = enterTemp();
            printf(" > %.2f K is equivalent to %.2f °F\n\n", temp, kelvinsFahrenheitConverter(temp));
            break;
        }
        default:
            printf("\nThis converter doesn't exist.\n\n");
    }
    
    return 0;
}
