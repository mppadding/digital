/**
 *  @brief      Logic pin
 **/
#ifndef SIM_PIN_H
#define SIM_PIN_H

#include <sim/net.h>
#include <string>
#include <vector>

namespace Sim {
    class Pin {
        public:
            void update();

            Pin();
            explicit Pin(std::string_view name);

            std::string_view    getName();
            void                setName(std::string_view name);

            std::vector<bool>   get_value();

            bool                get_bit(std::size_t bit);
            void                set_bit(std::size_t bit, bool value);

            void                disconnect();
            void                connect(Sim::Net* net);
            bool                is_connected();

            Sim::Net*           get_net();

        private:
            std::string         m_name;
            std::size_t         m_width;

            Sim::Net*           m_connection;
    };
}

#endif // SIM_PIN_H
