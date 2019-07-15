//Find the common elements of 2 int arrays
//Implement binary search of a sorted array of integers
#include <iostream>
#include <vector>
#include <algorithm>


int binSearch(std::vector<int> small, int search)			//given sorted array, search for int
{
	int first = 0;					//first is element 0
	int last = small.size() - 1;		//last is last element
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;		//mid is middle element
		if (small[mid] == search)	//if the middle element is the searched element, return it
		{
			return small[mid];
		}
		else if (small[mid] > search)		//if the middle element is greater, it would be in the left half
		{
			last = mid - 1;			//set the "last" element to the mid-1 element so search only the left half next
		}
		else//if the middle element is less, then it is in the right half
		{
			first = mid + 1;		//set the first element to the beginning of the right half
		}

	}
	return -1;		//if not found, return -1
}
void checkIntersection(std::vector <int> first, std::vector<int> second)
{
	std::vector <int> intersect;
	std::vector <int> smaller; 
	std::vector <int> larger;
	if (first.size() < second.size())				//find the smaller array
	{
		smaller = first;
		larger = second;
	}
	else
	{
		smaller = second;
		larger = first;
	}
	sort(smaller.begin(), smaller.end());			//sort the smaller array
	for (int i = 0; i < larger.size(); i++)
	{
		if (binSearch(smaller, larger[i]) != -1)		//if the bin search is not -1, i.e. if the element is found in the smaller array from larger array, add it to the intersection
		{
			intersect.push_back(larger[i]);
		}
	}
	std::cout << "number of common elements: " << intersect.size() << std::endl;
	if (intersect.size() > 0)
	{
		std::cout << "common elements: ";
		for (int i = 0; i < intersect.size(); i++)
		{
			std::cout << intersect[i] << " ";
		}
	}
}




std::vector<int> populateArr(int size, int num)
{
	std::vector <int> tempArr;
	for (int i = 0; i < size; i++)
	{
		int temp;
		std::cout << "enter element " << i + 1 << " of array " <<  num<< std::endl;
		std::cin >> temp;
		tempArr.push_back(temp);
	}
	return tempArr;
}

int main()
{
	int size1;
	int size2;
	char repeat;
	do
	{
		std::vector<int> arr1;
		std::vector<int> arr2;
		std::cout << "enter size of array 1" << std::endl;
		std::cin >> size1;
		std::cout << "enter size of array 2" << std::endl;
		std::cin >> size2;
		arr1 = populateArr(size1, 1);
		arr2 = populateArr(size2, 2);
		checkIntersection(arr1, arr2);
		std::cout << std::endl;
		std::cout << "run again?" << std::endl;
		std::cin >> repeat;
	} while (repeat == 'y' || repeat == 'Y');

}

//2for1 binary search and common elements