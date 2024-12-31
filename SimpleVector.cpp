#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* Data;
	int CurrentSize;
	int CurrentCapacity;

public:
	// �⺻ ������
	SimpleVector() : CurrentSize(0), CurrentCapacity(10)
	{
		Data = new T[10]();
	}

	// �Ű������� �޴� ������
	SimpleVector(int Capacity) : CurrentSize(0), CurrentCapacity(Capacity)
	{
		Data = new T[CurrentCapacity]();
	}

	// ���� ������
	SimpleVector(const SimpleVector& Other) : CurrentSize(Other.CurrentSize), CurrentCapacity(Other.CurrentCapacity)
	{
		Data = new T[CurrentCapacity];
		for (int i = 0; i < CurrentSize; ++i)
		{
			Data[i] = Other.Data[i];
		}
	}

	// �Ҹ���
	~SimpleVector()
	{
		delete[] Data;
	}

	// ������ ����
	void push_back(const T& Value)
	{
		// ���� �迭�� ũ�Ⱑ �뷮�� ���ٸ�
		if (CurrentSize == CurrentCapacity)
		{
			CurrentCapacity += 5;
			T* Temp = new T[CurrentCapacity]; // ���� �뷮�� +5�� �뷮�� ���� ���� �迭 ����
			for (int i = 0; i < CurrentSize; ++i) // ���� ������ ����
			{
				Temp[i] = Data[i];
			}
			delete[] Data; // ���� ���� �迭 ����

			Data = Temp; // �뷮 ���� ��Ų ���� �迭 �ּ� ����
		}

		Data[CurrentSize] = Value;
		CurrentSize++;
	}
	
	// ������ ��� ����
	void pop_back()
	{
		if (CurrentSize > 0)
		{
			--CurrentSize;
		}
	}

	// ���� �迭 ũ�� ��ȯ
	int size() { return CurrentSize; }

	// ���� �迭 �뷮 ��ȯ
	int capacity() { return CurrentCapacity; }

	// �迭 �뷮 �缳��
	void resize(int ResizeCapacity)
	{
		if (ResizeCapacity < CurrentCapacity) return;

		CurrentCapacity = ResizeCapacity;
		T* Temp = new T[CurrentCapacity];
		for (int i = 0; i < CurrentSize; ++i)
		{
			Temp[i] = Data[i];
		}
		delete[] Data;

		Data = Temp;
	}

	// ��ü ������ ���
	void PrintData()
	{
		for (int i = 0; i < CurrentSize; ++i)
		{
			cout << Data[i] << " ";
		}
	}

	// ������ ����
	void sortData(bool ascending = true)
	{
		if (ascending)
		{
			sort(Data, Data + CurrentSize);
		}
		else
		{
			sort(Data, Data + CurrentSize, greater<T>());
		}
	}
};