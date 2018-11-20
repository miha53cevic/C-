#include <iostream>
#include <fstream>

int main()
{
    std::fstream writer;
	writer.open("test.txt", std::fstream::in | std::fstream::app);
	writer << "yeet" << "\n";
}
