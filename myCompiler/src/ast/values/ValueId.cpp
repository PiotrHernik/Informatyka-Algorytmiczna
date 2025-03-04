#include "values/ValueId.hpp"

ValueId::ValueId(std::shared_ptr<Identifier> identifier, const Location& loc) 
    : Value(loc), identifier_(identifier) {}