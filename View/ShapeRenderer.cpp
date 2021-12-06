#include "ShapeRenderer.h"
#include <iostream>
ShapeRenderer::~ShapeRenderer() {
    SDL_DestroyRenderer(m_renderer);
}

void ShapeRenderer::clear() {
    SDL_RenderClear(m_renderer);
}

void ShapeRenderer::present() {
    SDL_RenderPresent(m_renderer);
}

void ShapeRenderer::render(Shape *s) {
    if (s->shape() == "Square") {
        render(static_cast<Square*>(s));
    }
}

void ShapeRenderer::render(Square *s) {
    uint32_t x = s->x();
    uint32_t y = s->y();

    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0x00);

    for (uint32_t y_off = 0; y_off < s->h(); y_off++)
        for (uint32_t x_off = 0; x_off < s->w(); x_off++)
            SDL_RenderDrawPoint(m_renderer, x + x_off, y + y_off);

    SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x00);
}