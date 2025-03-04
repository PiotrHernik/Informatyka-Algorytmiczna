#include "CommandAssign.hpp"

CommandAssign::CommandAssign(std::shared_ptr<Identifier> identifier, std::shared_ptr<Expression> expression, const Location& loc)
    : Command(loc), identifier_(identifier), expression_(expression) {}