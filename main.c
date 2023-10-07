#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

void clearScreen()
{
    printf("\e[1;1H\e[2J");
}

void waitForKeypress()
{
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    while (getchar() != '\n'); // Consume any remaining characters in the input buffer
    getchar(); // Wait for a key press
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

double celsiusToFahrenheit(double celsius)
{
    return (celsius * 9 / 5) + 32;
}

double fahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

double celsiusToKelvin(double celsius)
{
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin)
{
    return kelvin - 273.15;
}

double fahrenheitToKelvin(double fahrenheit)
{
    return ((fahrenheit - 32) * 5 / 9) + 273.15;
}

double kelvinToFahrenheit(double kelvin)
{
    return ((kelvin - 273.15) * 9 / 5) + 32;
}

void showMenu()
{
    printf("Select the type of conversion you want to perform:\n");
    printf("\t1. Celsius to Fahrenheit\n");
    printf("\t2. Fahrenheit to Celsius\n");
    printf("\t3. Celsius to Kelvin\n");
    printf("\t4. Kelvin to Celsius\n");
    printf("\t5. Fahrenheit to Kelvin\n");
    printf("\t6. Kelvin to Fahrenheit\n");
    printf("\t7. Exit\n");
}

int getInputOption()
{
    int option;
    printf("Choose [1, 2, 3, 4, 5, 6, 7]: ");
    scanf("%d", &option);
    return option;
}

double getInputTemperature()
{
    double temperature;
    printf("Enter the temperature: ");
    scanf("%lf", &temperature);
    return temperature;
}

void processConversion(int option, double input)
{
    double result;
    switch (option)
    {
        case 1:
            result = celsiusToFahrenheit(input);
            printf("%.2lf Celsius is equivalent to %.2lf Fahrenheit\n", input, result);
            break;
        case 2:
            result = fahrenheitToCelsius(input);
            printf("%.2lf Fahrenheit is equivalent to %.2lf Celsius\n", input, result);
            break;
        case 3:
            result = celsiusToKelvin(input);
            printf("%.2lf Celsius is equivalent to %.2lf Kelvin\n", input, result);
            break;
        case 4:
            result = kelvinToCelsius(input);
            printf("%.2lf Kelvin is equivalent to %.2lf Celsius\n", input, result);
            break;
        case 5:
            result = fahrenheitToKelvin(input);
            printf("%.2lf Fahrenheit is equivalent to %.2lf Kelvin\n", input, result);
            break;
        case 6:
            result = kelvinToFahrenheit(input);
            printf("%.2lf Kelvin is equivalent to %.2lf Fahrenheit\n", input, result);
            break;
        default:
            printf("Invalid option\n");
            return;
    }
}

int main(void)
{
    while (1)
    {
        clearScreen();
        showMenu();
        int option = getInputOption();
        if (option == 7)
        {
            printf("Exiting...\n");
            break;
        }
        if (option >= 1 && option <= 6)
        {
            double input = getInputTemperature();
            processConversion(option, input);
            printf("Press any key to continue... ");
            waitForKeypress();
        }
        else
        {
            printf("Invalid option. Select an option between 1 and 7.\n");
        }
    }
    return 0;
}
