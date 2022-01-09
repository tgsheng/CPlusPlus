# ch2 Variables and Basic Types

## Exercise 2.3
> What output will the following code produce?
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

**Output(clang++ 12.0.1)**
```
32
4294967264
32
-32
0
0
```

**Explanation**

The result of `u - u2`, -32, won't fit in an `unsigned` value. -32 will be transformed to an `unsigned` value. Assuming 32-bit `int`, converting an `int` to `unsigned` is to add $2^{32}$ to it.

For example, the loop below will never terminate, because `u` is a `unsigned` value, which never less than 0.
```cpp
for (unsigned u = 10; u >= 0; --u)
    std::cout << u << std::endl;
```

**Follow Up**

Expressions that mix `signed` and `unsigned` values can yield surprising results when the `signed` value is negative -- `signed` values are automatically converted to `unsigned`.
```cpp
int a = -1, b = 1;
std::cout << a * b << std::endl; // -1
unsigned c = 1;
std::cout << a * c << std::endl; // 4294967295
```

## Exercise 2.10
> What are the initial values, if any, of each of the following variables?
```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```
`global_str` is a global variable, so the value is empty string.

`global_int` is a global variable, so the value is 0.

`local_int` is a local variable which is unintialized, so it has a undefined value.

`local_str` is also a local variable which is unitialized, but it has a value, empty string, that is defined by the class.

**Explanation**

Uninitialized objects of built-in type defined inside a function body have undefined value. Objects of class type that we do not explicitly initialize have a value that is defined by the class. So we recommend initializing every object of built-in type.

## Exercise 2.11
> Explain whether each of the following is a declaration or a definition:
```cpp
    extern int ix = 1024; // (a) definition
    int iy;               // (b) definition
    extern int iz;        // (c) declaration
```

**Note**

A variable declaration specifies the type and name of a variable. . In addition to specifying the name and type, a definition also allocates storage and may provide the variable with an initial value.

Any declaration that includes an explicit initializer is a definition, such as (a).

Variables must be defined exactly once but can be declared many times.
