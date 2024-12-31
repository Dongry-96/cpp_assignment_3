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
	// 기본 생성자
	SimpleVector() : CurrentSize(0), CurrentCapacity(10)
	{
		Data = new T[10]();
	}

	// 매개변수를 받는 생성자
	SimpleVector(int Capacity) : CurrentSize(0), CurrentCapacity(Capacity)
	{
		Data = new T[CurrentCapacity]();
	}

	// 복사 생성자
	SimpleVector(const SimpleVector& Other) : CurrentSize(Other.CurrentSize), CurrentCapacity(Other.CurrentCapacity)
	{
		Data = new T[CurrentCapacity];
		for (int i = 0; i < CurrentSize; ++i)
		{
			Data[i] = Other.Data[i];
		}
	}

	// 소멸자
	~SimpleVector()
	{
		delete[] Data;
	}

	// 데이터 삽입
	void push_back(const T& Value)
	{
		// 현재 배열의 크기가 용량과 같다면
		if (CurrentSize == CurrentCapacity)
		{
			CurrentCapacity += 5;
			T* Temp = new T[CurrentCapacity]; // 현재 용량에 +5의 용량을 가진 동적 배열 생성
			for (int i = 0; i < CurrentSize; ++i) // 기존 데이터 복사
			{
				Temp[i] = Data[i];
			}
			delete[] Data; // 기존 동적 배열 삭제

			Data = Temp; // 용량 증가 시킨 동적 배열 주소 저장
		}

		Data[CurrentSize] = Value;
		CurrentSize++;
	}
	
	// 마지막 요소 삭제
	void pop_back()
	{
		if (CurrentSize > 0)
		{
			--CurrentSize;
		}
	}

	// 현재 배열 크기 반환
	int size() { return CurrentSize; }

	// 현재 배열 용량 반환
	int capacity() { return CurrentCapacity; }

	// 배열 용량 재설정
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

	// 전체 데이터 출력
	void PrintData()
	{
		for (int i = 0; i < CurrentSize; ++i)
		{
			cout << Data[i] << " ";
		}
	}

	// 데이터 정렬
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