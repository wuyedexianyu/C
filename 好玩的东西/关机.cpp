#include<stdio.h>
#include<windows.h>
int main()
{
	char a[10];
	system("shutdown -s -t 60");
	printf("�����롰��������������ĵ��Խ���60s��ػ�\n");
	loop:
	{
		scanf("%s", &a);
	}
	if (strcmp(a, "������") != 0)
	{
		printf("�������\n");
		printf("60�뻹û�е����㻹�л���\n");
		goto loop; 
	}
	else
	{
		printf("����Ҳ��û���õģ�����\n");
	}
	Sleep(2000);
	return 0;
}
