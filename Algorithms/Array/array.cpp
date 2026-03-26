#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ArrayDSA
{
public:
    ArrayDSA &traverse(vector<int> &array)
    {
        cout << "Numbers in the list are: ";
        for (int number : array)
        {
            cout << number << " ";
        }
        cout << endl;
        return *this;
    }

    ArrayDSA &linearSearch(const vector<int> &array, int target)
    {
        bool found = false;

        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] == target)
            {
                cout << target << " is found at index " << i << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << target << " is not found in the array." << endl;
        }

        return *this;
    }

    ArrayDSA &linearMultiPosSearch(const vector<int> &array, int target)
    {
        vector<int> searchPlace;

        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] == target)
            {
                searchPlace.push_back(i);
            }
        }

        if (searchPlace.empty())
        {
            cout << target << " is not found in the array." << endl;
        }
        else
        {
            cout << target << " is found at positions: ";
            for (int index : searchPlace)
            {
                cout << index << " ";
            }
            cout << endl;
        }

        return *this;
    }

    ArrayDSA &binarySearchSingle(const vector<int> &array, int target)
    {
        int left = 0, right = array.size() - 1;
        bool found = false;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (array[mid] == target)
            {
                cout << target << " is found at index " << mid << endl;
                found = true;
                break;
            }
            else if (array[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (!found)
            cout << target << " is not found in the array." << endl;

        return *this;
    }

    ArrayDSA &binarySearchMulti(const vector<int> &array, int target)
    {
        int left = 0;
        int right = array.size() - 1;
        int foundIndex = -1;

        // Step 1: Find any one occurrence using binary search
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (array[mid] == target)
            {
                foundIndex = mid;
                break;
            }
            else if (array[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (foundIndex == -1)
        {
            cout << target << " is not found in the array." << endl;
            return *this;
        }

        // Step 2: Move left from foundIndex
        int i = foundIndex;
        cout << target << " is found at positions: ";
        while (i >= 0 && array[i] == target)
            i--;

        // Step 3: Move right from foundIndex
        i++;
        while (i < array.size() && array[i] == target)
        {
            cout << i << " ";
            i++;
        }

        cout << endl;
        return *this;
    }
};

int main()
{
    int n;
    vector<int> numbers = {};
    char action = 'y';
    ArrayDSA arrayDsa;

    cout << "Enter how many numbers you want to input: ";
    cin >> n;

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        numbers.push_back(value);
    }

    while (action != 'n' && action != 'N')
    {
        int option;
        cout << "\n1. Traverse\n2. Search\n3. Exit\nChoice: ";
        cin >> option;
        switch (option)
        {
        case 1:
            arrayDsa.traverse(numbers);
            break;
        case 2:
        {
            int searchValue;
            cout << "Enter the number to search for: ";
            cin >> searchValue;
            arrayDsa.linearMultiPosSearch(numbers, searchValue);
            break;
        }
      case 3:
        {
            sort(numbers.begin(), numbers.end());
            int value;
            cout << "Enter number to search: ";
            cin >> value;
            arrayDsa.binarySearchSingle(numbers, value);
            break;
        }

        case 4:
        {
            sort(numbers.begin(), numbers.end());
            int value;
            cout << "Enter number to search: ";
            cin >> value;
            arrayDsa.binarySearchMulti(numbers, value);
            break;
        }

        case 5:
            action = 'n';
            continue;

        default:
            cout << "Invalid option. Try again.\n";
        }

        cout << "Continue? (y/n): ";
        cin >> action;
    }

    return 0;
}
