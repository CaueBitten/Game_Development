#pragma once

#include <string>

class LoaderParams
{
private:

	int m_xSrc;
	int m_ySrc;
	int m_xDest;
	int m_yDest;

	int m_width;
	int m_height;
	
	std::string m_textureID;

public:

	LoaderParams(int xSrc, int ySrc, int xDest, int yDest, int width, int height, std::string textureID);
	~LoaderParams();

	int getXSrc() const;
	int getYSrc() const;
	int getXDest() const;
	int getYDest() const;

	int getWidth() const;
	int getHeight() const;

	std::string getTextureID() const;
};

