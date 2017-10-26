# Log4cppWrapper

1. Introduction
There are many advantange of using Log4cpp, but if we don't encapsulate it, it's not convient to use it, like some funciton name are long. So we need encapsulate it, Easier using log4cpp like using funciton printf().

2. Encapsulating objectives
    + No need to call the getInstance of Log4cpp once we use it, we only need to include it at main file one time. 
    + Make the log functions short, like we just calling logError("some log").
    + The output log contains file name, function name, line number.
    + use singleton pattern to enscapsulate it
