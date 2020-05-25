#ifndef BroButtonDoubleClickCandidateStateH
#define BroButtonDoubleClickCandidateStateH

#include <State/BroButtonStateBase.h>

class BroButtonDoubleClickCandidateState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};

#endif //BroButtonDoubleClickCandidateStateH