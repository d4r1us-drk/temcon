# temcon - Temperature Converter Tool

## Introduction
`temcon` is a simple command-line utility that allows you to convert temperatures between Celsius, Fahrenheit, and Kelvin.

## Usage
```
temcon [OPTION] <value>
```

## Options
- `-c, --celsius VALUE`       Convert Celsius to Fahrenheit and Kelvin.
- `-f, --fahrenheit VALUE`    Convert Fahrenheit to Celsius and Kelvin.
- `-k, --kelvin VALUE`        Convert Kelvin to Celsius and Fahrenheit.
- `-h, --help`                Display this help message and exit.
- `-v, --version`             Display the program version and exit.

## Example Usage
- To convert 25 degrees Celsius to Fahrenheit and Kelvin:
  ```
  temcon -c 25
  ```

- To convert 68 degrees Fahrenheit to Celsius and Kelvin:
  ```
  temcon -f 68
  ```

- To convert 298 Kelvin to Celsius and Fahrenheit:
  ```
  temcon -k 298
  ```

## License
This project is licensed under the GPLv3 License - see the [LICENSE](LICENSE)
file for details.

## Version
`temcon` version: 0.1

## Author
- Darius Drake

Please refer to the GNU General Public License for more details regarding the terms and conditions of using this software.
