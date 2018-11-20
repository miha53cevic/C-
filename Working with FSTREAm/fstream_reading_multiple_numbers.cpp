#include <iostream>
#include <fstream>
int main()
{
    std::fstream myfile("D:\\data.txt", std::ios_base::in);

    float a;
    while (myfile >> a)
    {
        printf("%f ", a);
    }

    return 0;
}
