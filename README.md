# Log4cppWrapper

## Introduction
There are many advantange of using Log4cpp, but if we don't encapsulate it, it's not convient to use it, like some funciton name are long. So we need encapsulate it, Easier using log4cpp like using funciton printf().

## Encapsulating objectives
1. No need to call the getInstance of Log4cpp once we use it, we only need to include it at main file one time. 
2. Make the log functions short, like we just calling logError("some log").
3. The output log contains file name, function name, line number.
4. use singleton pattern to enscapsulate it
