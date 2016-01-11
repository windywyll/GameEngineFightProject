#include "Jump.h"
#include <Windows.h>


Jump::Jump(std::string pName,
	float loadingTime,
	float moveDuration,
	float Recovery,
	float stunTime):ActionFinal(pName,loadingTime,moveDuration,Recovery,stunTime)
{
}


Jump::~Jump()
{
}

void Jump::execute(Player* p)
{
	float jumpForce = 5;
	p->movePosition(Vector3(0, jumpForce,0));
	Sleep(600);
	p->movePosition(Vector3(0, -jumpForce, 0));
}
