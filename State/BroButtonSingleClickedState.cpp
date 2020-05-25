#include "State/BroButtonSingleClickedState.h"
#include "State/BroButtonNormalState.h"

void BroButtonSingleClickedState::RaiseEventIfNeeded()
{
    RaiseClickIfNotNull();
    TransitionTo(new BroButtonNormalState());
}
