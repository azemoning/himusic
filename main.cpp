#include <iostream>
#include <windows.h>

void main_menu();

int main()
{
    system("title HiMusic - Toko Musik Online Masa Depan");
    system("mode 650");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    main_menu();
    return 0;
}
