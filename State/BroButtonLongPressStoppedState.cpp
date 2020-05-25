#include "State/BroButtonLongPressStoppedState.h"
#include "State/BroButtonNormalState.h"

void BroButtonLongPressStoppedState::RaiseEventIfNeeded()
{
    RaiseLongPressStopIfNotNull();
    TransitionTo(new BroButtonNormalState());
}
