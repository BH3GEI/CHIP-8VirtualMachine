#include "chip8.h"
#include <fstream>

void Chip8::initialize() {
    pc     = 0x200;  // Program counter starts at 0x200
    opcode = 0;      // Reset current opcode	
    I      = 0;      // Reset index register
    sp     = 0;      // Reset stack pointer
    
    // Clear display
    for (int i = 0; i < 64 * 32; i++)
        gfx[i] = 0;

    // Clear stack
    for (int i = 0; i < 16; i++)
        stack[i] = 0;

    // Clear registers V0 through VF
    for (int i = 0; i < 16; i++)
        V[i] = 0;

    // Clear memory
    for (int i = 0; i < 4096; i++)
        memory[i] = 0;

    // Reset timers
    delay_timer = 0;
    sound_timer = 0;
}

void Chip8::loadGame(const char *filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (file.is_open()) {
        std::streampos size = file.tellg();
        char* buffer = new char[size];

        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        for (long long i = 0; i < size; ++i)
            memory[i + 512] = buffer[i];

        delete[] buffer;
    }
}

void Chip8::emulateCycle() {
    // Fetch opcode
    opcode = memory[pc] << 8 | memory[pc + 1];

    // Decode opcode
    switch(opcode & 0xF000){
        // ... implement opcode decoding and execution here...
    }

    // Update timers
    if(delay_timer > 0)
        --delay_timer;

    if(sound_timer > 0)
        --sound_timer;
}