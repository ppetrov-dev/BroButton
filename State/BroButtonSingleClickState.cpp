#include "State/BroButtonSingleClickState.h"
#include "State/BroButtonSingleClickedState.h"
#include "State/BroButtonDoubleClickCandidateState.h"

void BroButtonSingleClickState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (!ContainsDoubleClickHandler() || IsClickTicksExpired(milliseconds))
        TransitionTo(new BroButtonSingleClickedState());
    else if (isButtonPressed && IsDebounceExpiredWithStopTime(milliseconds))
    {
        SetStartTime(milliseconds);
        TransitionTo(new BroButtonDoubleClickCandidateState());
    }
}
