# include "../inc/PmergeMe.hpp"

// sorts elements in pairs for initial organization before merging
// iterates over elements two by two and sorts the pairs in ascending order
// @param elemCount - total number of elements to be sorted in pairs
// @param elemSize - size of each element, used to calculate offset
void PmergeMe::d_sortPairs(int elemCount, int elemSize)
{
	d_it it = d_mergeMe.begin();

	for (int i = 0; i < elemCount - 1; i += 2)
	{
		d_it first = it + i * elemSize, second = it + (i + 1) * elemSize;

		if (*first < *second) // swap the pair if out of order
		{
			comparisons++;
			std::swap_ranges(first, second, second);
		}
	}
}

// performs a binary search on 'd_bottom' to find the correct insertion point in 'd_top'
// inserts elements from 'd_bottom' into 'd_top' at the calculated position
// @param d_top - the deque to insert into
// @param d_bottom - the deque to insert from
// @param index - the starting index for the search
// @param elemSize - the size of each element, used for offset calculation
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

// separates elements into two deques ('d_top' abd 'd_bottom') based on their position
// elements at even positions go into 'd_top' and odd positions into 'd_bottom'
// @param elemCount - total number of elements to be distributed
// @param elemSize - size of each element, used for offset calculation
// @param d_top - the deque for storing elements from even positions 
// @param d_bottom - the deque for storing elements from odd positions
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

// merges elements from 'd_bottom' into 'd_top' using binary search for optimal comparison count
// after merging, 'd_mergeMe' is updated with the sorted elements from 'd_top'
// @param elemCount - total number of elements to merge
// @param elemSize - size of each element for offset calculation
// @param d_top - target deque where elements from 'd_bottom' will be inserted
// @param d_bottom - source deque that will be merged into 'd_top'
void PmergeMe::d_insert(int elemCount, int elemSize, deque &d_top, deque &d_bottom)
{
	int index = 0; // start from the first element for insertion
	int d_bottomCount = elemCount / 2 + elemCount % 2; // calculate the number of elements in 'd_bottom'
	j_index = 0; // reset Jacobsthal index
	insertCount = 0; // reset insert count

	d_makePairs(elemCount, elemSize, d_top, d_bottom); // distribute elements into 'd_top' and 'd_bottom'
	for (int i = 0; i < d_bottomCount; ++i)
	{
		index = getNextIndex(index); // calculate next index using Jacobsthal sequence
		if (index >= d_bottomCount)
			index = d_bottomCount; // ensure index does not exceed bounds
		d_binarySearch(d_top, d_bottom, index - 1, elemSize); // insert 'd_bottom' elements into 'd_top'
	}
	for (size_t i = 0; i < d_top.size(); ++i)
		d_mergeMe[i] = d_top[i]; // update 'd_mergeMe' with sorted elements
}

// recursively applies the merge-insertion sort to sort elements
// divides the problem into smaller subsets, sorts pairs, then merges them
// @param elemCount - the total elements to sort
// @param elemSize - the size of each element, affecting sorting and merging logic
void PmergeMe::d_mergeInsert(int elemCount, int elemSize)
{
	if (elemCount == 1)
		return; // base case - a single element is already sorted
	deque d_top, d_bottom; // temporary deques for holding elements during the sorting process
	d_sortPairs(elemCount, elemSize); // initial pair sorting
	d_mergeInsert(elemCount / 2, elemSize * 2); // recursive call for sorting smaller subsets
	d_insert(elemCount, elemSize, d_top, d_bottom); // merge & insert sorted elements
}

// initializes the sorting process
void	PmergeMe::d_init(int argc, char **argv)
{
	comparisons = 1;
	for (int i = 1; i < argc; i++)
		d_mergeMe.push_back(std::atoi(argv[i]));
	if (isSorted(d_mergeMe) == true)
    {
        printContainer(d_mergeMe, ERR_SORTED, "");
		throw Exception(errorMessage(ERR_SORTED)); // throw exception if already sorted
    }
}

// wrapper for the sorting & tracking of the performance
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
