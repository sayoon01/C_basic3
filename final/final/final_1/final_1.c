////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////
////int main(void)
////{
////	int n;
////	int A[100];
////	int d;
////	int flag = 1;
////
////	scanf("%d", &n);
////
////	if (n <= 0)
////		return 0;
////
////	for (int i = 0; i < n; i++)
////		scanf("%d", &A[i]);
////
////	d = A[1] - A[0];
////
////
////	for (int i = 0; i < n - 1; i++)
////	{
////		int d0 = A[i + 1] - A[i];
////		if (d != d0)
////		{
////			flag = 0;
////			break;
////		}
////	}
////
////	printf("%d", flag);
////}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int count = 0;
//void countKey(int num, int key)
//{
//	while (num != 0)
//	{
//		if ((num % 10) == key)
//			count++;
//		num /= 10;
//	}
//}
//int main(void)
//{
//	int data[1000];
//	int n;
//	int k;
//
//	scanf("%d %d", &n, &k);
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &data[i]);
//		countKey(data[i], k);
//	}
//
//	printf("%d", count);
//}
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int plays, wins;
	int start, mid, end;
	int answer;
	int winpercent, winpercent_var;

	scanf("%d %d", &plays, &wins);
	winpercent = (int)((wins / (double)plays) * 100);

	if (winpercent>=99) {
		answer = -1;
	}
	else {
		start = 1;
		end = 1000000000;

		while (start <= end) {
			mid = (start + end) / 2;

			int winpercent_var = (int)((wins + mid) / (double)(plays + mid) * 100);
			if (winpercent_var > winpercent) {
				answer = mid;
				end = mid - 1;
			}
			else
				start = mid + 1;
		}
	}
	

	printf("%d", answer);
}