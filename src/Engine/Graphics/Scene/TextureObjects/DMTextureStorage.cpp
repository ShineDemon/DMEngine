#include "DMTextureStorage.h"

namespace GS
{

DMTextureStorage::DMTextureStorage( const std::string& path ) : DMResourceStorage( path )
{

}

DMTextureStorage::~DMTextureStorage()
{

}

bool DMTextureStorage::load( const std::string& name )
{
	if( exists( name ) )
		return true;

	std::string fullPath = path() + "\\" + name;

	DMTexture texture( nextId(), m_textureLoader.loadFromFile( fullPath.data() ) );

	insertResource( name, std::move( texture ) );

	return true;
}

}