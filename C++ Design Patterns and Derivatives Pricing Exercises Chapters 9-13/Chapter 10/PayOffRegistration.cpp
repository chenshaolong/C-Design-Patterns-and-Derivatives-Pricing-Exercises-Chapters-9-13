// C++ Design Patterns and Derivatives Pricing---Listing 10.4, page 182

#include "PayOffConstructible.h"

namespace
{
	PayOffHelper<PayOffCall> RegisterCall("call");
	PayOffHelper<PayOffPut> RegisterPut("put");
}