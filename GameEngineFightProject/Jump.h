#pragma once
#include "ActionFinal.h"

class Jump :
	public ActionFinal
{
public:
	Jump();
	~Jump();

	void execute();
};

