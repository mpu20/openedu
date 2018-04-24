// Anti-Quicksort

// Хотя QuickSort является очень быстрой сортировкой в среднем, существуют тесты, 
// на которых она работает очень долго. Оценивать время работы алгоритма будем числом 
// сравнений с элементами массива (то есть, суммарным числом сравнений в первом и 
// втором while). Требуется написать программу, генерирующую тест, на котором быстрая 
// сортировка сделает наибольшее число таких сравнений.

// Формат входного файла
// В первой строке находится единственное число n(1<=n<=10^6) .

// Формат выходного файла
// Вывести перестановку чисел от 1 до n, на которой быстрая сортировка выполнит 
// максимальное число сравнений. Если таких перестановок несколько, вывести любую из них.


#include <fstream>


void antiqucksort(int n)
{
    std::ofstream fout("output.txt");
    
    if (n == 1) {
        fout << "1\n";
        return;
    }
    
    int *a = new int [n];
    a[0] = 1;
    a[1] = 2;
    
    int buff;
    
    for (int i = 2; i < n; ++i) {
        a[i] = i + 1;
        buff = a[i / 2];
        a[i / 2] = a[i];
        a[i] = buff;
    }
    
    for (int i = 0; i < n; i++)
        fout << a[i] << " ";
    fout << "\n";
    
    delete [] a;
}


int main()
{
    std::ifstream fin("input.txt");
    
    int n;
    fin >> n;
    
    antiqucksort(n);
    
    return 0;
}
