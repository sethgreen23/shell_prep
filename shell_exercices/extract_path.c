#include "main.h"

int main(void)
{
    char path[] = "/root/.vscode-server/bin/e7e037083ff4455cf320e344325dacb480062c3c/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/mnt/c/Program Files/WindowsApps/CanonicalGroupLimited.Ubuntu20.04LTS_2004.6.16.0_x64__79rhkp1fndgsc:/mnt/c/Program Files (x86)/Common Files/Oracle/Java/javapath";
    char *token = NULL;

    token = strtok(path, ":");
    while(token != NULL)
    {
        printf("[token] %s\n", token);
        token = strtok(NULL, ":");
    }

    return (0);
}