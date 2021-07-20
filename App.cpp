#include "pch.h"
#include "Engine/Engine.h"

int main(int argc, char** argv)
{
	FO3D::Core.Initialize();

	while (FO3D::Core.Run())
	{
		FO3D::Core.Update();
	}
	return 0;
}