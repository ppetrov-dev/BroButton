#include "State/BroButtonSingleClickCandidateState.h"
#include "State/BroButtonNormalState.h"
#include "State/BroButtonSingleClickState.h"
#include "State/BroButtonLongPressCandidateState.h"

void BroButtonSingleClickCandidateState::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
    if (!isButtonPressed)
    {
        if (IsDebounceExpiredWithStartTime(milliseconds))
        {
            SetStopTime(milliseconds);
            TransitionTo(new BroButtonSingleClickState());
        }
        else
            TransitionTo(new BroButtonNormalState());
    }
    else if (IsPressTicksExpired(milliseconds))
        TransitionTo(new BroButtonLongPressCandidateState());
}
