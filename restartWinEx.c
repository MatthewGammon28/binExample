/*  Filename:   restartWinEx.c
*   Date:       2023/05/02
*   Name:       Gammon M.D.
*   --------------------------------------------------------
*   Description: A short program that restarts windows explorer.
*   	I found that changes to desktop icons often don't reflect
*   	untill windows explorer is restarted, so I wrote this program.
*   --------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

 int main(){
    system("taskkill /f /im explorer.exe");
    system("start explorer.exe");

    return 0;
 }
