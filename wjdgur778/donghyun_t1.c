#include<stdio.h>

struct account {
	int ID;
	int sum;
	char name[10];
}typedef account;//����
account user[100];
int AccountN = 0;//���� �ε���

int MakingAccount() {
	int id;
	char name[10];
	int sum;

	scanf_s("%d", &id);
	for (int i = 0; i < 100; i++) {
		if (user[i].ID == id) {
			printf("���� ID�� �ֽ��ϴ�.");
			return 0;
		}//���� ���̵� ������ return 0
	}//���� �迭 ��� Ȯ��
	printf("�̸�:");
	scanf_s("%s", name,sizeof(name));
	printf("�Աݾ�:");
	scanf_s("%d", &sum);
	user[AccountN].ID = id;
	for (int i = 0; i < sizeof(user[AccountN].name); i++) {
		user[AccountN].name[i] = name[i];
	}
	user[AccountN].sum = sum;
	AccountN++;
	//���� ����
}

void Deposit() {
	int id;
	char name[10];
	int sum;
	if (user[0].ID != 0) {
		printf("[��   ��] \n");
		printf("����ID: ");
		scanf_s("&d", &id);
		printf("�Աݾ�:");
		scanf_s("%d", &sum);
		printf("�ԱݿϷ� \n");
		for (int i = 0; i < 100; i++) {
			if (user[i].ID == id)
				user[i].sum = user[i].sum + sum;
		}//���� id��  ã�� �Ա�
	}
	else
		printf("���¸� �����ϼ��� %d�� \n", id);
}//�Ա�

int Withdrawal() {
	int id;
	int sum;
	if (user[0].ID != 0) {
		printf("[��   ��] \n");
		printf("���� ID:");
		scanf_s("%d", &id);
		printf("��ݾ�:");
		scanf_s("%d", &sum);

		for (int i = 0; i < 100; i++) {
			if (id == user[i].ID) {
				if (user[i].sum - (sum) > 0) {
					user[i].sum = user[i].sum - sum;
					return 0;
				}

				else
				{
					printf("�ܾ��̺����մϴ�.\n");
					return 0;
				}
			}
		}
	}
	else
		printf("���¸� �����ϼ��� %d�� \n", &id);
}//���
void ShowAcc() {
	/*for (int i = 0; i < 100; i++) {
		if (user[i].ID == 0)
			break;
		else
		{
			printf("����ID: %d \n", &user[i].ID);
			printf("�̸�: %s \n", &user[i].name);
			printf("�ܾ�: %d \n", &user[i].sum);
		}
	}*/
	printf("����ID: %d \n", user[0].ID);
	printf("�̸�: %s \n", &user[0].name);
	printf("�ܾ�: %d \n", user[0].sum);
}

void Show() {
	printf("----- Menu-----  \n");
	printf("1. ���°��� \n");
	printf("2. �Ա�\n");
	printf("3. ���\n");
	printf("4. �������� ��ü ���\n");
	printf("5. ���α׷� ����\n");
	printf("����");
}//ȭ�� ����

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
			printf("���α׷��� ��ġ�ڽ��ϴ�.");
			return 0;
		default:
			printf("wrong number \n");
		}
	}//ȭ���� ��� ������ �ݺ�
	return 0;
}