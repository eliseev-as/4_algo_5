#include <iostream>
#include <sstream>
using namespace std;

// Получить максимальное произведение последовательности из k элементов
long getMaxProduct(vector<int> numbers, int k) {
    // Сортируем вектор чисел по возрастанию
    ranges::sort(numbers);

    // Максимальное произведение последовательности
    long product = 1;

    // Размер последовательности
    const unsigned long size = numbers.size();

    for (auto i = size - 1; i >= size - k; i--)
        product *= numbers[i];
    return product;
}

// Преобразовать вектор чисел к строке
string toString(vector<int> numbers) {
    stringstream ss;
    ranges::copy(numbers, ostream_iterator<int>(ss, ", "));
    const string s = ss.str();
    return s.substr(0, s.length() - 2);
}

int main() {
    const vector<int> numbers1 = {-1, -7, 0, -2, -8, -5, -3};
    int k1 = 3;
    cout << format("Максимальное произведение последовательности {} из {} элементов = ", toString(numbers1), k1) <<
            getMaxProduct(numbers1, k1) << endl;

    const vector<int> numbers2 = {1, 7, 0, 2, 8, 5, 3};
    int k2 = 3;
    cout << format("Максимальное произведение последовательности {} из {} элементов = ", toString(numbers2), k2) <<
            getMaxProduct(numbers2, k2) << endl;

    const vector<int> numbers3 = {-1, -7, -2, -8, -5, -3};
    int k3 = 3;
    cout << format("Максимальное произведение последовательности {} из {} элементов = ", toString(numbers3), k3) <<
            getMaxProduct(numbers3, k3) << endl;

    return 0;
}
