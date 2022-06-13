/**
 *  @brief      Logic net (wires)
 **/
#ifndef SIM_NET_H
#define SIM_NET_H

#include <vector>

namespace Sim {

    class Component;

    class Net {
        public:

            explicit Net(std::size_t width);

            void update();

            void connect(Sim::Component* component, std::size_t pin_num);

            [[nodiscard]] std::size_t get_width() const;
            void set_width(std::size_t width);

            [[nodiscard]] bool get_bit(std::size_t bit) const;
            void set_bit(std::size_t bit, bool value);

            std::vector<bool> get_value();

            bool merge(Net* net);

        private:
            std::size_t         m_width;
            std::vector<bool>   m_values;

            std::vector<std::pair<Sim::Component*, std::size_t>> m_connections{};
    };
}

#endif // SIM_NET_H
