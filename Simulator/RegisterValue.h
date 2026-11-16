#ifndef REGISTERVALUE_H
#define REGISTERVALUE_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

class RegisterValue{
    Q_GADGET
    QML_VALUE_TYPE(registerValue)
    Q_PROPERTY(QString value READ getValue)
    Q_PROPERTY(int address READ getAddress)

    QString m_value;
    int m_address;
public:
    RegisterValue() = default;
    RegisterValue(int address, QString value);

    QString getValue() const;

    int getAddress() const;
};


#endif // REGISTERVALUE_H
