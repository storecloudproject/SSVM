// SPDX-License-Identifier: Apache-2.0
#include "interpreter/engine/provider.h"

namespace SSVM {
namespace Interpreter {

/// Getter for next instruction. See "include/interpreter/engine/provider.h".
const AST::Instruction *InstrProvider::getNextInstr() {
  /// Instruction sequence vector is empty.
  if (Iters.size() == 0) {
    return nullptr;
  }

  /// Instruction sequence executed to end.
  if (Iters.back().Curr == Iters.back().End) {
    return nullptr;
  }

  /// Get instruction.
  const AST::Instruction *Instr = (*Iters.back().Curr).get();
  (Iters.back().Curr)++;
  return Instr;
}

} // namespace Interpreter
} // namespace SSVM
