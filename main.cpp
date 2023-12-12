#include <iostream>
#include <array>
#include <stack>
#include <string>
#include <algorithm>
#include <fstream>

// #include <SDL.h>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Please run this program as " << argv[0] << " <filename>\n"; 
        return -1;
    } 
    std::string filename(argv[1]);

    if (filename.size() <= 4 || filename.substr(filename.size()-4, 4) != ".ch8") {
        std::cout << "Please provide a .ch8 file\n";
        return -1;
    }
    
    /* Init our virtual RAM + V0-VF registers for the interpreter */
    std::array<char, 4096> V_RAM{{0}};
    std::array<char, 16> V_REG{{0}};
    // represents a 64-bit by 32-bit pixel raster
    // outer array is row, inner array is col -> grouped into bytes of 8 pixels
    std::array<std::array<char, 8>,4> DISPLAY{{0}};

    // todo: how are we going to store the display?
    uint16_t I = 0x200;
    uint16_t PC = 0x200;

    //todo: figure out logic for these timers
    uint8_t delay = UINT8_MAX;
    uint8_t sound = UINT8_MAX;

    std::stack<uint16_t> call_stack;

    /* read the CHIP-8 file into memory */
    std::ifstream stream(filename, std::ifstream::in | std::ifstream::binary);

    if (!stream.is_open()) {
        std::cout << "Failed to open CHIP-8 file\n";
        return -1;
    }

    std::copy(std::istreambuf_iterator<char>{stream}, {}, V_RAM.begin() + 0x200);
    stream.close();
    
    return 0;
}