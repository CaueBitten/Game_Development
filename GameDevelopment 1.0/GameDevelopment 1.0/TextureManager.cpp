#include "TextureManager.h"

using namespace std;

TextureManager* TextureManager::s_pInstance = 0;

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
	s_pInstance = 0;
}

TextureManager * TextureManager::Instance()
{
	if (s_pInstance == 0) {
		s_pInstance = new TextureManager();
		return s_pInstance;
	}
	
	return s_pInstance;
}

bool TextureManager::load(string fileName, string id, SDL_Renderer * pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if (pTempSurface == 0) {

		cout << "load image fail : " << IMG_GetError() << endl;
		return false;		// Failing load image
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	// everything went ok, add the texture to our map
	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}

	// reaching here means something went wrong
	cout << "create a texture from a surface fail" << endl;
	return false;
}

void TextureManager::draw(string id, int xSrc, int ySrc, int xDest, int yDest, int width, int height, SDL_Renderer * pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = xSrc;
	srcRect.y = ySrc;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = xDest;
	destRect.y = yDest;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id] , &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string id, int xSrc, int ySrc, int xDest, int yDest, int width, int height, int currentRow, int currentFrame, SDL_Renderer * pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * currentFrame + xSrc;
	srcRect.y = height * (currentRow - 1) + ySrc;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = xDest;
	destRect.y = yDest;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id)
{
	m_textureMap.erase(id);
}
