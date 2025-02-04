#pragma once


#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
#include <initializer_list>


#include "../ast/Identifier.hpp"
#include "../ast/Value.hpp"
#include "../ast/Condition.hpp"
#include "../ast/Expression.hpp"
#include "../ast/Args.hpp"
#include "../ast/ArgsDeclaration.hpp"
#include "../ast/Declaration.hpp"
#include "../ast/ProcHead.hpp"
#include "../ast/ProcCall.hpp"
#include "../ast/Command.hpp"
#include "../ast/Procedure.hpp"
#include "../ast/Main.hpp"
#include "../SymbolTable/SymbolTable.hpp"
#include "../ast/Node.hpp"
#include "../ast/Enums.hpp"
#include "../ast/Ast.hpp"


#include "../astUtilities/makeArgs.hpp"
#include "../astUtilities/makeArgsDeclaration.hpp"
#include "../astUtilities/makeCommands.hpp"
#include "../astUtilities/makeDeclarations.hpp"
#include "../astUtilities/makeIdentifier.hpp"
#include "../astUtilities/makeProcCall.hpp"
#include "../astUtilities/makeProcedures.hpp"
#include "../astUtilities/makeProcHead.hpp"


