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
#include <stdbool.h>
#include <ctype.h>

#define VERSION 0.1

// Constants for temperature conversion types
#define CELSIUS_TO_FAHRENHEIT 1
#define FAHRENHEIT_TO_CELSIUS 2
#define CELSIUS_TO_KELVIN 3
#define KELVIN_TO_CELSIUS 4
#define FAHRENHEIT_TO_KELVIN 5
#define KELVIN_TO_FAHRENHEIT 6

// Function prototypes
bool isNumeric(const char* str);
double convertTemperature(double value, int type);
void displayHelp();
void displayVersion();

int main(int argc, char **argv) {
    int option;
    double value;

    // Check if there are no command-line arguments
    if (argc == 1) {
        displayHelp();
        return 0;
    }

    // Define short and long options for command-line argument parsing
    static const char* const short_options = "c:f:k:hv";
    static struct option long_options[] = {
        {"celsius", required_argument, NULL, 'c'},
        {"fahrenheit", required_argument, NULL, 'f'},
        {"kelvin", required_argument, NULL, 'k'},
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'v'},
        {NULL, 0, NULL, 0}
    };

    // Parse command-line arguments
    while ((option = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
        switch (option) {
            case 'c':
            case 'f':
            case 'k':
                // Check if the argument is numeric
                if (!isNumeric(optarg)) {
                    fprintf(stderr, "Invalid value. Enter a valid number to convert.\n");
                    return 1;
                }

                // Convert the argument to a double
                value = atof(optarg);

                int fromType, toType;
                if (option == 'c') {
                    fromType = CELSIUS_TO_FAHRENHEIT;
                    toType = CELSIUS_TO_KELVIN;
                } else if (option == 'f') {
                    fromType = FAHRENHEIT_TO_CELSIUS;
                    toType = FAHRENHEIT_TO_KELVIN;
                } else {
                    fromType = KELVIN_TO_CELSIUS;
                    toType = KELVIN_TO_FAHRENHEIT;
                }

                // Convert the temperature and print the results
                double result1 = convertTemperature(value, fromType);
                double result2 = convertTemperature(value, toType);
                
                printf("%.2lf %s is equivalent to %.2lf %s and %.2lf %s\n",
                        value,
                        option == 'c' ? "Celsius" : (option == 'f' ? "Fahrenheit" : "Kelvin"),
                        result1,
                        option == 'c' ? "Fahrenheit" : (option == 'f' ? "Celsius" : "Fahrenheit"),
                        result2,
                        option == 'c' ? "Kelvin" : (option == 'f' ? "Kelvin" : "Celsius"));
                break;

            case 'h':
                // Display help message
                displayHelp();
                break;
            case 'v':
                // Display program version
                displayVersion();
                break;
            case '?':
                // Handle unrecognized options
                fprintf(stderr, "Use '-h, --help' for help.\n");
                return 1;
        }
    }

    // Check for unsupported options or arguments
    for (int i = optind; i < argc; i++) {
        if (argv[i][0] != '-') {
            fprintf(stderr, "Invalid option or argument '%s'. Use '-h, --help' for help.\n", argv[i]);
        }
    }

    return 0;
}

// Function to check if a string is numeric
bool isNumeric(const char* str) {
    for (int i = 0; str[i]; i++) {
        // Check if each character is a digit, a dot (for decimals), or a minus sign (for negative numbers)
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
            return false;
        }
    }
    return true;
}

// Function to convert temperature
double convertTemperature(double value, int type) {
    switch (type) {
        case CELSIUS_TO_FAHRENHEIT:
            return (value * 9 / 5) + 32;
        case CELSIUS_TO_KELVIN:
            return value + 273.15;
        case FAHRENHEIT_TO_CELSIUS:
            return (value - 32) * 5 / 9;
        case FAHRENHEIT_TO_KELVIN:
            return ((value - 32) * 5 / 9) + 273.15;
        case KELVIN_TO_CELSIUS:
            return value - 273.15;
        case KELVIN_TO_FAHRENHEIT:
            return ((value - 273.15) * 9 / 5) + 32;
        default:
            fprintf(stderr, "ERROR: Specify a valid type of conversion\n");
            return -1;
    }
}

// Function to display help
void displayHelp() {
    printf("Usage: temcon [OPTION] <value>\n");
    printf("Convert between temperature units.\n");
    printf("\nOptions:\n");
    printf("\t-c, --celsius VALUE       Convert Celsius to Fahrenheit and Kelvin\n");
    printf("\t-f, --fahrenheit VALUE    Convert Fahrenheit to Celsius and Kelvin\n");
    printf("\t-k, --kelvin VALUE        Convert Kelvin to Celsius and Fahrenheit\n");
    printf("\t-h, --help                Display this help message and exit.\n");
    printf("\t-v, --version             Display the program version and exit.\n");
}

// Function to display version
void displayVersion() {
    printf("temcon. version: %.1lf\n", VERSION);
}
