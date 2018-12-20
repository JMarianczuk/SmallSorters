
#include "GitInfo.h"
#include <stdlib.h>
#include <string>
#include <fstream>

std::string GetGitCommitOfContainingRepository() {
    auto _ = freopen("commit.txt", "w", stdout);
    int res = system("git show --no-patch --format=%H");
    if (res == 0) 
    {
        std::ifstream file("commit.txt");
        std::string line;
        std::getline(file, line);
        return line.substr(0, 7); //Short commit
    }
    else 
    {
        printf("git show returned with status code %i", res);
        return "ccc";
    }
}