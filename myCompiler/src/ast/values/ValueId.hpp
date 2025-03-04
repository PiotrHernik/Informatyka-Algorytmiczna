#include <memory>

#include "Value.hpp"
#include "Identifier.hpp"


class ValueId : public Value
{
public:
    ValueId(std::shared_ptr<Identifier>, const Location&);
private:
    std::shared_ptr<Identifier> identifier_;
};