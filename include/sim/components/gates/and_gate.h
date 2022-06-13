/**
 *  @brief      AND gate (1 bit)
 **/
#ifndef SIM_GATES_AND_H
#define SIM_GATES_AND_H

#include <sim/net.h>
#include <string>
#include <vector>

#include <sim/component.h>

namespace Sim::Components::Gates {
    class AND : public Sim::Component {
        public:
            AND();
            explicit AND(std::size_t width);

            void update(std::size_t pin) override;
        private:
            std::size_t m_width;
    };
}

#endif // SIM_GATES_AND_H
