#ifndef PUBLIC_CONST_H
#define PUBLIC_CONST_H

//全局通用常量定义文件
//ps.使用const常量会经过C++的类型检查！尽量减少使用预处理宏

//尽量减少包含头文件，尽可能使用前置声明
#include <QString>
class QSettings;
class QVariant;

//该宏几乎每个文件都要用到，考虑性能问题，不放在inline.h里
//注意，如果要操作的指针是只读的，不要使用这个宏，直接用delete关键字就行
#define DELETE(p) {if(p)delete (p);(p)=0;};

//配置文件相关
extern QSettings *config;
extern QSettings *defaultConfig;
void loadConfig();
QVariant configValue(QString key);
//配置文件路径
const QString CONFIG_FILE = QObject::trUtf8("./config.ini");

#endif // PUBLIC_CONST_H