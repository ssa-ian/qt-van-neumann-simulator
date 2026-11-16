#include "NumberSource.h"

QVariantList NumberStore::registers() const
{
    QVariantList out;
    out.reserve(m_list.size());
    for (const RegisterValue &reg : m_list) {
        out.append(QVariant::fromValue(reg));
    }
    return out;
}

QList<RegisterValue> NumberStore::registersTest() const{
    return m_list;
}