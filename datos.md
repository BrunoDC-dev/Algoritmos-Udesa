# Informacion Util de C 

Reserved Key Words:

| _Bool    | break    | char      | const     |
|----------|----------|-----------|-----------|
| continue | default  | do        | double    |
| else     | enum     | extern    | float     |
| for      | goto     | if        | inline    |
| int      | long     | register  | restrict  |
| return   | short    | signed    | sizeof    |
| static   | struct   | switch    | typedef   |
| union    | unsigned | void      | volatile  |
| while    |          |           |           |


## Data Size and Binary Representation 

| Type          | Meaning                                      | Size (bytes) | Size (bits) |
|---------------|----------------------------------------------|--------------|-------------|
| `char`        | a single byte, capable of holding one character | 1 byte     | 8 bits      |
| `int`         | an integer                                   | 4 bytes      | 32 bits     |
| `float`       | single-precision floating point number       | 4 bytes      | 32 bits     |
| `double`      | double-precision floating point number       | 8 bytes      | 64 bits     |
| `short int`   | -                                            | 2 bytes      | 16 bits     |
| `long int`    | -                                            | 8 bytes      | 64 bits     |
| `long double` | -                                            | 16 bytes     | 128 bits    |


## Numeric Constants 

The Int in c can be represented in vatious bases as hexadecimal or octagonal 
    
Example:
```cpp
int year = 1984; //integer constant 1984
int octalYear = 03700; //1984 in octal
int hexYear = 0x7c0; //1984 in hexadecimal
```
## Character Constants

character constants are specified by enclosing a single character within single quotes ('). For example:
``` cpp
char myChar = 'A';
```
Character constants can also include escape sequences to represent special characters. Some commonly used escape sequences are:

```cpp
char newline = '\n'; 
char tab = '\t';
char singleQuote = '\'';
char backslash = '\\';
```

## String Constants
string constants are sequences of characters enclosed within double quotes ("). For example:
```cpp
char *myString = "Hello, world!";
```
String constants are represented as **arrays** of characters in memory, terminated by a null character **('\0')** to indicate the end of the string.

```cpp
char myString[] = "Hello";
//'H','e','l','l','o','\0'.
```
## Enumeration Constants

Enumeration constants (also known as enum constants) are symbolic names for integral constants. They provide a way to define sets of related constants in a more readable and maintainable manner.

```cpp
enum Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

Monday    : 0
Tuesday   : 1
Wednesday : 2
Thursday  : 3
Friday    : 4
Saturday  : 5
Sunday    : 6
```
 You can also explicitly assign values to enumeration constants and subsequent enumeration constants are assigned sequential values, incremented by 1.

```cpp

enum Day { Monday=1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
    
Monday    : 1
Tuesday   : 2
Wednesday : 3
Thursday  : 4
Friday    : 5
Saturday  : 6
Sunday    : 7
```
##  Const Keyowrd
The const keyword is used to specify that a variable’s value cannot be changed. It tells the compiler to prevent the user from changing the value of that variable.

```cpp
const int x = 33;
``` 