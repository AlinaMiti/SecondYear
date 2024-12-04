#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BitField.h"
#include "Set.h"
#include <iostream>


// int main(){
//     BitField G = BitField(10);
//     G.SetBit(5);
//     G.SetBit(7);
//     std::cout << "G:  ";
//     for(size_t i = 0; i < 10; i++){
//         if (G.GetBit(i) == 1)
//             std::cout << 1 << " ";
//         else std::cout << 0 << " ";
    
//     }
//     std::cout << " " << std::endl;
//     BitField G1 = G >> 100;
//     std::cout << "G1: ";
//     for(size_t i = 0; i < 10; i++){
//         if (G1.GetBit(i) == 1)
//             std::cout << 1 << " ";
//         else std::cout << 0 << " ";
//     }

//     std::cout << " " << std::endl;
//     BitField G2 = G1 << 100;
//     std::cout << "G2: ";
//     for(size_t i = 0; i < 10; i++){
//         if (G1.GetBit(i) == 1)
//             std::cout << 1 << " ";
//         else std::cout << 0 << " ";
//     }
//     return 0;
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
