# Libft Tester

This repo provides test scripts for your **Libft** (first project at 42 School). These tests were designed by students (cf. [Credits](#Credits)).

## Installation

First things first, clone this repo alongside the **Libft**'s directory.

```shell
git clone https://github.com/valfur03/libft_tester
```

The file tree should look like this.

```
.
+--	libft
	+--	libft.a
	+--	libft.h
+--	libft_tester
```

However, you can change the **Libft**'s path in the `Makefile`.

> The **Libft** has to be first compiled before using the tester.

> Note that the tester doesn't check the norm. The purpose of this repo is to be more effective in evaluation, not to botch it up.

## Usage

Once the installation is done, `cd` into the tester's directory, and run the `./run.sh` script. You will be able to see which function passed or failed. 

The logs are stored in the `logs` directory. For example, if you want to see the logs for the `atoi` function, you will find them in the `logs/atoi.log` file.

> A `.libft.h` file is available under `test/includes`. You should not use it in evaluation, but it is here in case of... Just copy it under the name of `libft.h` in the same directory.

### Linux

Even though this tester was made for MacOS, you can use it on Linux.

In the **Makefile**, change the line :

```make
LIB = 
```

to :

```make
LIB = -lbsd
```

> You need to have the package **libbsd-dev** installed. If not, run `sudo apt install libbsd-dev`

#### Functions compatibility

Some functions doesn't work the same on Linux and MacOS. Here is a list of test that can return you KO when you should have OK.

- ft_isalnum_basic
- ft_isalpha_basic
- ft_isdigit_basic
- ft_isprint_basic
- ft_tolower_negative
- ft_toupper_negative

> And maybe more...

### Arguments

#### -b | --bonus

This arguments runs the bonus tests too.

```shell
./run.sh -b
```

#### -c | --check-files

If you want to check that the file exists in the **Libft**'s directory, you can use either the `-c` or the `-check-files` argument. This way, if you misspelled the name of a file (`ft_atio.c` instead of `ft_atoi.c`), you will get a warning.

```shell
./run.sh -c
```

#### --no-compile

Do not compile the **Libft**.

```shell
./run.sh --no-compile
```

#### --no-logs

By default, the script displays the logs in case of the test failed. You can disable that with the `--no-logs` argument.

```shell
./run.sh --no-logs
```

#### -h | --help

Not sure I need to describe this one.

> It prints a help message.

#### Functions name

At the end of all the arguments, you can specify functions name. This way, only these functions will be tested and compiled.

```shell
./run.sh [arguments...] atoi memcpy
```

## Troubleshooting

### Error when compiling the tests.

You can see this error message for several reasons:

- Your **Libft**'s path in the **Makefile** is wrong.
- There are missing functions in your **Libft**. Try specifying [functions name](#Functions name).
- The **libft.h** file isn't in the **Libft**'s directory.

To see what is wrong, try running `make`.

### I have another problem

If you encounter another problem, please feel free to open an Issue using the **GitHub**'s tab.

## Credits

- [vbotte](https://github.com/VincentBotte)
- [echin](https://github.com/Elxse)
- [vfurmane](https://github.com/valfur03)