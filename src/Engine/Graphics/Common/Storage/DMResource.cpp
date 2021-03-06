#include "DMResource.h"

namespace GS
{

DMResource::DMResource( uint32_t id, const std::string& name ) : m_id( id ), m_name( name )
{
}

DMResource::DMResource( DMResource&& other )
{
	*this = std::move( other );
}

DMResource& DMResource::operator=( DMResource&& other )
{
	m_id = other.m_id;
	m_name = std::move( other.m_name );
	return *this;
}

DMResource::~DMResource()
{
}

const std::string& DMResource::name()
{
	return m_name;
}

uint32_t DMResource::id()
{
	return m_id;
}

}