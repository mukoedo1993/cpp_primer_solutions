#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <string> 
int main(void)
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    char str3[50]="0";
    strcat(str, str2);
    strcat(str, " ...");
    std::cout << str[6]<<std::endl;
    strcat(str, " Goodbye World!");
    std::cout << str[13] << std::endl;
    strcpy(str3, str);
    std::cout << str3[0] << std::endl;

}