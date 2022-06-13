/**
 *  @brief      Generic component
 **/
#ifndef SIM_COMPONENT_H
#define SIM_COMPONENT_H

#include <vector>
#include <sim/pin.h>
#include <sim/net.h>

namespace Sim {
    class Component {
        public:
            virtual void update(std::size_t pin) = 0;

            void connect(Sim::Net* net, std::size_t pin);

            Sim::Net* get_pin_net(std::size_t pin);

        protected:
            std::vector<Pin> m_pins;
    };
}

#endif // SIM_NET_H
