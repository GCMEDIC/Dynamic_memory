#include <iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;


#define tab "\t"

//основа

template <typename T>T** Allocate(const int m, const int n);
template <typename T>void fillrand(T* arr, const int n);
template <typename T>void fillrand(T** arr, const int m, const int n);
template <typename T>void print(T arr[], const int n);
template <typename T>void print(T** arr, const int m, const int n);

//добавление элеметнов
template <typename T>T* push_back(T arr[], int& n, int value);
template <typename T>T* push_front(T arr[], int& n, int value);

//ну взял и удалил, чё бубнить то?
template <typename T>T* pop_back(T arr[], int& n);
template <typename T>T* pop_front(T arr[], int& n);
template <typename T>void Clear(T** arr, const int m);

/////////////////////////////////////////////////////////////////////
template <typename T>T** push_row_back(T** arr, int& m, const int n);//Добавление строки в конец массива
template <typename T>T** push_row_front(T** arr, int& m, const int n);//Добавление строки в начало массива
template <typename T>void push_col_back(T** arr, const int m, int& n);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2


void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;

	cout << "Введите размер массива: "; cin >> n;

	//Объявление динамического массива
	int* arr = new int[n];
	fillrand(arr, n);
	print(arr, n);
	int value;
	//значение добавляемое в массива

	//добавления значения в конец массива 
	cout << "Введите добавляемое значение в начале: "; cin >> value;
	arr = push_back(arr, n, value);
	print(arr, n);

	//добавление значения в начало массива
	cout << "введите добавляемое значение в конце: "; cin >> value;
	arr = push_front(arr, n, value);
	print(arr, n);

	//удаление значения с конца массива
	cout << "Удаление элемента с конца массива:\n";
	arr = pop_back(arr, n);
	print(arr, n);

	//удаления значения с начала массива
	cout << "Удаление элемента с начала массива:\n";
	arr = pop_front(arr, n);
	print(arr, n);

	delete[] arr;
	cout << "OUR JOURNEY TO VICTORY HAS JUST BEGUN!" << endl;
#endif //DYNAMIC_MEMORY_1

	/*fillrand(arr, n);
	print(arr, n);

	int brr[5];
	fillrand(brr, 5);
	print(brr, 5);

	delete[] arr;*/


#ifdef DYNAMIC_MEMORY_2
	int m; //количество строк
	int n; //количество столбцов
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество столбцов: "; cin >> n;

	/////////////////////////////////////////////////////////////////
	///////////////// ОБЪЯВЛЕНИЕ МАССИВА ////////////////////////////
	/////////////////////////////////////////////////////////////////

	double** arr = Allocate<double>(m, n);

	/////////////////////////////////////////////////////////////////
	///////////////// ИСПОЛЬЗОВАНИЕ МАССИВА /////////////////////////
	/////////////////////////////////////////////////////////////////

	cout << "Память выделена" << endl;
	system("PAUSE");
	fillrand(arr, m, n);
	print(arr, m, n);
	cout << "Добавляем строку в конец массива: " << endl;
	arr = push_row_back(arr, m, n);
	cout << "Строка добавлена" << endl;
	print(arr, m, n);
	cout << "Добавляем строку в начало массива" << endl;
	arr = push_row_front(arr, m, n);
	print(arr, m, n);
	
    //print(arr, m, n);

	/////////////////////////////////////////////////////////////////
	///////////////// УДАЛЕНИЕ МАССИВА //////////////////////////////
	/////////////////////////////////////////////////////////////////

	Clear(arr, m);

	cout << "I'm sorry! i don't speak japanese!";
#endif //DYNAMIC_MEMORY_2

	//1)создаём массив указателей:

}

template <typename T>void fillrand(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		// * - возвращает значения по адресу
		*(arr + i) = rand() % 100;
	}
}

template <typename T>void fillrand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

template <typename T>void print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// [] - оператор индексирования возвращает значение по индексу
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template <typename T>void print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

//взял и добавил, массива стал на 50% круче
template<typename T>T* push_back(T arr[], int& n, int value)
{
	//cout << sizeof(n) << endl;
	///////////////////////////////////////////////////////////
	////////////////// добавление значения в конец массива: ///
	///////////////////////////////////////////////////////////
	//1) Создать буферный массив нужного размера (на 1 элемент больше), это будет наш новый массив:
	T* buffer = new T[n + 1];
	//2) Копируем значения из исходного массива в буфферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
	//cout << typeid(arr).name() << endl;
	delete[] arr;
	//4) Подменяем адрес старого массива адресом нового массива 
	arr = buffer;
	// После этого в массиве 'arr' появился элемент, в который можно положить ещё одно значение 
	//5) Помещаем добавляемое значение в конец массива
	arr[n] = value;
	//6) После того как в массив добавился элемент, количество его элементов увеличилось на 1
	n++;
	//7) mission complete - значение добавлено
	return arr;
}

template<typename T>T* push_front(T arr[], int& n, int value)
{
	///////////////////////////////////////////////////////////
	///////////////// добавление значения в начало массива: ///
	///////////////////////////////////////////////////////////

	//следуем плану выше, только буффер [i+1]

	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

//ну удалил я и удалил, и что ты сделаешь?
template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}

template<typename T>T** push_row_back(T** arr, int& m, const int n)
{
	//1) создаём буфферный массив
	T** buffer = new T* [m + 1];
	//2) копируем адреса строк в новый массив
	for (int i = 0; i < m; i++)
		buffer[i] = arr[i];
	//3) Удаляем исходный массив указателей
	delete[] arr;
	//4) Создаём последнюю строку массива
	buffer[m] = new T[n] {};
	//5) Увеличиваем количество строк:
	m++;
	//6) возвращаем адрес нового массива на место вызова
	return buffer;
}
template<typename T>T** push_row_front(T** arr, int& m, const int n)
{
	T** buffer = new T*[m + 1];
	for (int i = 0; i < m; i++)
		buffer[i+1] = arr[i];
	delete[] arr;
	buffer[0] = new T [n] {};
	m++;
	return buffer;

}


template <typename T>T** Allocate(const int m, const int n)
{
	//1) Создаём массив указателей:
	T** arr = new T* [m];
	//2) Выделяем память под строки:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n] {};
	}
	return arr;
}

template <typename T>void Clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	//2) удаляем массив указателей:
	delete[] arr;
}

template<typename T>void push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		//1)Создаем буферную строку:
		T* buffer = new T[n + 1]{};
		//2)Копируем исходную строку массива в буферную:
		for (int j = 0; j < n; j++)buffer[j] = arr[i][j];
		//3)Удаляем исходную строку:
		delete[] arr[i];
		//4)Подменяем адрес в массиве указателей на адрес новой строки:
		arr[i] = buffer;
	}
	n++;
}