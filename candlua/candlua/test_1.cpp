//学习c++与lua的交互代码
//程序 简单的写c++与lua交互程序
//c++中得到lua环境 并调用lua文件
#include <iostream>
using namespace std;
#include "lua-5.3.2/src/lua.hpp"
int main()
{
	//得到lua的环境
	lua_State *l = luaL_newstate();
	//开启环境
	luaL_openlibs(l);
	//实际上就是运行了所在的lua文件
	luaL_dofile(l, "candlua.lua");
	//关闭当前环境
	lua_close(l);
	system("pause");
	return 0;
}