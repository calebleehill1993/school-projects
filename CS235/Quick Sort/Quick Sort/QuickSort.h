#ifndef QUICKSORT_H_
#define QUICKSORT_H_
#include <string>
#include "QSInterface.h"
#include <sstream>
using namespace std;

template<typename T>
class QuickSort : public QSInterface<T>
{
private:
	size_t c;
	size_t s;
	T* start;
	T* end;
public:
	QuickSort() {c = 0; s = 0; }
	~QuickSort() { delete start; }

	/** Dynamically allocate an initial array to the QuickSort class. */
	bool createArray(size_t capacity) 
	{
		c = capacity;
		T* pointer = new T[capacity];
		s = 0;
		delete start;
		start = pointer;
		return 0;
	};

	void reallocate(size_t capacity)
	{
		c = capacity;
		T* pointer = new T[capacity];
		if (s > capacity)
		{
			s = capacity;
		}
		for (size_t i = 0; i < s; i++)
		{
			pointer[i] = start[i];
		}
		delete start;
		start = pointer;
	};

	/** Add an element to the QuickSort array. Dynamically grow array as needed. */
	bool addElement(T element)
	{ 
		if (s == c)
		{
			reallocate(c * 2);
		}
		start[s] = element;
		s++;
		return 0;
	};

	/** Sort the elements of a QuickSort subarray using median and partition functions. */
	bool sort(size_t left, size_t right) { return 0; };

	/** Sort all elements of the QuickSort array using median and partition functions. */
	bool sortAll() { return 0; };

	/** Removes all items from the QuickSort array. */
	bool clear() 
	{ 
		for (size_t i = 0; i < s; i++)
		{
			start[i] = NULL;
		}
		s = 0;
		return 0; 
	};

	/** Return size of the QuickSort array. */
	size_t capacity() const { return c; };

	/** Return number of elements in the QuickSort array. */
	size_t size() const { return s; };

	/** The median of three pivot selection has two parts:
	1) Calculates the middle index by averaging the given left and right indices:
	middle = (left + right)/2
	2) Then bubble-sorts the values at the left, middle, and right indices.

	After this method is called, data[left] <= data[middle] <= data[right].

	@param left - the left boundary for the subarray from which to find a pivot
	@param right - the right + 1 boundary for the subarray from which to find a pivot
	@return the index of the pivot (middle index).
	Return -1 if	1) the array is empty,
	2) if either of the given integers is out of bounds,
	3) or if the left index is not less than the right index.
	*/
	int medianOfThree(size_t left, size_t right)
	{
		if (s < 1)
		{
			return -1;
		}
		if (left < 0 || right < 0 || s < right || s < left)
		{
			return -1;
		}
		if (right - 1 <= left)
		{
			return -1;
		}
		int middle = (left + right) / 2;
		right = right - 1;
		if (start[left] > start[middle]) swap(start[left], start[middle]);
		if (start[middle] > start[right])
		{
			swap(start[middle], start[right]);
			if (start[left] > start[middle]) swap(start[left], start[middle]);
		}
		return  middle;
	};

	/** Partitions a subarray around a pivot value selected according
	to median-of-three pivot selection. Because there are multiple ways
	to partition a list, follow the algorithm on page 611.

	The values which are smaller than the pivot should be placed to the left of the pivot;
	the values which are larger than the pivot should be placed to the right of the pivot.

	@param left - left index for the subarray to partition.
	@param right - right index + 1 for the subarray to partition.
	@param pivotIndex - index of the pivot in the subarray.
	@return the pivot's ending index after the partition completes:
	Return -1 if	1) the array is empty,
	2) if any of the given indexes are out of bounds,
	3) if the left index is not less than the right index.
	*/
	int partition(size_t left, size_t right, size_t pivotIndex)
	{
		int middle = medianOfThree(left, right);
		if (middle == -1) return -1;
		swap(start[left], start[middle]);
		size_t up = left + 1;
		size_t down = right - 1;
		do
		{
			while ((start[up] <= start[left]) && (up != (right - 1))) 
			{ 
				up++;
			}
			while ((start[down] > start[left]) && (down != left))
			{
				down--;
			}
			if (up < down) swap(start[up], start[down]);
		} while (up < down);
		swap(start[left], start[down]);
		return down;
	};

	/** @return: comma delimited string representation of the array. */
	std::string toString() const
	{
		if (s > 0)
		{
			stringstream out;
			out << start[0];
				for (size_t i = 1; i < s; i++)
				{
					out << "," << start[i];
				}
			return out.str();
		}
		return "Empty";
	};
};

#endif /* QUICKSORT_H_ */