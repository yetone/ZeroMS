#include <QDateTime>
#include "OMessage.h"
#include "OGlobal.h"

//public:
OMessage::OMessage():type(0),protocol(P_VER),time(0)
{

}

OMessage::OMessage(int type,QByteArray data):type(type),protocol(P_VER),time(0),data(data)
{

}

OMessage::OMessage(int type):type(type),protocol(P_VER),time(0)
{

}

OMessage::OMessage(QByteArray data)
{
    protocol=QBtoint(data.mid(0,4));
    int len=QBtoint(data.mid(4,4));
    if(len!=data.size()-P_HEADLEN)
        Q_ASSERT(!"传递进的数据长度必须和数据包头部长度相等");
    type=QBtoint(data.mid(8,4));
    time=QBtoint(data.mid(12,4));

    this->data=data.mid(P_HEADLEN);
}

OMessage OMessage::fromDataBuff(QByteArray *databuf,bool autoRemove)
{
    if(!databuf)
        return OMessage();
    OMessage msg;
    if(databuf->size()>=P_HEADLEN)
    {
        int len=QBtoint(databuf->mid(4,4));
        if(databuf->size()>=len)
        {
            msg=OMessage(databuf->left(P_HEADLEN+len));
            if(autoRemove)
            {
                databuf->remove(0,P_HEADLEN+len);
            }
        }
    }
    return msg;
}

QString OMessage::split(int n)
{
    //TODO 很乱，有待改进
    QString str(data);
    //TODO int a=str.indexOf(" ");
    while(str.indexOf("  ")>-1)
        str=str.replace("  "," ");
    QString temp;
    while(n>-1)
    {
        str.remove(0,temp.length()?temp.length()+1:0);
        temp=str.left(str.indexOf(" "));
        n--;
    }

    if(temp.trimmed()=="/")
        temp="";
    return temp;
}

QString OMessage::splitTail(int n)
{
    //TODO 很乱，有待改进
    int N=n;
    int len=0;
    n--;
    while(n>-1)
    {
        len+=split(n).length();
        n--;
    }
    len+=N;

    QString str(data);
    return str.right(str.length()-len);
}

QByteArray OMessage::exec()
{
    if(!type)
        return QByteArray();
    QByteArray tData;
    QDataStream DSdata(&tData,QIODevice::WriteOnly);
    unsigned int time=QDateTime::currentDateTime().toTime_t();
    DSdata<<protocol<<data.size()<<type<<time;
    tData.append(data);
    return tData;
}
