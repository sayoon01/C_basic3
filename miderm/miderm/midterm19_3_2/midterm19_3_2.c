//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int solution(int n);
//int dataDigit(int idx, int size, int num);
//
//int main(void)
//{
//    int digit;
//    int n;
//    int cnt = 1;
//    int num = 3;
//    scanf("%d", &n);
//
//    while (cnt <= n)
//    {
//        if (num < 10)
//        {
//            if (cnt == n)
//                printf("%d", num);
//            cnt++;
//        }
//        else
//        {
//            int x = solution(num);
//            for (int i = 0; i < x; i++)
//            {
//                if (cnt == n)
//                    printf("%d ", dataDigit(i, x, num));
//                cnt++;
//            }
//        }
//        num += 3;
//    }
//
//    return 0;
//}
//
//int solution(int n)
//{
//    int cnt = 0;
//    while (n > 0)
//    {
//        cnt++;
//        n /= 10;
//    }
//    return cnt;
//}
//
//int dataDigit(int idx, int size, int num)
//{
//    int i = 0;
//    int result;
//    int* p = (int*)malloc(sizeof(int) * size);
//
//    i = 0;
//    while(num!=0)
//    {
//        p[i++] = num % 10;
//        num /= 10;
//    }
//
//    result = p[size - 1 - idx];
//    free(p);
//
//    return result;
//}
////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <stdlib.h>
////
////int solution(int n);
////int digitSetter(int num, int size, int idx);
////int main(void)
////{
////	int n;
////	int cnt = 1;
////	int num = 3;
////
////	scanf("%d", &n);
////
////	while (cnt <= n)
////	{
////		if (num < 10)
////		{
////			if (cnt == n)
////				printf("%d", num);
////			cnt++;
////		}
////		else
////		{
////			int x = solution(num);
////			for (int i = 0; i < cipher; i++)
////			{
////				if (cnt == n)
////					printf("%d", digitSetter(num, cipher, i));
////				cnt++;
////			}
////		}
////		num += 3;
////	}
////}
////int solution(int num)
////{
////	int count = 0;
////	if (num != 0)
////	{
////		count++;
////		num /= 10;
////	}
////	return count;
////}
////int digitSetter(int num, int size, int idx)
////{
////	int* p = (int*)malloc(sizeof(int) * size);
////
////	for (int i = 0; i < size; i++)
////	{
////		p[i] = num % 10;
////		num /= 10;
////	}
////
////	int result = p[size - 1 - idx];
////	free(p);
////	return result;
////}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 3의 배수 게임
int solution(int n)
{
	int count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return count;
}
void makeArray(int* p, int size, int num)
{
	int i = 0;
	while (i<size)
	{
		p[size - 1 - i] = num % 10;
		num /= 10;
		i++;
	}

}
int main(void)
{
	int num, size;
	int i = 1, three = 3;
	
	scanf("%d", &num);
	/*size = solution(num);
	printf("%d", size);*/

	while (i <= num)
	{
		if (three < 10)
		{
			if (i == num)
			{
				printf("%d",three);
			}
			i++;
		}
		else
		{
			size = solution(three);
			int* p = (int*)malloc(sizeof(int) * size);
			makeArray(p, size, three);

			for (int j = 0; j < size; j++)
			{
				if (num == i + j)
				{
					printf("%d", p[j]);
					break;
				}
			}
			free(p);
			i += size;
		}
		three += 3;
	}

}