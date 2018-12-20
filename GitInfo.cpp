
#include "GitInfo.h"
#include <stdlib.h>
#include <string>
#include <fstream>
// #include <git2.h>

std::string GetGitCommitOfContainingRepository() {
    // git_libgit2_init();
    // git_repository* repo;
    // git_reference *head;
    // git_repository_open(&repo, ".");
    // int result = git_repository_head(&head, repo);
    // return git_reference_name(head);
    // std::stringstream buffer;
    auto _ = freopen("commit.txt", "w", stdout);
    // stdout.rdbuf(buffer.rdbuf());
    int res = system("git show --no-patch --format=%H");
    if (res == 0) 
    {
        std::ifstream file("commit.txt");
        std::string line;
        std::getline(file, line);
        return line.substr(0, 7);
        // auto file = fopen("commit.txt", "r");

    }
    else 
    {
        printf("git show returned with status code %i", res);
        return "ccc";
    }
}