#pragma once
#include <QObject>
#include <QList>
#include <QtQml/qqmlregistration.h>
#include <QDebug>
#include "RegisterValue.h"
#include <QVariant>
#include <string>

class NumberStore : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(QList<RegisterValue> registers READ registersTest NOTIFY registersChanged)
    Q_PROPERTY(bool fetch READ getFetch NOTIFY fdecountChanged)
    Q_PROPERTY(bool decode READ getDecode NOTIFY fdecountChanged)
    Q_PROPERTY(bool execute READ getExecute NOTIFY fdecountChanged)
    Q_PROPERTY(int accumulator READ getAccVal NOTIFY accumulatorChanged)
    Q_PROPERTY(int pcounter READ getCounter NOTIFY pcounterChanged)
    Q_PROPERTY(QString iregister READ getiregister NOTIFY iregisterChanged)
public:
    explicit NumberStore(QObject *parent = nullptr) : QObject(parent)
    {
    }

    QVariantList registers() const;

    QList<RegisterValue> registersTest() const;

    QString getiregister() const;

    bool getFetch() const;
    bool getDecode() const;
    bool getExecute() const;

    Q_INVOKABLE void setfdecount();

    Q_INVOKABLE void reset();

    int getCounter() const;

    int getAccVal() const;

signals:
    void registersChanged();
    void fdecountChanged();
    void accumulatorChanged();
    void pcounterChanged();
    void iregisterChanged();

private:
    QList<RegisterValue> m_list {
        {0,"LOAD 6", true},
        {1,"ADD 2"} ,
        {2,"STORE 7"},
        {3,"HALT"},
        {4,"0"},
        {5,"0"},
        {6,"2"},
        {7,"0"}};

    int fdecount = 0;

    int accVal = 0;

    int pc = 0;

    bool halted = false;

    std::string iregister {m_list.begin() ->getValue().QString::toStdString()};
};