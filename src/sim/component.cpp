/**
 *  @brief      Generic component
 **/
#include <sim/component.h>

#include <sim/net.h>
#include <sim/pin.h>

namespace Sim {
    void Component::connect(Sim::Net* net, std::size_t pin) {
        if(pin >= m_pins.size()) {
            return;
        }

        net->connect(this, pin);
        m_pins[pin].connect(net);
    }

    Sim::Net* Component::get_pin_net(std::size_t pin) {
        if(pin >= m_pins.size()) {
            return nullptr;
        }

        return m_pins[pin].get_net();
    }
}
