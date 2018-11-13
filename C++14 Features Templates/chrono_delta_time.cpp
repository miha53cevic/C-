#include <iostream>
#include <chrono>

int main()
{
    //60 updates per second
    float frameTime = 1.f / 60.f;

    float fElapsed = 0;

    std::chrono::system_clock::time_point t;

    while (1)
    {
        //Dobivanje DELTA vremena
        auto elapsed = std::chrono::system_clock::now() - t;

        //Dodavanje vremena u fElapsed i pretvaranje u FLOAT
        fElapsed += std::chrono::duration<float>(elapsed).count();

        if (fElapsed >= frameTime)
        {
            printf("hello");

            fElapsed -= fElapsed;
        }

        //Zapravo prijasnje vrijeme
        t = std::chrono::system_clock::now();
    }

    return 0;
}
