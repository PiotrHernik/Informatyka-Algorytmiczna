#include "CommandRead.hpp"

CommandRead::CommandRead(std::shared_ptr<Identifier> identifier, const Location& loc) : Command(loc), identifier_(identifier) {}