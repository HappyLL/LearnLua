// LuaDll1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
//c++���庯�� lua������
#include <iostream>
using namespace::std;

#include "../lua-5.3.2/src/lua.hpp"

//extern
/*
@param lState : ��ʾ��ǰlua�����ĺ���ָ��
@return :��ʾ�ú�������Ľ���ĸ���
*/
int Cpp_Max(lua_State *lState)
{
	//ȡ����ĵ�һ������
	double dA = luaL_checknumber(lState, 1);
	//ȡ����ĵڶ�������
	double dB = luaL_checknumber(lState, 2);
	double dRet = (dA < dB) ? dB : dA;
	//�����ѹ��ջ��
	lua_pushnumber(lState, dRet);
	return 1;
}

//�ṹ��
luaL_Reg szCPPRegFunc[] =
{
	{ "CPP_Max", Cpp_Max},
	{ NULL, NULL }
};

int luaopen_CppFunc(lua_State *lState)
{
	luaL_newlib(lState, szCPPRegFunc);
	return 1;
}
