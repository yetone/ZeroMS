#include "OSettings.h"
#include <QFile>
#include <QCoreApplication>

//public:
OSettings::OSettings(QString file):config(0),defaultConfig(0)
{
    configFile=file;
    load();
}

OSettings::~OSettings()
{
    DELETE(config);
    DELETE(defaultConfig);
}

void OSettings::load()
{
    //如果没有配置文件,输出默认配置文件
    if(!QFile::exists(configFile))
    {
        QFile file(configFile);
        QFile defaultConfigFile(":/config.ini");
        defaultConfigFile.open(QFile::ReadOnly);
        file.open(QFile::WriteOnly);
        file.write(defaultConfigFile.readAll());
    }
    DELETE(config);
    config=new QSettings(configFile,QSettings::IniFormat,qApp);
    config->setIniCodec("UTF-8");
    DELETE(defaultConfig);
    defaultConfig=new QSettings(":/config.ini",QSettings::IniFormat,qApp);
    defaultConfig->setIniCodec("UTF-8");
}
