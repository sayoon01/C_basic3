#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main(void)
//{
//	int i, flag, cnt;
//	int num, rsltnum;
//	scanf("%d", &num);
//
//	for (i = 1;; i++)
//	{
//		rsltnum = num * i; //모든 자리 숫자가 1인 수를 찾을 때까지 i를 곱한다, 함수 사용한다면 무한반복문 피할 수 있음
//		
//		cnt = 0; // 1의 개수를 세기
//		flag = 1; // flag=1이면 모든 자리 숫자가 1 아니면 flag=0
//		while (rsltnum != 0)
//		{
//			if (rsltnum % 10 != 1) {
//				flag = 0;
//				break; // 1이 아닌수 발견 시 바로 반복문 나온다
//			}
//			else
//				cnt++;
//			rsltnum /= 10;
//		}
//
//		if (flag)  // 모든 숫자가 1이 되는 배수라면 반복문 벗어나기 왜냐하면 가장 작은 수 C를 찾기 때문
//			break; 
//	}
//
//	printf("%d\n", cnt);
//}
int main(void)
{
	int i, flag, cnt;
	int num, rsltnum;
	scanf("%d", &num);

	for (i = 1;; i++)
	{
		rsltnum = num * i; //모든 자리 숫자가 1인 수를 찾을 때까지 i를 곱한다, 함수 사용한다면 무한반복문 피할 수 있음

		cnt = 0; // 1의 개수를 세기
		while (rsltnum != 0)
		{
			if (rsltnum % 10 != 1) {
				break;
			}
			else
				cnt++;
			rsltnum /= 10;
		}

		if (rsltnum == 0) {
			printf("%d\n", cnt);
			return 0;
		}
	}
}

