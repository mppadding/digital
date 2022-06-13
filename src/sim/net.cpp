/**
 *  @brief      Logic net (wires)
 **/
#include <sim/net.h>

#include <sim/component.h>

namespace Sim {
    Net::Net(std::size_t width) : m_width(width), m_values(width) {}

    void Net::connect(Sim::Component* component, std::size_t pin_num) {
        m_connections.emplace_back(component, pin_num);
    }

    std::size_t Net::get_width() const {
        return m_width;
    }

    void Net::set_width(std::size_t width) {
        m_width = width;
    }

    bool Net::get_bit(std::size_t bit) const {
        return m_values[bit];
    }

    void Net::set_bit(std::size_t bit, bool value) {
        m_values[bit] = value;

        for(auto comp_pin : m_connections) {
            comp_pin.first->update(comp_pin.second);
        }
    }

    std::vector<bool> Net::get_value() {
        return m_values;
    }

    bool Net::merge(Net* net) {
        if(net == nullptr || net == this || net->get_width() != m_width) {
            return false;
        }

        // Pre-allocate memory
        m_connections.reserve(m_connections.size() + net->m_connections.size());

        // Merge
        for(auto connection : net->m_connections) {
            connection.first->connect(this, connection.second);
        }

        net->m_connections.clear();

        return true;
    }
}
