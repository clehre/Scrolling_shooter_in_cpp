
//
// Created by Christoffer Lehre on 03/04/2022.
//

#include "TextureManager.h"

bool TextureManager::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    m_window = SDL_CreateWindow("SpaceWars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOWWIDTH,
                                WINDOWHEIGHT,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (m_window == nullptr) {
        std::cout << "window initialize failed" << std::endl;
        TextureManager::Instance().clean();
        return false;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        std::cout << "renderer initialize failed" << std::endl;
        TextureManager::Instance().clean();
        return false;
    }

    TTF_Init();

    m_ttfFont = TTF_OpenFont("../img/Font.ttf", 120);

    if (m_ttfFont == nullptr) {
        std::cout << "font initialize failed" << std::endl;
        TextureManager::Instance().clean();
        return false;
    }


    std::cout << "Texturemanager init finished successfully" << std::endl;
    return true;
}

void
TextureManager::renderText(const char *text, Vector2D pos, Vector2D size) {

    SDL_Rect textRect;
    textRect.x = pos.getX();
    textRect.y = pos.getY();
    textRect.w = size.getX();
    textRect.h = size.getY();

    SDL_Surface *textSurface = TTF_RenderText_Solid(m_ttfFont, text, m_yellow);

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(m_renderer, textSurface);

    SDL_RenderCopy(m_renderer, textTexture, nullptr, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

bool TextureManager::load(const char *path, const char *id) {
    SDL_Surface *tmpSurface = IMG_Load(path);
    if (tmpSurface == nullptr) {
        std::cout << "TextureManager failed Loading img" << path << std::endl;
        return false;
    }
    SDL_Texture *pTexture =
            SDL_CreateTextureFromSurface(m_renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    if (pTexture != nullptr) {
        m_textureMap[id] = pTexture;
        return true;
    }
    std::cout << "TextureManager failed Loading img" << path << std::endl;
    return false;

}

void TextureManager::draw(const std::string &id, Vector2D pos, Vector2D size, SDL_Renderer *pRenderer,
                          SDL_RendererFlip sdlFlip, double angle) {
    SDL_Rect srcRect{0, 0, size.getX(), size.getY()};
    SDL_Rect destRect{pos.getX(), pos.getY(), size.getX(), size.getY()};
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, angle, 0, sdlFlip);
}

void TextureManager::drawFrame(const std::string &id, Vector2D pos, Vector2D size, int currentFrame, int currentRow,
                               SDL_Renderer *pRenderer, SDL_RendererFlip sdlFlip, double angle) {
    SDL_Rect srcRect{size.getX() * currentFrame, size.getY() * currentRow, size.getX(), size.getY()};
    SDL_Rect destRect{pos.getX(), pos.getY(), size.getX(), size.getY()};
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, angle, 0, sdlFlip);

}

void TextureManager::drawBar(Vector2D pos, Vector2D size){
    SDL_SetRenderDrawColor(m_renderer,160,10,30,0);
    SDL_Rect destRect{pos.getX(), pos.getY(), size.getX(), size.getY()};
    SDL_RenderFillRect(m_renderer,&destRect);
    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);

}

void TextureManager::clean() {
    for (auto const &t: m_textureMap) {
        SDL_DestroyTexture(t.second);
    }
    SDL_Quit();
}
