#include <vector>
#include <string>

class Arithmetics
{
public:

static const int asmMultiplySize = 75;
static const int asmDivideSize = 107;

static int rtntAddressMultiply;
static int rtntAddressDivide;

static std::vector<std::string> multiply();
static std::vector<std::string> divide();
};