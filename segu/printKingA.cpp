#include <iostream>
#include <cstdio>
#include <memory.h>
#include <windows.h>

int main()
{
    char buff[64];
    memset(buff, 0, sizeof(buff));
    auto file = fopen("king.txt", "r");
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if(file==NULL)
    {
        std::cout << "파일이 없습니다." << std::endl;
        return 0;
    }

    for(int i=0; i<100; i++)
    {
        std::cout<<"\r";
        std::cout<<"킹아 세구";
        for(int j=0; j<i; j++)
        {
            std::cout<<"■";
        }
        for(int j=i; j<100; j++)
        {
            std::cout<<"□";
        }
        std::cout<<" " << i << "%";
        std::cout<<" 다운로드 중";
        for(int j=0; j<i%3+1; j++)
        {
            std::cout<<".";
        }
        Sleep(50);
    }

    std::cout<<"\r"<<std::endl;
    while(std::fread(buff, sizeof(char), sizeof(buff)-1, file) > 0)
    {
        std::cout << buff;
        Sleep(1);
    }

    fclose(file);

    return 0;
}