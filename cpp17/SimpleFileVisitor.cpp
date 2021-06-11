#include <iostream>
#include <filesystem>

namespace fs = std::experimental::filesystem;

void DisplayDirTree(const fs::path& pathToShow, int level)
{
    if (fs::exists(pathToShow) && fs::is_directory(pathToShow))
    {
        auto parentFolder = pathToShow.filename();
        for (int i = 0; i < level; i++)
            std::cout << "-";
        std::cout << "[" + parentFolder.string() + "]" << "\n";

        // Entry is type directory_entry
        for (const auto& entry : fs::directory_iterator(pathToShow))
        {
            auto filename = entry.path().filename();
            if (fs::is_directory(entry.path()))
            {
                DisplayDirTree(entry.path(), level + 1);
            }
            else if (fs::is_regular_file(entry.path()))
            {
                // only show .mp3 files
                if (filename.extension() == ".mp3")
                {
                    for (int i = 0; i < level + 1; i++)
                        std::cout << "-";
                    std::cout << filename << "\n";
                }
            }
        }
    }
}

int main()
{
    DisplayDirTree("C:/Users/Mihael/Music/", 0);
}