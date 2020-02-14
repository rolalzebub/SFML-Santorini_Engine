#include "P_Builder.h"

void P_Builder::move(unsigned short i, unsigned short j)
{
    m_transform->GetTransformable().move(i, j);
}
