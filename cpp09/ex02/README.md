# Ford&Johnson Merge-Insertion Sort

_aka the 'why am i doing this to myself again?'-sort_

## introduction

the **Ford&Johnson Merge-Insertion Sort** is a sophisticated algorithm designed to sort a list of elements more efficiently than traditional methods.
it was developed with the goal of _minimizing the number of comparisons required_ to sort a list, it combines the principles of **merge sort** & **insertion sort**, leading to 
improved performance especially on small or partially sorted datasets.

## how the algorithm works

### initial pair sorting

the algorithm begins by sorting adjacent pairs of elements throughout the list. 

```cpp
	for (int i = 0; i < elemCount - 1; i += 2)
	{
		it first = it + i * elemSize;
		it second = it + (i + 1) * elemSize;

		if (*first < *second) // swap the pair if out of order
			std::swap_ranges(first, second, second);
	}
```

this step ensures that the elements are partially ordered, which is crucial for the **efficient merging and insertion** that follows.

### division into top and bottom sequences

the algorithm divides the sorted pairs into two containers, v_top and v_bottom, based on their position, to streamline the merge-insertion process.

```cpp
	for (int i = 0; i < elemCount; ++i)
	{
		if (i == elemCount - 1 || i % 2 == 1)
			bottom.insert(v_bottom.end(), it + i * elemSize, it + (i + 1) * elemSize);
		else if (i % 2 == 0)
			top.insert(v_top.end(), it + i * elemSize, it + (i + 1) * elemSize);
	}
```

### binary search and insertion

for inserting elements from bottom into top, the algorithm uses a binary search to find the correct insertion point, minimizing comparisons.

```cpp
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (top[mid * elemSize] < *bottom_it)
			left = mid + 1;
		else
			right = mid - 1;
	}
	top.insert(top_it + left * elemSize, bottom_it, bottom_it + elemSize);
```

### recursive sorting

the sorting process is applied recursively to subsets of the dataset, enhancing the algorithm's efficiency through a divide-and-conquer approach.

```cpp
	if (elemCount == 1)
		return; // base case - a single element is already sorted
	top, bottom; // temporary containers for holding elements during the sorting process
	v_sortPairs(elemCount, elemSize); // initial pair sorting
	v_mergeInsert(elemCount / 2, elemSize * 2); // recursive call for sorting smaller subsets
	v_insert(elemCount, elemSize, top, bottom); // merge & insert sorted elements
```

## complexity analysis

### general analysis

the Ford&Johnson Merge-Insertion Sort improves upon the time-complexity of traditional insertion sort methods. by reducing the numver of comparisons through initial pair sorting and binary search-based insertion, it achieves better efficiency, especially in small or partially sorted lists.
the exact time complexity varies based on the implementation and the dataset characteristics, but it generally offers a middle ground between _O(n log n)_ and _O(n^2)_ (usually closer to the former for most practical purposes).

this efficiency comes at the cost of increased space complexity due to the need for additional data structures to hold the divided elements during the sorting process.

### vector vs. deque

#### memory allocation

*   **vector:** a vector allocates memory in contiguous blocks. when it runs out of space, it needs to:
1.  allocate a larger block of memory
2.  copy the existing elements into the new block
3.  free the old block
->  expensive reallocations.

*   **deque:** a deque (double-ended queue) allocates memory in chunks or blocks of a fixed size, which are not necessarily contiguous.
-> faster reallocation without always copying the entire data structure as often as a vector.
#### element access

*   **vector:** provides constant-time (_O(n)_) access thanks to contiguous memory allocation.

*   **deque:** while still efficient, a deque has slower element access than a vector due to having to navigate through multiple blocks of memory to reach a particular element.

##### efficiency impact

if your algorithm frequently accesses elements randomly **(aka data_structure[i])**, a vector is more performant than a deque.

#### insertions and removals

*   **vector:** insertions and removals at positions other than the end of the vector are costly because they require moving all subsequent elements to maintain contiguity.

*   **deque:** designed to allow efficient insertions and removals at both the beginning and the end; insertions in the middle can still require moving elements, but they are less costly due to the deque's segmented nature.

#### small lists: why deque performs better

1.  **low overhead on small operations:** for small lists, the benefits of contiguous memory access that a vector offers do not outweigh the overhead of dynamic memory allocations (which is more frequent and complex for a vector due to its need for contiguous memory space).

2.  **efficient insertion and deletion:** early stages of the Ford&Johnson algorithm involve a lot of insertions and deletions. a deque is optimized for fast back & front insertions, which makes it less costly particularly for small lists.

#### large lists: why vector outperforms deque

1.  **memory allocation and access patterns:**  as lists grow, the benefits of contiguous memory allocation begin to outweigh its costs. a vector benefits from data locality, which improves cache utilization when accessing elements sequentially during sorting. this _significantly_ speeds up comparisons & swap operations, making vector much faster for large lists.

2.  **amortized costs of reallocation:** while vectors are costly when growing, this cost is amortized over the many insertions that occur between reallocations. as the size of the list increases, the impact of reallocation decreases relative to the overall operation count.

3.  **inserition efficiency:** although deque is designed for efficient insertions and deletions at its ends, insertions in the middle or near the middle (which are very common in sorting algorithms), can be slower. this is because even though a deque does not need to shift all of its elements like a vector does, it may need to move a significant amount of elements within or across the different blocks of memory it is storing them in - thus decreasing its advantage in insertion/deletion operations compared to the speed of accessing elements in a vector.

4.  **compiler and library optimizations:** many standard library implementations include very optimized versions of vectors due to their widespread use and simpler memory model.


## advantages & disadvantages

### advantages

*   **reduced comparisons:** by using binary search for insertions, the algorithm significantly reduces the number of comparisons needed for sorting.
*   **improved efficiency:** for certain datasets, especially small or nearly sorted, this algorithm can be more efficient than traditional ones.

### disadvantages

*   **complex implementation:** the algorithm's complexity makes it very challenging to understand and implement. (lol)
*   **increased space complexity:** the need for additional data structures increases the algorithm's space requirements.