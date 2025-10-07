#ifndef LIST_HPP
#define LIST_HPP
#include <vector>
template <typename T>
void Reverse(std::vector<T> &arr, int left, int right)
{
    if (left < 0 || left >= right || right >= arr.size())
        return;
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; i++)
        std::swap(arr[left + i], arr[right - i]);
}

template <typename T>
void Exchange(std::vector<T> &arr, int m, int n)
{
    if (m < 0 || n < 0 || m >= arr.size() || n >= arr.size())
        return;
    Reverse(arr, 0, arr.size() - 1);
    Reverse(arr, 0,n - 1);
    Reverse(arr, n, arr.size() - 1);
}



#endif