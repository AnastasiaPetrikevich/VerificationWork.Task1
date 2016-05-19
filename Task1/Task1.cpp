#include <iostream>
#include <fstream>

using namespace std;

const int N = 256;

void ShowContentsFile(char*);
int ContentsFile(char*);
int* InitArray(char*, int);
int* MergeArrays(int*, int, int*, int, int&);
void DisplayArray(int*, int);
void CreateFile(char*, int*, int);

int main()
{
	char fileNameFirst[N], fileNameSecond[N];
	cout << "Please, enter the name of source files: " << endl;
	cout << "1st file: ";
	cin.getline(fileNameFirst, N, '\n');
	cout << "2nd file: ";
	cin.getline(fileNameSecond, N, '\n');
	char fileNameNew[N];
	cout << "Please, enter the name of result file: " << endl;
	cin.getline(fileNameNew, N, '\n');
	system("cls");

	cout << "Sourse files: " << endl;
	ShowContentsFile(fileNameFirst);
	ShowContentsFile(fileNameSecond);

	int n, m, l = 0;
	n = ContentsFile(fileNameFirst);
	m = ContentsFile(fileNameSecond);
	int* a = InitArray(fileNameFirst, n);
	int* b = InitArray(fileNameSecond, m);
	int* c = MergeArrays(a, n, b, m, l);
	cout << "New array: " << endl;
	DisplayArray(c, l);
	cout << endl;
	CreateFile(fileNameNew, c, l);
	system("pause");
	system("cls");

	return 0;
}

void ShowContentsFile(char* fileName)
{
	ifstream streamIn;
	streamIn.open(fileName);
	if (!streamIn.is_open())
	{
		cout << " Cannot open file " << fileName << " to read!" << endl;
		system("pause");
		exit(1);
	}
	char string[N] = "";
	while (!streamIn.eof())
	{
		streamIn.getline(string, N, '\n');
		cout << string << endl;
	}
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int count = 0, term;
	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}

int* MergeArrays(int* a, int n, int* b, int m, int& l)
{
	l = n + m;
	int* c = new int[l];
	int i = 0, j = 0, k = 0;
	for (; i < n && j < m; k++)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
	}
	if (i == n)
		for (; j < m; j++, k++)
			c[k] = b[j];
	else
		for (; i < n; i++, k++)
			c[k] = a[i];
	return c;
}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
}

void CreateFile(char* fileName, int* arr, int n)
{
	ofstream streamOut(fileName);
	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}
	int temp;
	for (int i = 0; i < n; i++)
	{
		temp = arr[i];
		streamOut << temp << " ";
	}
	streamOut.close();
}