# Quadratic equations solver

Solves quadratic equations `ax^2 + bx + с = 0` and prints roots of a equation and their number.

## Setup

### For Windows

1. Run `git clone https://github.com/Krasnolutskaia/quadratisch-praktisch-gut.git --depth 1`
2. Go into the cloned folder with `cd quadratisch-praktisch-gut`
3. Run `.\compile.bat`
4. Run `.\quadro.exe`

## Usage

After running `.\quadro.exe` enter quadratic equation coefficients one by one and get your answer.
For help run `.\quadro.exe --help`

## Tests

### Auto-test mode

Run `.\quadro.exe --auto-test` to start built-in tests. The program will print number of successful tests. If received information and reference data don't match, test data will be printed.

### Tests from file

Run `.\quadro.exe --test [file_name]` to start tests from your file. The program will print number of successful tests. If received information and reference data don't match, test data will be printed.

### How to make file for tests 

1. Write a number of tests on the first line
2. Use one string for one test, following this template:
   `[coeff a] [coeff b] [coeff c] [x1] [x2] [number of roots]`
   If the equation has no roots, write `0` instead of [number of roots]. If the equation has infinite number of roots, write `3` instead of [number of roots] and `0 0` instead of [x1] [x2].
   If the equation has one root, write same values instead of [x1] and [x2].
