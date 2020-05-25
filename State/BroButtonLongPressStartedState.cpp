#include "State/BroButtonLongPressStartedState.h"
#include "State/BroButtonLongPressStoppedState.h"

void BroButtonLongPressStartedState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (!isButtonPressed)
    {
        SetStopTime(milliseconds);
        TransitionTo(new BroButtonLongPressStoppedState());
    }
}