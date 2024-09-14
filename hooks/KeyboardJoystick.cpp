#include "pch-il2cpp.h"
#include "_hooks.h"
#include "state.hpp"

void dKeyboardJoystick_Update(KeyboardJoystick* __this, MethodInfo* method) {
    if (State.ShowHookLogs) LOG_DEBUG("Hook dKeyboardJoystick_Update executed");
    if ((!State.FreeCam && !State.playerToAttach.has_value()) || State.PanicMode) {
        app::KeyboardJoystick_Update(__this, method);
    }
    else
        __this->fields.del = app::Vector2(); //Reset to zero
}

void dScreenJoystick_FixedUpdate(ScreenJoystick* __this, MethodInfo* method)
{
    if (State.ShowHookLogs) LOG_DEBUG("Hook dScreenJoystick_FixedUpdate executed");
    static int countdown;
    if ((!State.FreeCam && !State.playerToAttach.has_value()) || State.PanicMode) {
        app::ScreenJoystick_FixedUpdate(__this, method);
        countdown = 3; //This is necessary for mouseup to zero out the delta movement
    }
    else if (countdown > 0) {
        app::ScreenJoystick_FixedUpdate(__this, method);
        countdown--;
    }
    
}