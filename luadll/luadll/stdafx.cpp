// stdafx.cpp : source file that includes just the standard includes
// luadll.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
//c++���庯�� lua������
#include <iostream>
using namespace::std;

#include "../lua-5.3.2/src/lua.hpp"

//extern
/*
@param lState : ��ʾ��ǰlua�����ĺ���ָ��
@return :��ʾ�ú�������Ľ���ĸ���
*/
extern "C" int Cpp_Max(lua_State *lState)
{
	//ȡ����ĵ�һ������
	double dA = luaL_checknumber(lState, 1);
	//ȡ����ĵڶ�������
	double dB = luaL_checknumber(lState, 2);
	double dRet = (dA < dB) ? dB : dA;
	//�����ѹ��ջ��
	lua_pushnumber(lState, dRet);
	return dRet;
}

//�ṹ��
luaL_Reg szCPPRegFunc[] =
{
	{ "CPP_MAX", Cpp_Max },
	{ NULL, NULL }
};

extern int luaopen_CppFunc(lua_State *lState)
{
	luaL_newlib(lState, szCPPRegFunc);
	return 1;
}