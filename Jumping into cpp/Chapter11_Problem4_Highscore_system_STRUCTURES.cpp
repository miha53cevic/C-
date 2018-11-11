#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

struct ScoreSystem
{
    int score[10];
    string name;
    int highscore;
};

void fill_scores(ScoreSystem user[])
{
    user[0].name = "Mihael";
    user[1].name = "Zora";
    user[2].name = "Mario";
    user[3].name = "Lidija";
    user[4].name = "Marko";

    for (int i=0;i<5;i++)
    {
        for (int j=0;j<10;j++)
        {
            user[i].score[j] = 1 + rand() % 5000;
        }
    }
}

void leaderboard(ScoreSystem user)
{
    for (int i=0;i<5;i++)
    {
        cout << user[i].name << " - " << sort (user[i].score, user[i].score + 10);
    }
}

int main()
{
    //srand(time(NULL));

    ScoreSystem user[10];
    fill_scores(user);

    int input;

    cout <<  "Score System 2018\n\n1. Add\n2. Show leader board";

    switch (input)
    {
    case 1:
        {

        }
    case 2:
        {
            leaderboard(user);
        }
    }
}
