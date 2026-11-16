#include "NumberSource.h"
#include <string_view>

enum class Action{
    LOAD,
    ADD,
    STORE,
    HALT
};

Action getAction(std::string_view s){
    char c {*s.begin()};

    switch(c){
        case 'L':
            return Action::LOAD;
            break;
        case 'A':
            return Action::ADD;
            break;
        case 'S':
            return Action::STORE;
            break;
        case 'H':
        default:
            return Action::HALT;
            break;
    }
}

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

        if(getExecute()){
            ++pc;
            emit pcounterChanged();
            for(RegisterValue& rv : m_list){
                rv.setFocused(false);
                if(rv.getAddress() == pc){
                    rv.setFocused(true);
                    iregister = rv.getValue().QString::toStdString();
                }
            }
            emit iregisterChanged();
            emit registersChanged();
        }
        ++fdecount;
        emit fdecountChanged();

    }

}

QString NumberStore::getiregister() const{
    return QString::fromStdString(iregister);
}

void NumberStore::reset(){
    for(RegisterValue& rv : m_list){
        rv.setFocused(false);
    }
    m_list.first().setFocused(true);
    pc = 0;
    fdecount = -1;
    accVal = 0;
    halted = false;
    iregister = m_list.begin() ->getValue().QString::toStdString();

    emit iregisterChanged();
    emit registersChanged();
    emit fdecountChanged();
    emit accumulatorChanged();
    emit pcounterChanged();
}

int NumberStore::getCounter() const{
    return pc;
}


int NumberStore::getAccVal() const{
    return accVal;
}
