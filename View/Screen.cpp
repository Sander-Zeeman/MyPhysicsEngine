#include "Screen.h"

Screen::Screen() : Screen("Default Window", 640, 480) {}

Screen::Screen(const char title[]) : Screen(title, 640, 480) {}

Screen::Screen(const char title[], uint32_t width, uint32_t height)
    : m_width(width)
    , m_height(height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    initialize_window(title);
}

Screen::~Screen() {
    delete m_shapeRenderer;
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Screen::initialize_window(const char title[]) {
    if (m_window) {
        delete m_shapeRenderer;
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
        m_shapeRenderer = nullptr;
    }

    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(
        m_width,
        m_height,
        SDL_WINDOW_SHOWN,
        &m_window,
        &renderer
    );

    m_shapeRenderer = new ShapeRenderer(renderer);

    SDL_SetWindowTitle(m_window, title);

    if(!m_window) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }
}

void Screen::setWorld(World *w) {
    if (m_world)
        m_world->remove_observer(this);
    
    w->add_observer(this);
    m_world = w;
}

void Screen::render() {
    std::list<Shape*> shapes = m_world->shapes();
    m_shapeRenderer->clear();
    for (Shape *s : shapes)
        m_shapeRenderer->render(s);
    m_shapeRenderer->present();
}

void Screen::update() {
    render();
}