#include <stdio.h>
#include <windows.h>
void HV(int a) //VBS��Hyper-V����              1Ϊ����0Ϊ��
{
    if (a)
    {
        system("bcdedit /set hypervisorlaunchtype auto");
        printf("�ѳɹ�����VBS\n");
        system("DISM /Online /Enable-Feature:Microsoft-Hyper-V-All");
    }
    else
    {
        system("bcdedit /set hypervisorlaunchtype off");
        printf("�ѳɹ��ر�VBS\n");
        system("DISM /Online /Disable-Feature:Microsoft-Hyper-V-all");
    }
}
void Game(int b)    //��Ϸģʽ�Լ�GPU�ƻ��Ŀ��� 1Ϊ����0Ϊ��
{
    if (b)
    {
        system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\GameBar\" /v AutoGameModeEnabled /t REG_DWORD /d 1 /f");  //����Ϸģʽ
        printf("�ѿ�����Ϸģʽ\n");
        system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v HwSchMode /t REG_DWORD /d 2 /f");    //��GPU����
        printf("�ѹر�GPU����\n");
    }
    else
    {
        system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\GameBar\" /v AutoGameModeEnabled /t REG_DWORD /d 0 /f");  //����Ϸģʽ
        printf("�ѹر���Ϸģʽ\n");
        system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v HwSchMode /t REG_DWORD /d 1 /f");    //��GPU����
        printf("�ѹر�GPU����\n");
    }
}
void main()
{
    int a=0,b=0,sw;
    printf("��ѡ�������Ϸ��\n");
    printf("CS2    ��������    ��Ӱ����\n");
    printf("�ֱ����� 1 2 3\n");
    scanf("%d",&sw);
    system("cls");
    if (sw==1)
        a=0,b=1;
    else if (sw==2)
        a=0,b=0;
    else if (sw==3)
        a=1,b=0;
    else printf("��Ϊ���Զ�����Valorantģʽ\n");
    Sleep(500);
    Game(b);
    HV(a);
    system("pause");
}