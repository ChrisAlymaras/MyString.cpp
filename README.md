# MyString.cpp
MyString class represents strings without the use of C++ STL or String libraries.
This is accomplished with the use of a char array and the length of it.

Specifically, MyString class has three constructors. 
First one declares an empty string.
Second one declares a given string.
Third one declares a string that is a copy of another already declared.

Also, operators '==' '!=' '>' '<' are overloaded to compare strings.
Operator '+=' is overloaded to add another character in the end of a string.

Finally, array is returned as a C string together with it's length.
