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

bool NumberStore::getFetch() const{
    return (fdecount!= -1 &&fdecount % 3 == 0);
}
bool NumberStore::getDecode() const{
    return (fdecount!= -1 &&fdecount % 3 == 1);
}
bool NumberStore::getExecute() const{
    return (fdecount!= -1 &&fdecount % 3 == 2);
}

void NumberStore::setfdecount(){
    if(!halted){
        emit fdecountChanged();
        ++fdecount;
    }

}

int NumberStore::getAccVal() const{
    return accVal;
}
