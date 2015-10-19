#include "LoaderParams.h"

using namespace std;

LoaderParams::LoaderParams(int xSrc, int ySrc, int xDest, int yDest, int width, int height, string textureID)
{
	m_xSrc = xSrc;
	m_ySrc = ySrc;
	m_xDest = xDest;
	m_yDest = yDest;

	m_width = width;
	m_height = height;

	m_textureID = textureID;
}

LoaderParams::~LoaderParams()
{
}

int LoaderParams::getXSrc() const
{
	return m_xSrc;
}

int LoaderParams::getYSrc() const
{
	return m_ySrc;
}

int LoaderParams::getXDest() const
{
	return m_xDest;
}

int LoaderParams::getYDest() const
{
	return m_yDest;
}

int LoaderParams::getWidth() const
{
	return m_width;
}

int LoaderParams::getHeight() const
{
	return m_height;
}

string LoaderParams::getTextureID() const
{
	return m_textureID;
}
