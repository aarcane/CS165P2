#include "extra.h"
#include <limits>
namespace extra
{
static const size_t size_t_highMask[] = 
	{
0xFFFFFFFFFFFFFFFF,
0xFFFFFFFFFFFFFFFE,
0xFFFFFFFFFFFFFFFC,
0xFFFFFFFFFFFFFFF8,
0xFFFFFFFFFFFFFFF0,
0xFFFFFFFFFFFFFFE0,
0xFFFFFFFFFFFFFFC0,
0xFFFFFFFFFFFFFF80,
0xFFFFFFFFFFFFFF00,
0xFFFFFFFFFFFFFE00,
0xFFFFFFFFFFFFFC00,
0xFFFFFFFFFFFFF800,
0xFFFFFFFFFFFFF000,
0xFFFFFFFFFFFFE000,
0xFFFFFFFFFFFFC000,
0xFFFFFFFFFFFF8000,
0xFFFFFFFFFFFF0000,
0xFFFFFFFFFFFE0000,
0xFFFFFFFFFFFC0000,
0xFFFFFFFFFFF80000,
0xFFFFFFFFFFF00000,
0xFFFFFFFFFFE00000,
0xFFFFFFFFFFC00000,
0xFFFFFFFFFF800000,
0xFFFFFFFFFF000000,
0xFFFFFFFFFE000000,
0xFFFFFFFFFC000000,
0xFFFFFFFFF8000000,
0xFFFFFFFFF0000000,
0xFFFFFFFFE0000000,
0xFFFFFFFFC0000000,
0xFFFFFFFF80000000,
0xFFFFFFFF00000000,
0xFFFFFFFE00000000,
0xFFFFFFFC00000000,
0xFFFFFFF800000000,
0xFFFFFFF000000000,
0xFFFFFFE000000000,
0xFFFFFFC000000000,
0xFFFFFF8000000000,
0xFFFFFF0000000000,
0xFFFFFE0000000000,
0xFFFFFC0000000000,
0xFFFFF80000000000,
0xFFFFF00000000000,
0xFFFFE00000000000,
0xFFFFC00000000000,
0xFFFF800000000000,
0xFFFF000000000000,
0xFFFE000000000000,
0xFFFC000000000000,
0xFFF8000000000000,
0xFFF0000000000000,
0xFFE0000000000000,
0xFFC0000000000000,
0xFF80000000000000,
0xFF00000000000000,
0xFE00000000000000,
0xFC00000000000000,
0xF800000000000000,
0xF000000000000000,
0xE000000000000000,
0xC000000000000000,
0x8000000000000000,
0x0
};
static const size_t size_t_lowMask[] = 
	{0x0,	0x0000000000000001,	0x0000000000000003,	0x0000000000000007,	0x000000000000000F,
		0x000000000000001F,	0x000000000000003F,	0x000000000000007F,	0x00000000000000FF,
		0x00000000000001FF,	0x00000000000003FF,	0x00000000000007FF,	0x0000000000000FFF,
		0x0000000000001FFF,	0x0000000000003FFF,	0x0000000000007FFF,	0x000000000000FFFF,
		0x000000000001FFFF,	0x000000000003FFFF,	0x000000000007FFFF,	0x00000000000FFFFF,
		0x00000000001FFFFF,	0x00000000003FFFFF,	0x00000000007FFFFF,	0x0000000000FFFFFF,
		0x0000000001FFFFFF,	0x0000000003FFFFFF,	0x0000000007FFFFFF,	0x000000000FFFFFFF,
		0x000000001FFFFFFF,	0x000000003FFFFFFF,	0x000000007FFFFFFF,	0x00000000FFFFFFFF,
		0x00000001FFFFFFFF,	0x00000003FFFFFFFF,	0x00000007FFFFFFFF,	0x0000000FFFFFFFFF,
		0x0000001FFFFFFFFF,	0x0000003FFFFFFFFF,	0x0000007FFFFFFFFF,	0x000000FFFFFFFFFF,
		0x000001FFFFFFFFFF,	0x000003FFFFFFFFFF,	0x000007FFFFFFFFFF,	0x00000FFFFFFFFFFF,
		0x00001FFFFFFFFFFF,	0x00003FFFFFFFFFFF,	0x00007FFFFFFFFFFF,	0x0000FFFFFFFFFFFF,
		0x0001FFFFFFFFFFFF,	0x0003FFFFFFFFFFFF,	0x0007FFFFFFFFFFFF,	0x000FFFFFFFFFFFFF,
		0x001FFFFFFFFFFFFF,	0x003FFFFFFFFFFFFF,	0x007FFFFFFFFFFFFF,	0x00FFFFFFFFFFFFFF,
		0x01FFFFFFFFFFFFFF,	0x03FFFFFFFFFFFFFF,	0x07FFFFFFFFFFFFFF,	0x0FFFFFFFFFFFFFFF,
		0x1FFFFFFFFFFFFFFF,	0x3FFFFFFFFFFFFFFF,	0x7FFFFFFFFFFFFFFF,	0xFFFFFFFFFFFFFFFF
	};

size_t next_pow_2(const size_t& t)
{	return hb(t) << 1;
}

size_t hb(const size_t& t)
{	size_t highest = std::numeric_limits<size_t>::digits -1;
	size_t lowest = 0;
	size_t oldguess = std::numeric_limits<size_t>::max();
	size_t guess = (highest+lowest)/2;
	if(t == 0 || t == 1) return 1;
	while(highest != lowest)
	{	if((t & size_t_highMask[guess]))
		{	lowest = guess;
		}
		else
		{	highest = guess;
		}
		oldguess = guess;
		guess = (highest + lowest) / 2;
		if(guess == oldguess) {++guess; ++lowest;}
	}
	//guess = std::min(guess, guess - 1);
	return 1 << (guess - 1);
}

}
