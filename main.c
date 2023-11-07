/* 
 * main.c
 *
 * Copyright 2023 Darius Drake
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void clearScreen() {
    printf("\e[1;1H\e[2J");
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double fahrenheitToKelvin(double fahrenheit) {
    return ((fahrenheit - 32) * 5 / 9) + 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return ((kelvin - 273.15) * 9 / 5) + 32;
}

void displayHelp() {
    printf("Usage: temperature-converter [OPTION]...\n");
    printf("Convert between temperature units.\n");
    printf("\nOptions:\n");
    printf("  -c VALUE    Convert Celsius to Fahrenheit and Kelvin\n");
    printf("  -f VALUE    Convert Fahrenheit to Celsius and Kelvin\n");
    printf("  -k VALUE    Convert Kelvin to Celsius and Fahrenheit\n");
    printf("  -h          Display this help message and exit.\n");
}

int main(int argc, char** argv) {

    if (argc == 1) {
        displayHelp();
        exit(0);
    }

    int option;
    double value;

    while ((option = getopt(argc, argv, "c:f:k:h")) != -1) {
        switch (option) {
            case 'c':
                value = atof(optarg);
                printf("%.2lf Celsius is equivalent to %.2lf Fahrenheit and %.2lf Kelvin\n",
                       value, celsiusToFahrenheit(value), celsiusToKelvin(value));
                break;
            case 'f':
                value = atof(optarg);
                printf("%.2lf Fahrenheit is equivalent to %.2lf Celsius and %.2lf Kelvin\n",
                       value, fahrenheitToCelsius(value), fahrenheitToKelvin(value));
                break;
            case 'k':
                value = atof(optarg);
                printf("%.2lf Kelvin is equivalent to %.2lf Celsius and %.2lf Fahrenheit\n",
                       value, kelvinToCelsius(value), kelvinToFahrenheit(value));
                break;
            case 'h':
                displayHelp();
                break;
            default:
                fprintf(stderr, "Invalid option. Use '-h' for help.\n");
                return 1;
        }
    }

    return 0;
}
