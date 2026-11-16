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
public:
    explicit NumberStore(QObject *parent = nullptr) : QObject(parent)
    {
    }

    QVariantList registers() const;

    QList<RegisterValue> registersTest() const;

signals:
    void registersChanged();
private:
    QList<RegisterValue> m_list {
        {0,"Hello"},
        {1,"Good"} ,
        {2,"Morning"},
        {3,""}};
};