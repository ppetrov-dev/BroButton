#ifndef BroButtonDoubleClickingStateH
#define BroButtonDoubleClickingStateH

#include <State/BroButtonStateBase.h>

class BroButtonDoubleClickingState : public BroButtonStateBase
{
public:
    void RaiseEventIfNeeded() override;
};

#endif //BroButtonDoubleClickingStateH