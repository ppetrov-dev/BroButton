#include "State/BroButtonLongPressCandidateState.h"
#include "State/BroButtonLongPressStartedState.h"

void BroButtonLongPressCandidateState::RaiseEventIfNeeded()
{
    RaiseLongPressStartIfNotNull();
    TransitionTo(new BroButtonLongPressStartedState());
}
