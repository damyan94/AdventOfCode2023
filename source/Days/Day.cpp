#include "stdafx.h"

#include "Days/Day.h"
#include "Days/Day1.h"

#define DAY_ITERATOR(__Result, __Id) case __Id: __Result = new Day##__Id##(); break;

////////////////////////////////////////////////////////////////////////////////
bool Day::IsValidDayId(int32_t dayId)
{
	return dayId >= Day::MIN_ID && dayId <= Day::MAX_ID;
}

////////////////////////////////////////////////////////////////////////////////
Day* Day::Create(int32_t dayId)
{
	AssertReturnIf(!IsValidDayId(dayId), nullptr);

	Day* result = nullptr;
	switch (dayId)
	{
		DAY_ITERATOR(result, 1);
		//DAY_ITERATOR(result, 2);
		//DAY_ITERATOR(result, 3);
		//DAY_ITERATOR(result, 4);
		//DAY_ITERATOR(result, 5);
		//DAY_ITERATOR(result, 6);
		//DAY_ITERATOR(result, 7);
		//DAY_ITERATOR(result, 8);
		//DAY_ITERATOR(result, 9);
		//DAY_ITERATOR(result, 10);
		//DAY_ITERATOR(result, 11);
		//DAY_ITERATOR(result, 12);
		//DAY_ITERATOR(result, 13);
		//DAY_ITERATOR(result, 14);
		//DAY_ITERATOR(result, 15);
		//DAY_ITERATOR(result, 16);
		//DAY_ITERATOR(result, 17);
		//DAY_ITERATOR(result, 18);
		//DAY_ITERATOR(result, 19);
		//DAY_ITERATOR(result, 20);
		//DAY_ITERATOR(result, 21);
		//DAY_ITERATOR(result, 22);
		//DAY_ITERATOR(result, 23);
		//DAY_ITERATOR(result, 24);
		//DAY_ITERATOR(result, 25);
	}

	return result;
}