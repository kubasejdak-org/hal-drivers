/////////////////////////////////////////////////////////////////////////////////////
///
/// @file
/// @author Kuba Sejdak
/// @copyright BSD 2-Clause License
///
/// Copyright (c) 2020-2023, Kuba Sejdak <kuba.sejdak@gmail.com>
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
///
/// 1. Redistributions of source code must retain the above copyright notice, this
///    list of conditions and the following disclaimer.
///
/// 2. Redistributions in binary form must reproduce the above copyright notice,
///    this list of conditions and the following disclaimer in the documentation
///    and/or other materials provided with the distribution.
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
/// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
/// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
/// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
/// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
/// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
/// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
/// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
/////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <fmt/core.h>

#include <string_view>

namespace hal::gpio::mcp23x17 {

/// Represents used register addresses of the BANK0 mode in the MCP23x17 device.
enum Bank0 {
    eIODIRA = 0x00,
    eIODIRB = 0x01,
    eIOCON = 0x0a,
    eGPIOA = 0x12,
    eGPIOB = 0x13
};

/// Represents flag for setting individual bits of the IOCON register in the MCP23x17 device.
enum IOCON {
    eHAEN = (1U << 3U)
};

/// Represents id of the 8-bit port in the MCP23x17 device.
enum class Port {
    eGpioA,
    eGpioB
};

} // namespace hal::gpio::mcp23x17

template <>
struct fmt::formatter<hal::gpio::mcp23x17::Bank0> : fmt::formatter<std::string_view> {
    template <typename FormatContext>
    auto format(hal::gpio::mcp23x17::Bank0 value, FormatContext& ctx)
    {
        std::string_view name;
        switch (value) {
            case hal::gpio::mcp23x17::Bank0::eIODIRA: name = "IODIRA"; break;
            case hal::gpio::mcp23x17::Bank0::eIODIRB: name = "IODIRB"; break;
            case hal::gpio::mcp23x17::Bank0::eIOCON: name = "IOCON"; break;
            case hal::gpio::mcp23x17::Bank0::eGPIOA: name = "GPIOA"; break;
            case hal::gpio::mcp23x17::Bank0::eGPIOB: name = "GPIOB"; break;
        }

        return fmt::formatter<std::string_view>::format(name, ctx);
    }
};
