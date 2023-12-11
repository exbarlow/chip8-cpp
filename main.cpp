#include <iostream>

#include <SDL.h>


int main(int argc, char* argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL_Init(SDL_INIT_VIDEO) returned error: " << SDL_GetError() << "\n";  
        return -1;  
    } else {
        std::cout << "SDL video system initialized\n";
    }

    SDL_Window* window = nullptr;

    window = SDL_CreateWindow("C++ SDL MacOS Window", 0, 0, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Failed to create window\n";
        return -1;
    }

    bool is_running = true;
    while (is_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    is_running = false;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_1:
                            std::cout << "you pressed number 1\n";
                            break;
                        case SDL_SCANCODE_ESCAPE:
                        case SDL_SCANCODE_Q:
                            is_running = false;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

    }

    SDL_DestroyWindow(window);
    return 0;
}