#include "BroButtonStateBase.h"
#include "BroButtonStates.h"
#include "BroButton.h"

void BroButtonStateBase::Tick(const bool &isButtonPressed, const unsigned long &milliseconds)
{
}
void BroButtonStateBase::SetContext(BroButton *context)
{
    _context = context;
}
void BroButtonStateBase::SetStartTime(const unsigned long &milliseconds)
{
    _context->_startTime = milliseconds;
}

void BroButtonStateBase::SetStopTime(const unsigned long &milliseconds)
{
    _context->_stopTime = milliseconds;
}
bool BroButtonStateBase::IsDebounceExpiredWithStartTime(const unsigned long &milliseconds)
{
    return milliseconds - _context->_startTime > _context->_debounceTicks;
}
bool BroButtonStateBase::IsDebounceExpiredWithStopTime(const unsigned long &milliseconds)
{
    return milliseconds - _context->_stopTime > _context->_debounceTicks;
}
bool BroButtonStateBase::IsClickTicksExpired(const unsigned long &milliseconds)
{
    return milliseconds - _context->_startTime > _context->_clickTicks;
}
bool BroButtonStateBase::IsPressTicksExpired(const unsigned long &milliseconds)
{
    return milliseconds - _context->_startTime > _context->_pressTicks;
}
bool BroButtonStateBase::ContainsDoubleClickHandler()
{
    return _context->_onDoubleClickCallbackFunc != nullptr;
}
void BroButtonStateBase::TransitionTo(BroButtonStateBase *state)
{
    _context->TransitionTo(state);
}
void BroButtonStateBase::RaiseLongPressStartIfNotNull()
{
    if (_context->_onLongPressStartCallbackFunc != nullptr)
        _context->_onLongPressStartCallbackFunc();
}
void BroButtonStateBase::RaiseClickIfNotNull()
{
    if (_context->_onClickCallbackFunc != nullptr)
        _context->_onClickCallbackFunc();
}
void BroButtonStateBase::RaiseLongPressStopIfNotNull()
{
    if (_context->_onLongPressStopCallbackFunc != nullptr)
        _context->_onLongPressStopCallbackFunc();
}
void BroButtonStateBase::RaiseDoubleClickIfNotNull()
{
    if (_context->_onDoubleClickCallbackFunc != nullptr)
        _context->_onDoubleClickCallbackFunc();
}