# chapter 7 Classes

## [Exercise 7.1](ex7_01.cpp)
## [Exercise 7.2](ex7_02.h)
## [Exercise 7.3](ex7_03.cpp)
## [Exercise 7.5](ex7_05.h)
## [Exercise 7.6](ex7_06.h)
## [Exercise 7.7](ex7_07.cpp)

## Exercise 7.8
Define `read`'s Sales_data parameter as plain reference since it's intended to change the members' value.

Define `print`'s Sales_data parameter as a reference to const since it isn't intended to change any member's value of this object.

## [Exercise 7.9](ex7_09.h)

## Exercise 7.10
The condition of the `if` statement would read two Sales_data object at one time. It is equalequivalent to
```cpp
std::istream &step1 = read(std::cin, data1);
sdt::istream &step2 = read(step1, data2);
if (step2)
```