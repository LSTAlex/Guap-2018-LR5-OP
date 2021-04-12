#include  <iostream>
#include  <time.h>
#include  <stdlib.h>
#include  <conio.h>
#include  <crtdbg.h>
#define  _CRTDBG_MAP_ALLOC
#define  DBG_NEW  new  ( _NORMAL_BLOCK  ,    FILE      ,   LINE     )
#define  newDBG_NEW

using  namespace  std;  // подключение     пространства  имён  std

// функция  по выводу  массива
void  Mas(int  *arr,int  n,  int  nmax,  int  nmin)
{
srand(time(NULL));

// вывод   массива
cout  << "Массив:\n";	
for  (int  i = 0;  i < n;  i++)	
{	
	arr[i]  = rand  () %   201 +(-100);	
	cout  << "m["<<  i <<"]  = " << arr[i]  << "	" <<endl;
}	
cout  << "\n";	
}	

//функция  по нахождению  произведения отрицательных  элементов
void  negmult(int  *arr,  int  n,  int  negnum  )
{
//находим  произведение отрицательных  элементов
for  (int  i = 0;  i < n;  i++)
{
	if (arr[i]  < 0)
	negnum  += arr[i];
}
cout  << "Сумма  отрицательных  элементов  массиваровна:"  << negnum  << endl;
}

// функция  по нахождению  произведения элементов  между  мин.  и макс.
значением  массива
void  Multip(int  *arr,  int  n,  int  nmax,  int  nmin,  int  ii, int  jj, double mult)
{
// находим минимальный элемент массива
for  (int  i = 0;  i < n;  i++)
{ 
	if (arr[i]  < nmin)
	{
		nmin  = arr[i];
		jj = i; // индекс  минимального
	}
}

cout  << "Минимальный  элемент  m["  << jj << "] = " << nmin  << endl;

// находим  максимальный элемент  массива
for  (int  i = 0;  i < n;  i++)
{
	if (arr[i]  > nmax)
	{
		nmax  = arr[i];
		ii = i; // индекс максимального
	}
}

cout  << "Максимальный  элемент  m["  << ii << "] = " << nmax  << endl;

// произведение элементов между минимальным и максимальным  элементом
if (jj <  ii)
{
	for  (int  i = jj + 1;  i < ii; i++)
	mult  *=  arr[i];
}
else
{
for  (int  i = ii + 1;  i < jj; i++)
	mult  *=  arr[i];
}

cout  << "Произведение  элементов:  " << mult  << endl;
}

//функция  сортировки  массива  по возрастанию  (пузырьковая  сортировка)
void  sort(int  *arr,  int  n,  int  *Swap)
{
for  (int  i = 0;  i < n;  i++)
{
	for  (int  j = n - 1;  j >= i; j--)
	{
		if (arr[j  - 1]  > arr[j])
		{
			*Swap  = arr[j  - 1];
			arr[j  - 1]  = arr[j];
			arr[j]  = *Swap;
		} 
	}
}
cout  << "\n";
cout  << "Отсортированный  массив:\n";

// вывод отсортированного массива
for  (int  i = 0;  i < n;  i++)
{
	cout  << "m["  << i << "] = " << arr[i]   << "  " << endl;
}
delete[]  arr;  // очистка  памяти
delete[]  Swap;  // очистка  памяти
}

//функция  для ввода размера  массива
int  EnterN(void)
{
int n;
while  (true)
{
	cout  << "Введите  размер  массива:";
	cin  >> n;

	if (cin.fail())
	{
		cin.clear();
		cout  << "Введено  неверное значение.Введите  значение заново!";
	}
	else
	break;
}
return  n;
}

int  main()
{
setlocale(LC_ALL,  "Russian");

int  nmax  = 0 , nmin  = 0;
int  n = EnterN();
int  ii = 0,  jj = 0;  // переменные для хранения индексов значений
double  mult  = 1;  // переменная  для хнанения произведения
int  negnum  = 0;  //переменная  для хранения суммы  отрицательных  элементов
int  *Swap  = new  int[n];
int  *arr  = new  int [n];  // основной динамический  массив

Mas(arr,n,nmax,nmin);
negmult(arr,  n,  negnum);
Multip(arr,  n,  nmin,  nmax,  ii, jj, mult); 
sort(arr,  n,Swap);



// Для обнаружения  утечек памяти
_CrtSetReportMode(  _CRT_WARN,  _CRTDBG_MODE_FILE  );
_CrtSetReportFile(  _CRT_WARN,  _CRTDBG_FILE_STDOUT  );
CrtSetReportMode(  _CRT_ERROR,  _CRTDBG_MODE_FILE  );
_CrtSetReportFile(  _CRT_ERROR,  _CRTDBG_FILE_STDOUT  );
_CrtSetReportMode(  _CRT_ASSERT,  _CRTDBG_MODE_FILE  );
_CrtSetReportFile(  _CRT_ASSERT,  _CRTDBG_FILE_STDOUT  );
_CrtDumpMemoryLeaks();
system("pause");
return  0;
} 
