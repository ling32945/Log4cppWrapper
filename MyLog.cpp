#include "MyLog.h"
#include <QDir>
#include<log4cpp/PropertyConfigurator.hh>

MyLog* MyLog::plog_ = NULL;

MyLog& MyLog::getInstance() {
    if (plog_ == NULL) {
        plog_ = new MyLog;
    }
    return *plog_;
}

void MyLog::destory() {
    if (plog_) {
        plog_->table.info("Mylog destory");
        plog_->table.shutdown();
        delete plog_;
    }
}

MyLog::MyLog() :
    table(log4cpp::Category::getInstance(std::string("Sgk.Table")))
{

    //QString appDirPath = QCoreApplication::applicationDirPath();
    //QString configPath = appDirPath + QString("/../../..") + QString("/Plug-ins.localized/Sgk/Configuration/");
    QString currentWorkDirectory = QDir::currentPath();
    QString configPath = currentWorkDirectory + QString("/Plug-ins.localized/Sgk/Configuration/");
    QString logConfigFileName = "log4cpp.properties";
    std::string logConfigFile = (configPath + logConfigFileName).toStdString();

    log4cpp::PropertyConfigurator::configure(logConfigFile);
    //log4cpp::Category& root = log4cpp::Category::getRoot();
    //log4cpp::Category& sgk = log4cpp::Category::getInstance(std::string("Sgk"));

}

void MyLog::tableError(const char* msg, ...) {
    size_t size = 1024;
    char* buffer = new char[size];

    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, size, msg, args);
    this->table.error(buffer);
    va_end(args);
}

void MyLog::tableWarn(const char* msg, ...) {
    size_t size = 1024;
    char* buffer = new char[size];

    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, size, msg, args);
    this->table.warn(buffer);
    va_end(args);
}

void MyLog::tableInfo(const char* msg, ...) {
    size_t size = 1024;
    char* buffer = new char[size];

    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, size, msg, args);
    this->table.info(buffer);
    va_end(args);
}

void MyLog::tableDebug(const char* msg, ...) {
    size_t size = 1024;
    char* buffer = new char[size];

    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, size, msg, args);
    this->table.debug(buffer);
    va_end(args);
}
