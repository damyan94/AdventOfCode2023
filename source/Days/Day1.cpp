#include "stdafx.h"

#include "Days/Day1.h"

static constexpr int32_t s_IntegersCount = 9;
static constexpr const char* s_SpelledIntegers[s_IntegersCount]
{
	"one"
	, "two"
	, "three"
	, "four"
	, "five"
	, "six"
	, "seven"
	, "eight"
	, "nine"
};

////////////////////////////////////////////////////////////////////////////////
static bool IsCharInteger(char ch)
{
	return '0' <= ch && '9' >= ch;
}

////////////////////////////////////////////////////////////////////////////////
static std::pair<int32_t, int32_t> ExtractAllUnspelledIntegers(const std::string& str)
{
	std::pair<int32_t, int32_t> result{0, 0};

	// Find leftmost integer
	for (int32_t i = 0; i < str.size(); i++)
	{
		if (IsCharInteger(str[i]))
		{
			result.first = str[i] - '0';
			break;
		}
	}

	// Find rightmost integer
	for (int32_t i = str.size() - 1; i >= 0; i--)
	{
		if (IsCharInteger(str[i]))
		{
			result.second = str[i] - '0';
			break;
		}
	}

	return result;
}

////////////////////////////////////////////////////////////////////////////////
static std::pair<int32_t, int32_t> ExtractAllIntegers(const std::string& str)
{
	std::pair<int32_t, int32_t> result{ 0, 0 };

	// Find leftmost integer
	for (int32_t i = 0; i < str.size(); i++)
	{
		if (IsCharInteger(str[i]))
		{
			result.first = str[i] - '0';
		}
		else
		{
			for (int32_t j = 0; j < s_IntegersCount; j++)
			{
				const auto wordSize = strlen(s_SpelledIntegers[j]);
				if (strcmp(str.substr(i, wordSize).c_str(), s_SpelledIntegers[j]) == 0)
				{
					result.first = j + 1;
					break;
				}
			}
		}

		BreakIf(result.first != 0);
	}

	// Find rightmost integer
	for (int32_t i = str.size() - 1; i >= 0; i--)
	{
		if (IsCharInteger(str[i]))
		{
			result.second = str[i] - '0';
		}
		else
		{
			for (int32_t j = 0; j < s_IntegersCount; j++)
			{
				const auto wordSize = strlen(s_SpelledIntegers[j]);
				const int32_t offset = i - wordSize + 1;
				ContinueIf(offset < 0);

				if (strcmp(str.substr(offset, wordSize).c_str(), s_SpelledIntegers[j]) == 0)
				{
					result.second = j + 1;
					break;
				}
			}
		}

		BreakIf(result.second != 0);
	}

	return result;
}

////////////////////////////////////////////////////////////////////////////////
void Day1::Execute()
{
	std::vector<std::string> lines;
	ReturnUnless(Utils::ReadFromFile("../Input/1.txt", lines));

	m_ResultPart1 = ExecuteInternal(lines, ExtractAllUnspelledIntegers);
	m_ResultPart2 = ExecuteInternal(lines, ExtractAllIntegers);
}

////////////////////////////////////////////////////////////////////////////////
void Day1::Print() const
{
	Log::Console("Result part 1: %i", m_ResultPart1);
	Log::Console("Result part 2: %i", m_ResultPart2);
}

////////////////////////////////////////////////////////////////////////////////
int32_t Day1::ExecuteInternal(const std::vector<std::string>& lines, ExtractionFunctionType fn) const
{
	int32_t result = 0;

	for (const auto& line : lines)
	{
		auto integers = fn(line);
		ContinueIf(integers.first == 0 || integers.second == 0);

		int32_t integerToSum = integers.first * 10 + integers.second;
		result += integerToSum;
	}

	return result;
}