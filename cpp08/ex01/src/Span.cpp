#include "../inc/Span.hpp"
#include <cstddef>


Span::Span()
{

}

Span::Span(const Span &other) : N(other.N), storage(other.storage)
{

}

Span::Span(size_t _N) : N(_N)
{

}

Span::~Span()
{

}

Span	&Span::operator = (const Span &other)
{
	if (this == &other)
		return *this;
	this->N = other.N;
	this->storage = other.storage;
	return *this;
}

void	Span::addNumber(int n)
{
	if (this->storage.size() < this->N)
		this->storage.push_back(n);
	else
		throw AlreadyFull();
}

int		Span::shortestSpan()
{
	if (this->storage.size() <= 1)
		throw NoSpanFound();

	std::set <int> sorted(this->storage.begin(), this->storage.end());

	int		span = INT32_MAX;
	std::set <int>::iterator	iterator = sorted.begin();
	std::set <int>::iterator	prev = iterator++;

	for (; iterator != sorted.end(); prev = iterator++)
		span = std::min(span, *iterator - *prev);
	return span;
}

int		Span::longestSpan()
{
	if (this->storage.size() <= 1)
		throw NoSpanFound();

	return *(std::max_element(this->storage.begin(), this->storage.end())) - *(std::min_element(this->storage.begin(), this->storage.end()));
}

size_t	Span::getN() const
{
	return this->N;
}

const char	*Span::AlreadyFull::what() const throw()
{
	return "Error: Span Container Already Full";
}

const char	*Span::NoSpanFound::what() const throw()
{
	return "Error: No Span Found";
}