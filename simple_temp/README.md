
# Simple Shell project -shellix-


Simple Shell is a project for students at ALX. This endeavor serves as an extensive evaluation of our proficiency in the C programming language, our aptitude for teamwork, and our ability to strategize for a long-term project.




## Overview

The Simple Shell is a basic C program that functions as a UNIX command interpreter. It operates by executing bash commands entered by the user through the input stream, mimicking the behavior of a typical UNIX shell.
## Getting Started

Usage: `Shellix`  is initiated with the standard input linked to the terminal. To begin, compile all the .c files present in this repository using the following command:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o shellix
./shellix
```

## Usage
`shellix` is allowed to be invoked interactively and non-interactively. If `shellix` is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'Hello'" | ./shellix
'Hello'
$
```
When sodash is invoked with standard input connected to a terminal (determined by isatty(3), the interactive mode is opened. sodash Will be using the following prompt ^-^ .

Example:
```
$./shellix
:D
```
If a command line argument is provided, Shellix will consider the first argument as a file from which it will read commands.

Example:
```
$ cat text.txt
echo 'Hello'
$ ./shellix text.txt
'Hello'
$
```
## Built-ins
The simple shell has support for the following built-in commands:
| Command | Definition |
| -------- | -------- |
| env | Prints the environment |
| exit | Exits the shell |

## Authors

- **[Adnane-Bahili](https://github.com/Adnane-Bahili)**
- **[Younes-sakhnou](https://github.com/Younes-sakhnou)**
