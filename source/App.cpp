#include "stdafx.h"

#include "App.h"
#include "Days/Day.h"

////////////////////////////////////////////////////////////////////////////////
static int HandleInput(int32_t& taskId)
{
	Log::Console("Please enter valid day ID between %i and %i.",
		Day::MIN_ID, Day::MAX_ID);
	Log::Console("Enter 0 to exit the program.");

	return scanf_s("%i", &taskId);
}

namespace App
{
////////////////////////////////////////////////////////////////////////////////
bool Run()
{
	int32_t dayId = 0;

	while (true)
	{
		if (HandleInput(dayId) <= 0)
		{
			Log::Console("Day ID %i is invalid. Please enter valid day ID between %i and %i.",
				dayId, Day::MIN_ID, Day::MAX_ID);
			Log::Console("Enter 0 to exit the program.");
			continue;
		}

		ReturnIf(dayId == 0, true);

		if (!Day::IsValidDayId(dayId))
		{
			Log::Console("Day ID %i is invalid. Please enter valid day ID between %i and %i.",
				dayId, Day::MIN_ID, Day::MAX_ID);
			continue;
		}

		Day* day = Day::Create(dayId);
		AssertContinueIf(!day);

		day->Execute();
		day->Print();

		SafeDelete(day);
	}

	return true;
}
} // !namespace App