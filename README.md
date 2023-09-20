# Simple Shell

The project is a simple UNIX command interpreter written as part of the low-level programming and algorithm track at Alx. The shell works like the sh shell. The functions it handles includes but are not limited to:

* Environment variables handling
* Commands written with their absolute paths
* Commands execution with arguments

This project was done by EWEDAIRO ISRAEL AYOMIDE and IWELUMO JUDE, under the supervision of JULIEN BARBIER at Alx.

## Requirements

* All files will be compiled on Ubuntu 16.04 LTS.
* Programs and functions will be compiled with gcc using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All files should end with a new line
* A README.md file, at the root of the folder of the project, is mandatory
* Code uses the Betty linter style

## How to Compile

The code can easily be compiled with gcc in your terminal by GNU Vim.

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

Our simple shell works like the sh shell and operates in both interactive and non-interactive modes. here are some usage examples.

**Interactive Mode**

In interactive mode, you simply run the program and it will display a prompt where you can enter your commands, similar to sh.
```bash
$ ./hsh
$ mkdir my_new_directory
$ ls -l
$ cd my_new_directory
$ env
$ exit
```
**Non-Interactive Mode**

Non-interactive mode is when you want to send commands to the program via a pipe, a file, or from a bash script, for example.
Create a new directory:
```bash
$ echo "mkdir my_new_directory" | ./hsh
$ echo "ls -l" | ./hsh
$ echo "cd my_new_directory" | ./hsh
$ echo "env" | ./hsh
$ echo "exit" | ./hsh
```

```bash
$ mkdir my_new_directory
```
List directory contents:

```bash
$ ls -l
```
Change current directory to a new one:

```bash
$ cd my_new_directory
```
Print environment variables:

```bash
$ env
```
Exit shell:

```bash
$ exit
```

## Acknowledgments

* Thanks to Alx for providing the platform to learn and implement the functions for this shell.

## Contributing

This project is a work in progress and while it will probably fulfill basic needs, extra features may be desired. Please feel free to contribute those enhancements, or any bug fixes. If you'd like to contribute, please follow the typical Git workflow:

1. Fork this repository
2. Create your feature branch
3. Commit your changes
4. Push to your feature branch
5. Create a new Pull Request


## License

This project is licensed under the MIT License:

```
MIT License

Copyright (c) [2023] [EWEDAIRO ISRAEL AYOMIDE AND IWELUWO JUDE]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
