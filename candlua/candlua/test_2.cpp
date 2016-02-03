//c++定义函数 lua来调用
#include <iostream>
using namespace::std;

#include "lua-5.3.2/src/lua.hpp"

//extern
/*
	@param lState : 表示当前lua环境的函数指针
	@return :表示该函数计算的结果的个数
*/
extern "C" int Cpp_Max(lua_State *lState)
{
	//取传入的第一个参数
	double dA = luaL_checknumber(lState,1);
	//取传入的第二个参数
	double dB = luaL_checknumber(lState,2);
	double dRet = (dA < dB) ? dB : dA;
	//将结果压入栈中
	lua_pushnumber(lState,dRet);
	return dRet;
}

//结构是
luaL_Reg szCPPRegFunc[] = 
{
	{"CPP_MAX",Cpp_Max},
	{NULL,NULL}
};

extern int luaopen_CppFunc(lua_State *lState)
{	
	luaL_newlib(lState,szCPPRegFunc);
	return 1;
}
