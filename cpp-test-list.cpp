// Программа написана в рамках тестового задания. 
// Основные фунции: 
// - ввод списка;
// - ввод вектора; 
// - генерация вектора из списка и наоборот; 
// - объединение двух списков в один с сортировкой и удалением дублей.

#include <iostream>
#include <list>
#include <vector>

using namespace std;

list<int> list1;
list<int> list2;
vector <int> vector1;
vector <int> vector2;

int main()
{
    setlocale(LC_ALL, "rus"); // локализация русского текста

    // Ввод списка


    int n; // Количество элементов
    int k; // Сам элемент
    cout << "Введите количество элементов для Списка 1" << endl;
    cin >> n;   // сколько нужно ввести элементов в последовательность для списка

    // Ввод элементов списка через цикл
    for (int i = 1; i <= n; i++) {
        cout << i << endl;
        cin >> k;
        list1.push_back(k);
    }


    // Конвертация списка 1 в вектор 1
    vector <int> vector1{ begin(list1), end(list1) };

    // Определение размера списка 1
    int size_list1 = list1.size();

    cout << "Размер Списка1 составляет: " << size_list1 << " элементов" << endl;
    int i = 1;

    // Вывод списка через перебор с помощью итераторов
    for (auto iter = list1.begin(); iter != list1.end(); iter++)
    {

        cout << "Элемент номер " << i << ":\t" << *iter << endl; // \t - табуляция
        i++;
    }
    cout << endl;


    // Вывод вектора 1
    int size_vector1 = vector1.size();

    cout << "Размер Вектора1 составляет: " << size_vector1 << " элементов" << endl; // изменить на пересчет реального размера

    // Вывод содержимого вектора 1

    for (vector<int>::iterator it = vector1.begin(); it != vector1.end(); ++it)
        cout << *it << "\t";
    cout << endl;

    // Конец

    // Конвертация вектора 2 в список и вывод

    n = 0;
    char answ;

    cout << "Желаете ли вы ввести вектора 2 ? (y/n)" << endl;
    cin >> answ;


    if (answ == 'y' or answ == 'Y') {

        cout << "Введите количество элементов для Вектора 2" << endl;
        cin >> n;   // сколько нужно ввести элементов в последовательность

        // Ввод элементов вектора через цикл
        for (int i = 1; i <= n; i++) {
            cout << i << endl;
            cin >> k;
            vector2.push_back(k);
        }

        // Конвертация  вектор 2 в списка 2
        list <int> list2(vector2.begin(), vector2.end());

        // Определение размера списка 2
        int size_list2 = list2.size();

        cout << "Размер Списка2 составляет: " << size_list2 << " элементов" << endl;

        int i = 1;

        // Вывод списка через перебор с помощью итераторов
        for (auto iter = list2.begin(); iter != list2.end(); iter++)
        {

            cout << "Элемент номер " << i << ":\t" << *iter << endl; // \t - табуляция
            i++;
        }
        cout << endl;


        // Сортировка и объединение списков

        answ = 0;
        i = 0;

        cout << "Желаете ли вы объединить списки и отсортировать ? (y/n)" << endl;
        cin >> answ;

        if (answ == 'y' or answ == 'Y') {

            //Объединение списков
            list1.insert(list1.end(), list2.begin(), list2.end());
            //Сортировка списка
            list1.sort();
            list1.unique();

            cout << "Вывод объединенного списка." << endl;

            // Вывод списка через перебор с помощью итераторов
            for (auto iter = list1.begin(); iter != list1.end(); iter++)
            {
                cout << "Элемент номер " << i << ":\t" << *iter << endl; // \t - табуляция
                i++;
            }
            cout << endl;
        }
        else if (answ == 'n' or answ == 'N') {
            cout << "Завершение работы." << endl;
        }
        else {
            cout << "Ответ не распознан." << endl;
        }

    }
    else if (answ == 'n' or answ == 'N') {
        cout << "Завершение работы." << endl;
    }
    else {
        cout << "Ответ не распознан." << endl;
    }

    return 0;
}