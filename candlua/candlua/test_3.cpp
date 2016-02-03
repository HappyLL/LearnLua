//lua��c++���� 1
//дһ��lua�Ľ�����
//��������ֽ���
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

//��ʼ�������ַ���
void InitCommand()
{
	memset(strCommand, 0, sizeof(strCommand));
}

//��ʼ��lua����(��ʼ���ڲ�lua����ջ)
void InitLuaState()
{
	if (ptrLuaState != NULL)
	{
		ptrLuaState = NULL;
	}
	
	ptrLuaState = luaL_newstate();
	//��ǰ��lua����ָ���׼��
	luaL_openlibs(ptrLuaState);
}

//�������ǰ����Ҫ�ĳ�ʼ��
void Init()
{
	InitCommand();
	InitLuaState();
}

//���������һ������
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
		//���������ַ����﷨�Ƿ���ȷ
		//luaL_loadbuffer:ʵ�����ڲ����õ���lua_load:����Ӧ���ݽ���(������Կ�Դ��)
		if (luaL_loadbuffer(ptrLuaState, strCommand, strlen(strCommand), NULL) == 0)
		{	
			//������� ����Ӧ�����ݽṹ��ջ
			if (lua_pcall(ptrLuaState, 0, LUA_MULTRET, 0))
			{
				//��ջ��ȥ�Ĵ�����Ϣ ��Ӧ��indexΪ-1
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