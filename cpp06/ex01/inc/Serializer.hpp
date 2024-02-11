#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# pragma once

# include <stdint.h>
# include <iostream>
# include "DataStructure.hpp"

class Serializer
{
	private:

		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator = (const Serializer &other);
		~Serializer();
	
	public:

		static	uintptr_t 				serialize(t_DataStructure *data_ptr);
		static	t_DataStructure			*deserialize(uintptr_t raw);
};

#endif