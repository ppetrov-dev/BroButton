#ifndef BroButtonSingleClickedStateH
#define BroButtonSingleClickedStateH

#include <State/BroButtonStateBase.h>

class BroButtonSingleClickedState : public BroButtonStateBase
{
public:
    void RaiseEventIfNeeded() override;
};

#endif //BroButtonSingleClickedStateH