#include <fmt/core.h>
#include <sim/components/gates/and_gate.h>

namespace Sim::Components::Gates {
    
    AND::AND() : m_width(2) {
        m_pins.emplace_back("IN 1");
        m_pins.emplace_back("IN 2");
        m_pins.emplace_back("OUT");
    }

    AND::AND(std::size_t width) : m_width(width) {
        for(std::size_t i = 0; i < m_width; i++) {
            m_pins.emplace_back(fmt::format("IN {:d}", i));
        }

        m_pins.emplace_back("OUT");
    }

    void AND::update(std::size_t pin) {
        if(pin == m_width) {
            return;
        }

        bool output = true;
        for(std::size_t i = 0; i < m_width; i++) {
            // One of the pins is disconnected, no need to update output
            if(!m_pins[i].is_connected()) {
                return;
            }

            output = output && m_pins[i].get_bit(0);
        }

        m_pins[m_width].set_bit(0, output);
    }
}
