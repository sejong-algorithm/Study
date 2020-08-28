#include<stdio.h>

struct account {
	int ID;
	int sum;
	char name[10];
}typedef account;//계좌
account user[100];
int AccountN = 0;//계좌 인덱스

int MakingAccount() {
	int id;
	char name[10];
	int sum;

	scanf_s("%d", &id);
	for (int i = 0; i < 100; i++) {
		if (user[i].ID == id) {
			printf("같은 ID가 있습니다.");
			return 0;
		}//같은 아이디가 있을때 return 0
	}//계좌 배열 모두 확인
	printf("이름:");
	scanf_s("%s", name,sizeof(name));
	printf("입금액:");
	scanf_s("%d", &sum);
	user[AccountN].ID = id;
	for (int i = 0; i < sizeof(user[AccountN].name); i++) {
		user[AccountN].name[i] = name[i];
	}
	user[AccountN].sum = sum;
	AccountN++;
	//계좌 생성
}

void Deposit() {
	int id;
	char name[10];
	int sum;
	if (user[0].ID != 0) {
		printf("[입   금] \n");
		printf("계좌ID: ");
		scanf_s("&d", &id);
		printf("입금액:");
		scanf_s("%d", &sum);
		printf("입금완료 \n");
		for (int i = 0; i < 100; i++) {
			if (user[i].ID == id)
				user[i].sum = user[i].sum + sum;
		}//같은 id를  찾아 입금
	}
	else
		printf("계좌를 개설하세요 %d씨 \n", id);
}//입금

int Withdrawal() {
	int id;
	int sum;
	if (user[0].ID != 0) {
		printf("[출   금] \n");
		printf("계좌 ID:");
		scanf_s("%d", &id);
		printf("출금액:");
		scanf_s("%d", &sum);

		for (int i = 0; i < 100; i++) {
			if (id == user[i].ID) {
				if (user[i].sum - (sum) > 0) {
					user[i].sum = user[i].sum - sum;
					return 0;
				}

				else
				{
					printf("잔액이부족합니다.\n");
					return 0;
				}
			}
		}
	}
	else
		printf("계좌를 개설하세요 %d씨 \n", &id);
}//출금
void ShowAcc() {
	/*for (int i = 0; i < 100; i++) {
		if (user[i].ID == 0)
			break;
		else
		{
			printf("계좌ID: %d \n", &user[i].ID);
			printf("이름: %s \n", &user[i].name);
			printf("잔액: %d \n", &user[i].sum);
		}
	}*/
	printf("계좌ID: %d \n", user[0].ID);
	printf("이름: %s \n", &user[0].name);
	printf("잔액: %d \n", user[0].sum);
}

void Show() {
	printf("----- Menu-----  \n");
	printf("1. 계좌개설 \n");
	printf("2. 입금\n");
	printf("3. 출금\n");
	printf("4. 계좌정보 전체 출력\n");
	printf("5. 프로그램 종료\n");
	printf("선택");
}//화면 보기

int main() {
	int n;
	while (1) {
		Show();
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			MakingAccount();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdrawal();
			break;
		case 4:
			ShowAcc();
			break;
		case 5:
			printf("프로그램을 마치겠습니다.");
			return 0;
		default:
			printf("wrong number \n");
		}
	}//화면이 계속 나오게 반복
	return 0;
}