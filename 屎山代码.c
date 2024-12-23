#include <stdio.h>
#include <windows.h>
void HV(int a) //VBS和Hyper-V开关              1为开，0为关
{
    if (a)
    {
        system("bcdedit /set hypervisorlaunchtype auto");
        printf("已成功开启VBS\n");
        system("DISM /Online /Enable-Feature:Microsoft-Hyper-V-All");
    }
    else
    {
        system("bcdedit /set hypervisorlaunchtype off");
        printf("已成功关闭VBS\n");
        system("DISM /Online /Disable-Feature:Microsoft-Hyper-V-all");
    }
}
void Game(int b)    //游戏模式以及GPU计划的开关 1为开，0为关
{
    if (b)
    {
        system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\GameBar\" /v AutoGameModeEnabled /t REG_DWORD /d 1 /f");  //开游戏模式
        printf("已开启游戏模式\n");
        system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v HwSchMode /t REG_DWORD /d 2 /f");    //开GPU调度
        printf("已关闭GPU调度\n");
    }
    else
    {
        system("reg add \"HKEY_CURRENT_USER\\Software\\Microsoft\\GameBar\" /v AutoGameModeEnabled /t REG_DWORD /d 0 /f");  //关游戏模式
        printf("已关闭游戏模式\n");
        system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v HwSchMode /t REG_DWORD /d 1 /f");    //关GPU调度
        printf("已关闭GPU调度\n");
    }
}
void main()
{
    int a=0,b=0,sw;
    printf("请选择你的游戏：\n");
    printf("CS2    瓦罗兰特    火影忍者\n");
    printf("分别输入 1 2 3\n");
    scanf("%d",&sw);
    system("cls");
    if (sw==1)
        a=0,b=1;
    else if (sw==2)
        a=0,b=0;
    else if (sw==3)
        a=1,b=0;
    else printf("已为你自动加载Valorant模式\n");
    Sleep(500);
    Game(b);
    HV(a);
    system("pause");
}