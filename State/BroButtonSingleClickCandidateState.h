#ifndef BroButtonSingleClickCandidateStateH
#define BroButtonSingleClickCandidateStateH

#include <State/BroButtonStateBase.h>

class BroButtonSingleClickCandidateState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};

#endif //BroButtonSingleClickCandidateStateH