# Cat Utility in C

This project is an implementation of the `cat` utility in C, based on the C11 standard and compiled with gcc, following the POSIX.1-2017 standard. The `cat` utility is used to display, combine, and create text files. This implementation supports all flags specified in the project requirements, including the GNU versions.

## Build

To build the `cat` utility, you can use the Makefile provided in the `build/` directory. The Makefile includes the following targets:

- `all`: Builds the program.
- `build`: Installs the program.
- `rebuild`: Cleans the build directory and installs the program.
- `install`: Creates the build directory and compiles the program in it.
- `uninstall`: Removes the build directory.
- `clean`: Removes the build directory and all object files.

To build the program, run:

```
make all
```

This will create an executable file named `CatenateUtility` in the `build/` directory.

## Usage

The `cat` utility takes one or more file names as arguments. It reads each file in sequence and writes its contents to the standard output. If no files are specified, it reads from the standard input.

The following flags are supported:

- `-b` (`--number-nonblank`): Numbers only non-empty lines.
- `-e` (implies `-v`, GNU only: `-E` the same, but without implying `-v`): Displays end-of-line characters as `$`.
- `-n` (`--number`): Numbers all output lines.
- `-s` (`--squeeze-blank`): Squeezes multiple adjacent blank lines.
- `-t` (implies `-v`, GNU: `-T` the same, but without implying `-v`): Displays tabs as `^I`.

For example, to display the contents of a file named `example.txt` and number all output lines, run:

```
./CatenateUtility -n example.txt
```

To display the contents of multiple files and display end-of-line characters as `$`, run:

```
./CatenateUtility -e file1.txt file2.txt file3.txt
```

## Dependencies

This implementation does not use any third-party libraries. It only uses the standard C libraries and follows the POSIX.1-2017 standard.

## Development

The source code, header files, and build files are located in the `model/` directory. The code follows the principles of structured programming and avoids code duplication.

Integration tests cover all flag variants and input values, based on a comparison with the behavior of real Bash utilities.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more information.