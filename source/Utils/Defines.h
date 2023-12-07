#pragma once

#define __ASSERT_INFO(__Condition)\
		"Check: " #__Condition\
		"\nFile: " __FILE__\
		"\nFunction: " __FUNCTION__\
		"\nLine: " _STRINGIZE(__LINE__)

#define ReturnIf(__Condition, ...)					if(__Condition) return __VA_ARGS__
#define ContinueIf(__Condition)						if(__Condition) continue
#define BreakIf(__Condition)						if(__Condition) break

#define ReturnUnless(__Condition, ...)				ReturnIf(!__Condition, __VA_ARGS__)
#define ContinueUnless(__Condition)					ContinueIf(!__Condition)
#define BreakUnless(__Condition)					BreakIf(!__Condition)

#define AssertReturnIf(__Condition, ...)			do { if(__Condition) { Assert::Assert(__ASSERT_INFO(__Condition)); return __VA_ARGS__; }} while(false)
#define AssertContinueIf(__Condition)				do { if(__Condition) { Assert::Assert(__ASSERT_INFO(__Condition)); continue; }} while(false)
#define AssertBreakIf(__Condition)					do { if(__Condition) { Assert::Assert(__ASSERT_INFO(__Condition)); break; }} while(false)

#define AssertReturnUnless(__Condition, ...)		AssertReturnIf(!__Condition, __VA_ARGS__)
#define AssertContinueUnless(__Condition)			AssertContinueIf(!__Condition)
#define AssertBreakUnless(__Condition)				AssertBreakIf(!__Condition)

#define SafeDelete(__Ptr)							do { if(__Ptr) { delete __Ptr; __Ptr = nullptr; }} while(false)
#define SafeDeleteArray(__Ptr)						do { if(__Ptr) { delete[] __Ptr; __Ptr = nullptr; }} while(false)

enum class EConsoleTextColor
	: int16_t
{
	Invalid = -1
	, Default = 37
	, Black = 90
	, Red = 91
	, Green = 92
	, Yellow = 93
	, Blue = 94
	, Magenta = 95
	, Cyan = 96
	, White = 97
	, Count = 10
};

enum class EWriteMode
	: int8_t
{
	Invalid = -1
	, Out
	, App
	, Count
};