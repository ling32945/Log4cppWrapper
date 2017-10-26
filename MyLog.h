#ifndef MYLOG_H
#define MYLOG_H

#include<log4cpp/Category.hh>
#include<iostream>

class MyLog
{
public:
    static MyLog& getInstance();
    static void destory();

    void tableError(const char* msg, ...);
    void tableWarn(const char* msg, ...);
    void tableInfo(const char* msg, ...);
    void tableDebug(const char* msg, ...);

private:
    MyLog();

    static MyLog *plog_;
    //log4cpp::Category &category_ref_;
    log4cpp::Category &table;
};

// Convert int to string
inline std::string int2string(int line) {
    std::ostringstream oss;
    oss << line;
    return oss.str();
}

// Define a Macro to add File Name, Function Name, Line Number to the end of log
#define logSuffix(msg) std::string(msg).append(" ##")\
        .append(__FILE__).append(":").append(__func__)\
        .append(":").append(int2string(__LINE__))\
        .append("##").c_str()


// Noneed to call getInstance every time, only write #define _LOG4CPP_ in the main function file
#ifdef _LOG4CPP_
MyLog &logger = MyLog::getInstance();
#else
extern MyLog &logger;
#endif

//#define LogTableError(msg) logger.tableError(logSuffix(msg))
//#define LogTableError(msg, ...) printf(msg, ## __VA_ARGS__)
#define LogTableError(msg, ...)                 \
    do {                                        \
        size_t size = 1024;                     \
        char* buffer = new char[size];          \
        sprintf(buffer, msg, ## __VA_ARGS__);   \
        logger.tableError(logSuffix(buffer));   \
    }                                           \
    while (0)

//#define LogTableWarn(msg) logger.tableWarn(logSuffix(msg))
#define LogTableWarn(msg, ...)                  \
    do {                                        \
        size_t size = 1024;                     \
        char* buffer = new char[size];          \
        sprintf(buffer, msg, ## __VA_ARGS__);   \
        logger.tableWarn(logSuffix(buffer));    \
    }                                           \
    while (0)

//#define LogTableInfo(msg) logger.tableInfo(logSuffix(msg))
#define LogTableInfo(msg, ...)                  \
    do {                                        \
        size_t size = 1024;                     \
        char* buffer = new char[size];          \
        sprintf(buffer, msg, ## __VA_ARGS__);   \
        logger.tableInfo(logSuffix(buffer));    \
    }                                           \
    while (0)

//#define LogTableDebug(msg) logger.tableDebug(logSuffix(msg))
#define LogTableDebug(msg, ...)                 \
    do {                                        \
        size_t size = 1024;                     \
        char* buffer = new char[size];          \
        sprintf(buffer, msg, ## __VA_ARGS__);   \
        logger.tableDebug(logSuffix(buffer));   \
    }                                           \
    while (0)

#endif // MYLOG_H
