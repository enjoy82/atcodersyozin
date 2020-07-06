#include <stdio.h>
#include <string.h>
#include <algorithm>

int b[2][3], c[3][2];
int sum, temp[9], ans;

int f(int n, int a[]) {
	if (n == 9)
	{
		int res = 0;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (a[i * 3 + j] == a[(i + 1) * 3 + j])
				{
					res += b[i][j];
				}
				if (a[j * 3 + i] == a[j * 3 + i + 1])
				{
					res += c[j][i];
				}
			}
		}
		return res;
	}
	else
	{
		int res = 0;
		for (int i = 0; i < 9; i++)
		{
			if (a[i] == -1)
			{
				a[i] = n % 2;
				int tmp = f(n + 1, a);
				a[i] = -1;
				if (n % 2 == 1)
				{
					tmp = sum - tmp;
				}
				res = std::max(res, tmp);
			}
		}
		return (n % 2 == 0 ? res : sum - res);
	}
}

int main() {
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			scanf("%d", &b[i][j]);
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			scanf("%d", &c[i][j]);
		}
	}

	memset(temp, -1, sizeof(temp));
	for (int i = 0; i < 2; ++i) 
	{
		for (int j = 0; j < 3; ++j)
		{
			sum += (b[i][j] + c[j][i]);
		}
	}
	ans = f(0, temp);

	printf("%d\n%d\n", ans, sum - ans);
	return 0;
}
