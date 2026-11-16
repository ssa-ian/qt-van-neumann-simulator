#pragma once
#include <QObject>
#include <QList>
#include <QtQml/qqmlregistration.h>
#include <QDebug>
#include "RegisterValue.h"
#include <QVariant>

class NumberStore : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(QList<RegisterValue> registers READ registersTest NOTIFY registersChanged)
    Q_PROPERTY(bool fetch READ getFetch NOTIFY fdecountChanged)
    Q_PROPERTY(bool decode READ getDecode NOTIFY fdecountChanged)
    Q_PROPERTY(bool execute READ getExecute NOTIFY fdecountChanged)
    Q_PROPERTY(int accumulator READ getAccVal NOTIFY accumulatorChanged)
public:
    explicit NumberStore(QObject *parent = nullptr) : QObject(parent)
    {
    }

    QVariantList registers() const;

    QList<RegisterValue> registersTest() const;

    bool getFetch() const;
    bool getDecode() const;
    bool getExecute() const;

    Q_INVOKABLE void setfdecount();

    int getAccVal() const;

signals:
    void registersChanged();
    void fdecountChanged();
    void accumulatorChanged();

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

    int fdecount = -1;

    int accVal = 0;

    bool halted = false;
};