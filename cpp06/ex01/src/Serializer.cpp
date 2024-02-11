# include "../inc/Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

Serializer	&Serializer::operator = (const Serializer &other)
{
	if (this == &other)
		return *this;
	*this = other;
	return *this;
}

Serializer::~Serializer()
{

}

uintptr_t	Serializer::serialize(t_DataStructure *data_ptr)
{
	return reinterpret_cast<uintptr_t>(data_ptr);
}

t_DataStructure	*Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<t_DataStructure *>(raw);
}