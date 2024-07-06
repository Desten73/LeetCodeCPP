// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        auto num = nums.begin();
        short res = 1;
        for (auto i : nums)
            if (i != *num)
            {
                ++num;
                *num = i;
                ++res;
            }
        return res;
    }

    int maxProfit(std::vector<int>& prices) {
        int res = 0;
        for (auto firstNum = prices.begin(); firstNum < --prices.end(); ++firstNum)
        {
            auto secondNum = firstNum + 1;
            if (*firstNum < *secondNum)
                res += *secondNum - *firstNum;
        }
        return res;
    }

    void rotate(std::vector<int>& nums, int k) {
            std::rotate(nums.begin(), nums.begin() + (nums.size() - k% nums.size()), nums.end());
    }

    bool containsDuplicate(std::vector<int>& nums) {
        std::set<int> s;
        for (int i = 0; i < nums.size(); ++i)
        {
            s.insert(*(nums.begin() + i));
            if (s.size() == i)
                return true;

        }
        return false;
    }

    int singleNumber(std::vector<int>& nums) {
        unsigned res = 0;
        for (const auto &num : nums)
            res ^= num;
        return res;
    }

    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> nums3;

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::set_intersection(nums1.begin(), nums1.end(),
            nums2.begin(), nums2.end(),
            back_inserter(nums3));
        return nums3;
    }

    std::vector<int> plusOne(std::vector<int>& digits) {
        auto it = digits.end() - 1;
        while (it >= digits.begin())
        {
            if ((*it) == 9)
            {
                *it = 0;
                if (it == digits.begin())
                    break;
                --it;
            }
            else
            {
                ++(*it);
                return digits;
            }
        }
        if (*digits.begin() == 0)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }

    void moveZeroes(std::vector<int>& nums) {
        auto itFirst = nums.begin();
        auto itSecond = nums.begin();
        while (itFirst != nums.end())
        {
            if (*itFirst != 0)
            {
                *itSecond = std::move(*itFirst);
                ++itSecond;
            }
            ++itFirst;
        }
        while (itSecond != nums.end())
        {
            *itSecond = 0;
            ++itSecond;
        }
    }

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i)
            for (int ii = i + 1; ii < size; ++ii)
                if (nums[i] + nums[ii] == target)
                    return std::vector<int>{i, ii};
        return std::vector<int>();
    }

    int binary_search(std::vector<int>& nums, int key)
    {
        bool flag = false;
        int l = 0;
        int r = nums.size()-1;
        int mid;

        while ((l <= r) && (flag != true)) {
            mid = (l + r) / 2;

            if (nums[mid] == key) {
                flag = true;
                break;
            } 
            if (nums[mid] > key) 
                r = mid - 1; 
            else 
                l = mid + 1;
        }

        if (flag) 
            return mid;
        else 
            return 0;
    }


    bool threeConsecutiveOdds(std::vector<int>& arr) {
        for (auto it1 = arr.begin(), it2 = arr.begin() + 1, it3 = arr.begin() + 2; it1 < arr.end() - 2; ++it1, ++it2, ++it3)
        {
            if ((*it1 % 2) && (*it2 % 2) && (*it3 % 2) & 1)
            {
                std::cout << " nums = " <<  " " << *it1 << " " << *it2 << " " << *it3;
                return true;
            }
        }
        return false;
    }

    void rotate(std::vector<std::vector<int>>& matrix) {
    }
};

int main()
{
    std::cout << "Hello World!\n";
    std::vector<int> vect{ 3, 2, 4 };
    std::vector<int> vect2{ 0, 1, 3, 4 };

    Solution sol;
    std::vector<int> ve = sol.twoSum(vect, 6);
    //std::cout << "\nres = " << sol.threeConsecutiveOdds(vect);

    
    for (int i : ve)
    {
        std::cout << " " << i;
    }
    /*
    std::cout << "\n";
    for (int i : vect2)
    {
        std::cout << " " << i;
    }
    std::cout << "\n";
    for (int i : ve)
    {
        std::cout << " " << i;
    }
    */
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
