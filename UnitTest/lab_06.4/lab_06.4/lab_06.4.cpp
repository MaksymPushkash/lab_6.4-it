#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>    
#include <cstdlib>  
#include <ctime>    

void generateArray(std::vector<double>& arr, int n, double minVal, double maxVal)
{
    for (int i = 0; i < n; i++)
    {
        double randVal = minVal + static_cast<double>(rand()) / RAND_MAX * (maxVal - minVal);
        arr[i] = randVal;
    }
}

void printArray(const std::vector<double>& arr)
{
    for (const double& elem : arr)
    {
        std::cout << std::setw(10) << elem;
    }
    std::cout << std::endl;
}

int findMinModIndex(const std::vector<double>& arr)
{
    int minIndex = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (std::abs(arr[i]) < std::abs(arr[minIndex]))
        {
            minIndex = i;
        }
    }
    return minIndex;
}

double sumAfterFirstNegative(const std::vector<double>& arr)
{
    bool foundNegative = false;
    double sum = 0.0;
    for (const double& elem : arr)
    {
        if (foundNegative)
        {
            sum += std::abs(elem);
        }
        if (elem < 0 && !foundNegative)
        {
            foundNegative = true;
        }
    }
    return sum;
}

void compressArray(std::vector<double>& arr, double a, double b)
{
    int newSize = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (!(arr[i] >= a && arr[i] <= b))
        {
            arr[newSize++] = arr[i];
        }
    }
    for (int i = newSize; i < arr.size(); i++)
    {
        arr[i] = 0;
    }
}

int main()
{
    srand(time(0));

    int n;
    double a, b, minVal, maxVal;

    std::cout << "������ ������� �������� ������: ";
    std::cin >> n;

    std::cout << "������ �������� � ����������� �������� ��� ��������� �����: ";
    std::cin >> minVal >> maxVal;

    std::vector<double> arr(n);

    generateArray(arr, n, minVal, maxVal);

    std::cout << "���������� �����: " << std::endl;
    printArray(arr);

    int minModIndex = findMinModIndex(arr);
    std::cout << "������ ���������� �� ������ ��������: " << minModIndex << std::endl;

    double sum = sumAfterFirstNegative(arr);
    std::cout << "���� ������ �������� ���� ������� ��'������: " << sum << std::endl;

    std::cout << "������ a �� b (�������� ��� ���������): ";
    std::cin >> a >> b;

    compressArray(arr, a, b);

    std::cout << "������������� ����� ���� ���������: " << std::endl;
    printArray(arr);

    return 0;
}
