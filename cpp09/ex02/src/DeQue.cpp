# include "../inc/PmergeMe.hpp"

void PmergeMe::d_sortPairs(int elemCount, int elemSize)
{
	d_it it = d_mergeMe.begin();

	for (int i = 0; i < elemCount - 1; i += 2)
	{
		d_it first = it + i * elemSize, second = it + (i + 1) * elemSize;

		if (*first < *second)
		{
			comparisons++;
			std::swap_ranges(first, second, second);
		}
	}
}

void PmergeMe::d_binarySearch(deque &d_top, deque &d_bottom, size_t index, size_t elemSize)
{
	int left = 0, right = index + insertCount;
	d_it bottom_it = d_bottom.begin() + index * elemSize, top_it = d_top.begin();

	if (index == 0)
	{
		d_top.insert(top_it, bottom_it, bottom_it + elemSize);
		return;
	}
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (d_top[mid * elemSize] < *bottom_it && comparisons++)
			left = mid + 1;
		else
			right = mid - 1;
	}
	d_top.insert(top_it + left * elemSize, bottom_it, bottom_it + elemSize);
	insertCount++;
}

void PmergeMe::d_makePairs(int elemCount, int elemSize, deque &d_top, deque &d_bottom)
{
	d_it it = d_mergeMe.begin();

	for (int i = 0; i < elemCount; ++i)
	{
		if ((i == elemCount - 1 || i % 2 == 1) && comparisons++)
			d_bottom.insert(d_bottom.end(), it + i * elemSize, it + (i + 1) * elemSize);
		else if (i % 2 == 0 && comparisons++)
			d_top.insert(d_top.end(), it + i * elemSize, it + (i + 1) * elemSize);
	}
}

void PmergeMe::d_insert(int elemCount, int elemSize, deque &d_top, deque &d_bottom)
{
	int index = 0;
	int d_bottomCount = elemCount / 2 + elemCount % 2;
	j_index = 0;
	insertCount = 0;

	d_makePairs(elemCount, elemSize, d_top, d_bottom);
	for (int i = 0; i < d_bottomCount; ++i)
	{
		index = getNextIndex(index);
		if (index >= d_bottomCount)
			index = d_bottomCount;
		d_binarySearch(d_top, d_bottom, index - 1, elemSize);
	}
	for (size_t i = 0; i < d_top.size(); ++i)
		d_mergeMe[i] = d_top[i];
}

void PmergeMe::d_mergeInsert(int elemCount, int elemSize)
{
	if (elemCount == 1)
		return;
	deque d_top, d_bottom;
	d_sortPairs(elemCount, elemSize);
	d_mergeInsert(elemCount / 2, elemSize * 2);
	d_insert(elemCount, elemSize, d_top, d_bottom);
}

void	PmergeMe::d_init(int argc, char **argv)
{
	comparisons = 1;
	for (int i = 1; i < argc; i++)
		d_mergeMe.push_back(std::atoi(argv[i]));
	if (isSorted(d_mergeMe) == true)
    {
        printContainer(d_mergeMe, DEQ_TYPE, "before");
		throw Exception(errorMessage(ERR_SORTED));
    }
}

void	PmergeMe::d_sort(int argc, char **argv)
{
	clock_t start = clock();
	d_init(argc, argv);
	printContainer(d_mergeMe, DEQ_TYPE, "before");
	d_mergeInsert(d_mergeMe.size(), 1);
	printContainer(d_mergeMe, DEQ_TYPE, "after");
	if (isSorted(d_mergeMe) == false)
		throw Exception(errorMessage(ERR_NOT_SORTED));
	printResult(argc - 1, DEQ_TYPE, clock() - start, comparisons - 1);
}
