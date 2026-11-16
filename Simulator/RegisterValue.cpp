#include "RegisterValue.h"

RegisterValue::RegisterValue(int address, QString value, bool isFocused)
    : m_value{value} , m_address{address}, m_isFocused{isFocused}
{

}

QString RegisterValue::getValue() const{
    return m_value;
}


int RegisterValue::getAddress() const{
    return m_address;
}

bool RegisterValue::isFocused() const{
    return m_isFocused;
}

void RegisterValue::setFocused(bool b){
    m_isFocused = b;
}

void RegisterValue::setValue(std::string_view sv){
    m_value = QString::fromStdString(std::string{sv});
}