#include "stdafx.h"

#include "App.h"

////////////////////////////////////////////////////////////////////////////////
int32_t main(int32_t argC, char** argV)
{
	ReturnIf(!App::Run(), EXIT_FAILURE);

	return EXIT_SUCCESS;
}