#ifndef REGISTERVALUE_H
#define REGISTERVALUE_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

class RegisterValue{
    Q_GADGET
    QML_VALUE_TYPE(registerValue)
    Q_PROPERTY(QString value READ getValue)
    Q_PROPERTY(int address READ getAddress)
    Q_PROPERTY(bool isfocused READ isFocused)

    QString m_value;
    int m_address;
    bool m_isFocused = false;
public:
    RegisterValue() = default;
    RegisterValue(int address, QString valuel, bool isFocused = false);

    QString getValue() const;

    int getAddress() const;

    bool isFocused() const;

    void setFocused(bool b);
};


#endif // REGISTERVALUE_H
