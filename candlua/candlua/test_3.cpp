//lua与c++入门 1
//写一个lua的解释器
//最大命令字节数
#define MAX_COMMAND_LEN 256

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lua-5.3.2/src/lua.hpp"

char strCommand[MAX_COMMAND_LEN];
lua_State *ptrLuaState;

void PrintVersionInfo()
{
	printf("Lua 5.3.2  Copyright (C) 1994-2015 Lua.org, PUC-Rio\n");
	printf("Modified by Happyli 2016.02.03 17:08\n");
}

//初始化命令字符串
void InitCommand()
{
	memset(strCommand, 0, sizeof(strCommand));
}

//初始化lua环境(初始化内部lua虚拟栈)
void InitLuaState()
{
	if (ptrLuaState != NULL)
	{
		ptrLuaState = NULL;
	}
	
	ptrLuaState = luaL_newstate();
	//当前的lua环境指针标准库
	luaL_openlibs(ptrLuaState);
}

//进入程序前做必要的初始化
void Init()
{
	InitCommand();
	InitLuaState();
}

//程序结束做一遍清理
void clear()
{
	if (ptrLuaState != NULL)
	{
		lua_close(ptrLuaState);
	}
}

int main()
{	
	Init();
	PrintVersionInfo();
	printf("> ");
	while (gets(strCommand))
	{
		if (strcmp(strCommand, "EXIT()") == 0)
		{
			break;
		}
		//检测输入的字符串语法是否正确
		//luaL_loadbuffer:实际上内部调用的是lua_load:将对应数据解析(具体可以看源码)
		if (luaL_loadbuffer(ptrLuaState, strCommand, strlen(strCommand), NULL) == 0)
		{	
			//解析完后 将对应的数据结构入栈
			if (lua_pcall(ptrLuaState, 0, LUA_MULTRET, 0))
			{
				//从栈处去的错误信息 对应的index为-1
				printf("ERROR:%s\n", luaL_checkstring(ptrLuaState, -1));
			}
		}
		else
		{
			printf("ERROR:%s\n", luaL_checkstring(ptrLuaState, -1));
		}
	printf("> ");
	}
	clear();
	return 0;
}