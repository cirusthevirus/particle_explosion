// Name         Screen.hpp

#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <SDL2/SDL.h>

namespace jhb {

class Screen {
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

    Screen();
    bool init(const char* title);
    bool process_events();
    void close();
    void set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void update();
    void gaussian_blur();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    Uint32* m_buffer1;
    Uint32* m_buffer2;
    SDL_Event event;
    const double m_blur[3][3] = {{0.5, 0.5, 0.5},
                                 {0.5, 0.5, 0.5},
                                 {0.5, 0.5, 0.5}};
};

} // namespace jb

#endif // SCREEN_HPP_
