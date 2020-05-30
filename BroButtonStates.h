#ifndef BroButtonStatesH
#define BroButtonStatesH

#include "BroButtonStateBase.h"

class BroButtonUnreleasedState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};
class BroButtonNormalState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};
class BroButtonSingleClickCandidateState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};
class BroButtonSingleClickState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};
class BroButtonSingleClickedState : public BroButtonStateBase
{
public:
    void RaiseEventIfNeeded() override;
};
class BroButtonDoubleClickCandidateState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};
class BroButtonDoubleClickingState : public BroButtonStateBase
{
public:
    void RaiseEventIfNeeded() override;
};
class BroButtonDoubleClickedState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};
class BroButtonLongPressCandidateState : public BroButtonStateBase
{
public:
    void RaiseEventIfNeeded() override;
};
class BroButtonLongPressStartedState : public BroButtonStateBase
{
public:
    void Tick(const bool &isButtonPressed, const unsigned long &milliseconds) override;
};
class BroButtonLongPressStoppedState : public BroButtonStateBase
{
public:
    void RaiseEventIfNeeded() override;
};
#endif //BroButtonStatesH