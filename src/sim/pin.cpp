/**
 *  @brief      Logic pin
 **/
#include <sim/pin.h>

namespace Sim {
    void update();

    Pin::Pin() : m_name("Pin"), m_width(1), m_connection(nullptr) {}
    Pin::Pin(std::string_view name) : m_name(name), m_width(1), m_connection(nullptr) {}

    std::string_view Pin::getName() {
        return m_name;
    }

    void Pin::setName(std::string_view name) {
        m_name = name;
    }

    std::vector<bool> Pin::get_value() {
        return m_connection->get_value();
    }

    bool Pin::get_bit(std::size_t bit) {
        return m_connection->get_bit(bit);
    }

    void Pin::set_bit(std::size_t bit, bool value) {
        if(m_connection == nullptr) {
            return;
        }

        m_connection->set_bit(bit, value);
    }

    void Pin::disconnect() {
        m_connection = nullptr;
    }

    void Pin::connect(Sim::Net* net) {
        m_connection = net;
    }

    bool Pin::is_connected() {
        return m_connection != nullptr;
    }

    Sim::Net* Pin::get_net() {
        return m_connection;
    }
}
