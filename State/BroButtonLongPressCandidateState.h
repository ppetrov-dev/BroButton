#ifndef BroButtonLongPressCandidateStateH
#define BroButtonLongPressCandidateStateH

#include <State/BroButtonStateBase.h>

class BroButtonLongPressCandidateState : public BroButtonStateBase
{
public:
    void RaiseEventIfNeeded() override;
};

#endif //BroButtonLongPressCandidateStateH