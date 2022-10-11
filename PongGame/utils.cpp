using s8 = char;
using u8 = unsigned char;

using s16 = short;
using u16 = unsigned short;

using s32 = int;
using u32 = unsigned int;

using s64 = long long;
using u64 = unsigned long long;

inline int
clamp(int min, int val, int max)
{
	if (val < min)
		return min;
	if (val > max)
		return max;
	return val;
}
