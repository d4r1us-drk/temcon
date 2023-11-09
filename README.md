# temcon - Temperature Converter Tool

## Table of Contents

- [Introduction](#introduction)
- [Building](#building)
- [Usage](#usage)
- [Options](#options)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction
`temcon` is a simple command-line utility that allows you to convert temperatures between Celsius, Fahrenheit, and Kelvin.

## Building

This tool is provided as source code and can be built using `make`. Here
are the build instructions:

1. Clone the repository:

   ```bash
   git clone https://github.com/d4r1us-drk/temcon.git
   ```

2. Change the directory to the cloned repository:

   ```bash
   cd temcon
   ```

3. Build the tool using `make`:

   ```bash
   make
   ```

You should now have an executable named `temcon`. You can copy it to a
location in your PATH for easy access.

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

## Examples
1. To convert 25 degrees Celsius to Fahrenheit and Kelvin:
  ```bash
  temcon -c 25
  ```

2. To convert 68 degrees Fahrenheit to Celsius and Kelvin:
  ```bash
  temcon -f 68
  ```

3. To convert 298 Kelvin to Celsius and Fahrenheit:
  ```bash
  temcon -k 298
  ```
## Contributing

If you would like to contribute to Passgen, please create a pull request on the
GitHub repository.

## License

This project is licensed under the GPLv3 License - see the [LICENSE](LICENSE)
file for details.
