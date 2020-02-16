#pragma once
#include "Application.h"
#include <cstdlib>




int main()
{
	int key;
	Application app;//program application
	system("mode con: cols=60 lines=40");
	system("title Better than Melon");
	system("cOLoR 2f");

	
	app.Run();//프로그램 실행	

	return 0;
}
