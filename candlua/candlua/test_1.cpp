//ѧϰc++��lua�Ľ�������
//���� �򵥵�дc++��lua��������
//c++�еõ�lua���� ������lua�ļ�
#include <iostream>
using namespace std;
#include "lua-5.3.2/src/lua.hpp"
int main()
{
	//�õ�lua�Ļ���
	lua_State *l = luaL_newstate();
	//��������
	luaL_openlibs(l);
	//ʵ���Ͼ������������ڵ�lua�ļ�
	luaL_dofile(l, "candlua.lua");
	//�رյ�ǰ����
	lua_close(l);
	system("pause");
	return 0;
}