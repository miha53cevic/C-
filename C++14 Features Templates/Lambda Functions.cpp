#include <iostream>

int main()
{
    int a = 10;
    int b = 10;

    //Lambda Examples
    auto EmptyLambda = []()
    {
        std::cout << "Empty Lambda" << std::endl;
    };



    auto SumLambda = [](int x, int y) -> int // -> int znaci da je return int, ne mora biti tu
    {
        return x + y;
    };



    auto ExampleLambdaOne = [b](int x) //U [] se stavljaju varijable izvan funkcije koje lambda moze koristiti
    {
        return x + b;
    };

    auto ExampleLambdaTwo = [a, &b]()
    {
        //a = 5; Error, smije samo uzeti kopiju
        b = 5;
        return a + b;
    };



    auto ExampleLambdaThree = [=]() //= veli da smiju koristiti sve varijable, ali ih ne mjenjati
    {
        return a + b;
    };



    auto ExampleLambdaFour = [=, &b]()
    {
        //a = 5;    Error, smije samo koristiti varijablu kao const
        b = 4;

        return a + b;
    };



    auto ExampleLambdaFive = [&]()
    {
        a = 3;

        return a + b;
    };



    //Calling Lambdas
    EmptyLambda();
    std::cout << SumLambda(a, b) << std::endl;
    std::cout << ExampleLambdaOne(a) << std::endl;
    std::cout << ExampleLambdaTwo() << std::endl;
    std::cout << ExampleLambdaThree() << std::endl;
    std::cout << ExampleLambdaFour() << std::endl;
    std::cout << ExampleLambdaFive() << std::endl;

    //a, b
    std::cout << "a = " << a << std::endl; //a je promjenjen prije u & lambdama
    std::cout << "b = " << b << std::endl; //b je promjenjen prije u & lambdama
}
