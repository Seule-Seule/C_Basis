#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "log.h"


#define MAX_STRING_LEN 		10240

/*Level类别*/
#define NO_LOG_LEVEL		0
#define DEBUG_LEVEL			1
#define INFO_LEVEL			2
#define WARNING_LEVEL		3
#define ERROR_LEVEL			4

int  LogLevel[5] = { NO_LOG_LEVEL, DEBUG_LEVEL, INFO_LEVEL, WARNING_LEVEL, ERROR_LEVEL };

/*Level的名称*/
char LevelName[5][10] = { "NOLOG", "DEBUG", "INFO", "WARNING", "ERROR" };

static int Error_GetCurTime(char* strTime)
{
    struct tm* tmTime = NULL;
    size_t			timeLen = 0;
    time_t			tTime = 0;

    tTime = time(NULL);
    tmTime = localtime(&tTime);
    /*timeLen = strftime(strTime, 33, "%Y(Y)%m(M)%d(D)%H(H)%M(M)%S(S)", tmTime);*/
    timeLen = strftime(strTime, 33, "%Y.%m.%d %H:%M:%S", tmTime);

    return timeLen;
}

static int Error_OpenFile(int* pf, char *_file_name)
{
    char	fileName[1024];

    memset(fileName, 0, sizeof(fileName));
#ifdef _WIN32
    sprintf(fileName, "%s", _file_name);
#else
    sprintf(fileName, "%s",/* getenv("HOME"), */_file_name);
#endif

    * pf = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (*pf < 0)
    {
        return -1;
    }

    return 0;
}

static void Error_Core(char * _log_file_name, const char* file, int line, int level, int status, const char* fmt, va_list args)
{
    char str[MAX_STRING_LEN];
    int	 strLen = 0;
    char tmpStr[64];
    int	 tmpStrLen = 0;
    int  pf = 0;

    /*初始化*/
    memset(str, 0, MAX_STRING_LEN);
    memset(tmpStr, 0, 64);

    /*加入LOG时间*/
    tmpStrLen = Error_GetCurTime(tmpStr);
    tmpStrLen = sprintf(str, "[%s]  ", tmpStr);
    strLen = tmpStrLen;

    /*加入LOG等级*/
    tmpStrLen = sprintf(str + strLen, "[%s]  ", LevelName[level]);
    strLen += tmpStrLen;

    /*加入LOG状态*/
    if (status != 0)
    {
        tmpStrLen = sprintf(str + strLen, "[ERRNOMSG is %d]  ", status);
    }
    else
    {
        tmpStrLen = sprintf(str + strLen, "[SUCCESS]  ");
    }
    strLen += tmpStrLen;

    /*加入LOG信息*/
    tmpStrLen = vsprintf(str + strLen, fmt, args);
    strLen += tmpStrLen;

    /*加入LOG发生文件*/
    tmpStrLen = sprintf(str + strLen, " [%s]", file);
    strLen += tmpStrLen;

    /*加入LOG发生行数*/
    tmpStrLen = sprintf(str + strLen, " [%d]\n", line);
    strLen += tmpStrLen;

    /*打开LOG文件*/
    if (Error_OpenFile(&pf, _log_file_name))
    {
        return;
    }

    /*写入LOG文件*/
    write(pf, str, strLen);
    /*LR_Log_Error_WriteFile(str);*/

    /*关闭文件*/
    close(pf);

    return;
}

void LR_LOG(const char * _log_file_name, const char* file, int line, int level, int status, const char* fmt, ...)
{
    va_list args;

    /*判断是否需要写LOG*/
    /*if(level!=DEBUG_LEVEL && level!=INFO_LEVEL && level!=WARNING_LEVEL && level!=ERROR_LEVEL)*/
    if (level == NO_LOG_LEVEL)
    {
        return;
    }

    /*调用核心的写LOG函数*/
    va_start(args, fmt);
    Error_Core(_log_file_name, file, line, level, status, fmt, args);
    va_end(args);

    return;
}
