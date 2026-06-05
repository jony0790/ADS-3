#include <cstdint>
#include "alg.h"
// Collatz ketma-ketligi uzunligi
unsigned int collatzLen(uint64_t num)
{
    unsigned int len = 1;

    while (num != 1)
    {
        if (num & 1)
            num = 3 * num + 1;
        else
            num /= 2;

        ++len;
    }

    return len;
}

// Collatz ketma-ketligidagi maksimal qiymat
uint64_t collatzMaxValue(uint64_t num)
{
    uint64_t maxValue = num;

    while (num != 1)
    {
        if (num & 1)
            num = 3 * num + 1;
        else
            num /= 2;

        if (num > maxValue)
            maxValue = num;
    }

    return maxValue;
}

// [lbound, rbound] oralig'ida eng uzun ketma-ketlik beruvchi son
unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound)
{
    uint64_t bestNum = lbound;
    unsigned int bestLen = 0;

    for (uint64_t n = lbound; n <= rbound; ++n)
    {
        unsigned int len = collatzLen(n);

        if (len > bestLen)
        {
            bestLen = len;
            bestNum = n;
        }
    }

    *maxlen = bestLen;
    return static_cast<unsigned int>(bestNum);
}
