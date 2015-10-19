#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <map>

class TextureManager
{
private:

	std::map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;

	TextureManager();

public:
	~TextureManager();

	static TextureManager* Instance();

	bool		load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void		draw(std::string id, int xSrc, int ySrc, int xDest, int yDest, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE); 
	void		drawFrame(std::string id, int xSrc, int ySrc, int xDest, int yDest, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void		clearFromTextureMap(std::string id);
};
typedef TextureManager TheTextureManager;