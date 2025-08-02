#define PTELS_LN 1
#include "Element.h"

struct Element hydrogen = { .name = "hydrogen", .abbrev = "H", .atnum = 1 };
struct Element ptelements[PTELS_LN];

void init_ptelements()
{
    ptelements[0] = hydrogen;
}
