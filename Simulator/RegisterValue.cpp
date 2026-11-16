#include "RegisterValue.h"

RegisterValue::RegisterValue(int address, QString value)
    : m_value{value} , m_address{address}
{

}

QString RegisterValue::getValue() const{
    return m_value;
}


int RegisterValue::getAddress() const{
    return m_address;
}