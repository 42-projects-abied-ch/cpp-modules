# include "../inc/PmergeMe.hpp"

// sorts elements in pairs for initial organization before merging
// iterates over elements two by two and sorts the pairs in ascending order
// @param elemCount - total number of elements to be sorted in pairs
// @param elemSize - size of each element, used to calculate offset
void PmergeMe::v_sortPairs(int elemCount, int elemSize)
{
	v_it it = v_mergeMe.begin();

	for (int i = 0; i < elemCount - 1; i += 2)
	{
		v_it first = it + i * elemSize;
		v_it second = it + (i + 1) * elemSize;

		if (*first < *second) // swap the pair if out of order
		{
			comparisons++;
			std::swap_ranges(first, second, second);
		}
	}
}

// performs a binary search on 'v_bottom' to find the correct insertion point in 'v_top'
// inserts elements from 'v_bottom' into 'd_top' at the calculated position
// @param v_top - the vector to insert into
// @param v_bottom - the vector to insert from
// @param index - the starting index for the search
// @param elemSize - the size of each element, used for offset calculation
void PmergeMe::v_binarySearch(vector &v_top, vector &v_bottom, size_t index, size_t elemSize)
{
	int left = 0, right = index + insertCount;
	v_it bottom_it = v_bottom.begin() + index * elemSize, top_it = v_top.begin();

	if (index == 0)
	{
		v_top.insert(top_it, bottom_it, bottom_it + elemSize);
		return;
	}
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (v_top[mid * elemSize] < *bottom_it && comparisons++)
			left = mid + 1;
		else
			right = mid - 1;
	}
	v_top.insert(top_it + left * elemSize, bottom_it, bottom_it + elemSize);
	insertCount++;
}

// separates elements into two vectors ('v_top' abd 'v_bottom') based on their position
// elements at even positions go into 'v_top' and odd positions into 'v_bottom'
// @param elemCount - total number of elements to be distributed
// @param elemSize - size of each element, used for offset calculation
// @param v_top - the vector for storing elements from even positions 
// @param v_bottom - the vector for storing elements from odd positions
void PmergeMe::v_makePairs(int elemCount, int elemSize, vector &v_top, vector &v_bottom)
{
	v_it it = v_mergeMe.begin();

	for (int i = 0; i < elemCount; ++i)
	{
		if ((i == elemCount - 1 || i % 2 == 1) && comparisons++)
			v_bottom.insert(v_bottom.end(), it + i * elemSize, it + (i + 1) * elemSize);
		else if (i % 2 == 0 && comparisons++)
			v_top.insert(v_top.end(), it + i * elemSize, it + (i + 1) * elemSize);
	}
}

// merges elements from 'v_bottom' into 'v_top' using binary search for optimal comparison count
// after merging, 'v_mergeMe' is updated with the sorted elements from 'v_top'
// @param elemCount - total number of elements to merge
// @param elemSize - size of each element for offset calculation
// @param v_top - target vector where elements from 'v_bottom' will be inserted
// @param v_bottom - source vector that will be merged into 'v_top'
void PmergeMe::v_insert(int elemCount, int elemSize, vector &v_top, vector &v_bottom)
{
	int index = 0; // start from the first element for insertion
	int v_bottomCount = elemCount / 2 + elemCount % 2; // calculate the number of elements in 'v_bottom'
	j_index = 0; // reset Jacobsthal index
	insertCount = 0; // reset insert count

	v_makePairs(elemCount, elemSize, v_top, v_bottom); // distribute elements into 'v_top' and 'v_bottom'
	for (int i = 0; i < v_bottomCount; ++i)
	{
		index = getNextIndex(index); // calculate next index using Jacobsthal sequence
		if (index >= v_bottomCount)
			index = v_bottomCount; // ensure index does not exceed bounds
		v_binarySearch(v_top, v_bottom, index - 1, elemSize); // insert 'd_bottom' elements into 'd_top'
	}
	for (size_t i = 0; i < v_top.size(); ++i)
		v_mergeMe[i] = v_top[i]; // update 'v_mergeMe' with sorted elements
}

// recursively applies the merge-insertion sort to sort elements
// divides the problem into smaller subsets, sorts pairs, then merges them
// @param elemCount - the total elements to sort
// @param elemSize - the size of each element, affecting sorting and merging logic
void PmergeMe::v_mergeInsert(int elemCount, int elemSize)
{
	if (elemCount == 1)
		return; // base case - a single element is already sorted
	vector v_top, v_bottom; // temporary vectors for holding elements during the sorting process
	v_sortPairs(elemCount, elemSize); // initial pair sorting
	v_mergeInsert(elemCount / 2, elemSize * 2); // recursive call for sorting smaller subsets
	v_insert(elemCount, elemSize, v_top, v_bottom); // merge & insert sorted elements
}

// initializes the sorting process
void	PmergeMe::v_init(int argc, char **argv)
{
	comparisons = 1;
	for (int i = 1; i < argc; i++)
		v_mergeMe.push_back(std::atoi(argv[i]));
	if (isSorted(v_mergeMe) == true)
    {
        printContainer(v_mergeMe, ERR_SORTED, "");
		throw Exception(errorMessage(ERR_SORTED)); // throw exception if already sorted
    }
}

// wrapper for the sorting & tracking of the performance
void	PmergeMe::v_sort(int argc, char **argv)
{
	clock_t start = clock();
	v_init(argc, argv);
	printContainer(v_mergeMe, VEC_TYPE, "before");
	v_mergeInsert(v_mergeMe.size(), 1);
	printContainer(v_mergeMe, VEC_TYPE, "after");
	if (isSorted(v_mergeMe) == false)
		throw Exception(errorMessage(ERR_NOT_SORTED));
	printResult(argc - 1, VEC_TYPE, clock() - start, comparisons - 1);
}
