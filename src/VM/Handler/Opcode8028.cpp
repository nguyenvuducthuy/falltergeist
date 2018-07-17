/*
 * Copyright 2012-2018 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// Related headers
#include "../../VM/Handler/Opcode8028.h"

// C++ standard includes

// Falltergeist includes
#include "../../VM/IFalloutContext.h"
#include "../../VM/IFalloutProcedure.h"
#include "../../VM/IFalloutStack.h"
#include "VM/IFalloutValue.h"

// Third party includes

namespace Falltergeist {
    namespace VM {
        namespace Handler {
            void Opcode8028::applyTo(std::shared_ptr<IFalloutContext> context) {
                std::string name = context->dataStack()->pop()->asString();
                context->dataStack()->push((int) context->getProcedureByName(name)->bodyOffset());
            }

            int Opcode8028::number() {
                return 0x8028;
            }

            std::string Opcode8028::name() {
                return "int lookup_string_proc(string getProcedureByIndex)";
            }

            std::string Opcode8028::notes() {
                return "returns getProcedureByIndex address";
            }
        }
    }
}