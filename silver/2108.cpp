#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int coordinate[500001];
int cnt[8001]; // -4000 ~ 4000
int N, sum = 0;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> coordinate[i];
		sum += coordinate[i];
		cnt[coordinate[i]+4000]++;
	}
	
	sort(coordinate, coordinate + N);
	
	int mostval;
	int max = 0;
	
	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
			mostval = i;
		}
	}

	for (int i = mostval + 1; i < 8001; i++) // 두번째 최빈값
	{
		if (cnt[i] == max)
		{
			mostval = i;
			break;
		}
	}

	cout << (int)round(double(sum) / N) << "\n";
	cout << coordinate[(N - 1) / 2] << "\n";
	cout << mostval - 4000 << "\n";
	cout << coordinate[N - 1] - coordinate[0] << "\n";
}