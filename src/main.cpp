#include <iostream>
#include <chrono>

#include <fmt/core.h>

#include <sim/component.h>
#include <sim/components/gates/and_gate.h>

using namespace Sim;
using namespace Sim::Components;

/*

    ┌───────╮
A───┤A      │   X1
    │   &  X├───┤
B───┥B      │   │  ┌───────╮
    └───────╯   └──┤A      │
                   │   &  X├────X2
C──────────────────┥B      │
                   └───────╯
*/

int main() {
    Gates::AND and1{};
    Gates::AND and2{};

    Net A{1};
    Net B{1};
    Net C{1};

    Net X1{1};
    Net X2{1};
    
    and1.connect(&A, 0);
    and1.connect(&B, 1);
    and1.connect(&X1, 2);

    and2.connect(&X1, 0);
    and2.connect(&C, 1);
    and2.connect(&X2, 2);

    fmt::print("A | B | C || X1 X2\n");
    fmt::print("--+---+---++------\n");

    for(std::size_t i = 0; i < 8; i++) {
        A.set_bit(0, (i >> 2) & 0b1);
        B.set_bit(0, (i >> 1) & 0b1);
        C.set_bit(0, i & 0b1);
        fmt::print("{:d} | {:d} | {:d} ||  {:d}  {:d}\n", A.get_bit(0), B.get_bit(0), C.get_bit(0), X1.get_bit(0), X2.get_bit(0));
    }

    return 0;
}
