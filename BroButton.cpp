#include "BroButton.h"
#include "State/BroButtonNormalState.h"

BroButton::BroButton(byte pin, bool isActiveLow, bool isPullupActive)
	: _pin(pin), _isPullupActive(isPullupActive)
{
	_buttonPressedValue = isActiveLow ? LOW : HIGH;
}
BroButton::BroButton(byte pin)
	: BroButton(pin, true, true)
{
}
BroButton::~BroButton()
{
	DisposeStateIfNotNull();
}
void BroButton::Init()
{
	pinMode(_pin, _isPullupActive ? INPUT_PULLUP : INPUT);
	Reset();
}
void BroButton::Reset()
{
	_startTime = 0;
	_stopTime = 0;
	TransitionTo(new BroButtonNormalState());
}
void BroButton::SetDebounceTicks(unsigned long milliseconds)
{
	_debounceTicks = milliseconds;
}
void BroButton::SetClickTicks(unsigned long milliseconds)
{
	_clickTicks = milliseconds;
}
void BroButton::SetPressTicks(unsigned long milliseconds)
{
	_pressTicks = milliseconds;
}
void BroButton::AttachOnLeftHoldTurn(void (*newFunction)())
{
	_onLeftHoldTurnCallbackFunc = newFunction;
}
void BroButton::AttachOnRightHoldTurn(void (*newFunction)())
{
	_onRightHoldTurnCallbackFunc = newFunction;
}
void BroButton::AttachOnClick(void (*newFunction)())
{
	_onClickCallbackFunc = newFunction;
}
void BroButton::AttachOnDoubleClick(void (*newFunction)())
{
	_onDoubleClickCallbackFunc = newFunction;
}
void BroButton::AttachOnLongPressStart(void (*newFunction)())
{
	_onLongPressStartCallbackFunc = newFunction;
}
void BroButton::AttachOnLongPressStop(void (*newFunction)())
{
	_onLongPressStopCallbackFunc = newFunction;
}
int BroButton::GetLastPressedTicks()
{
	return _stopTime - _startTime;
}
void BroButton::DisposeStateIfNotNull()
{
	if (_state == nullptr)
		return;
	delete _state;
}
void BroButton::TransitionTo(BroButtonStateBase *state)
{
	DisposeStateIfNotNull();
	_state = state;
	if (_state == nullptr)
		return;
	_state->SetContext(this);
}
void BroButton::Tick()
{
	auto isButtonPressed = digitalRead(_pin) == _buttonPressedValue;
	auto currenMillis = millis();
	_state->Tick(isButtonPressed, currenMillis);
	_state->RaiseEventIfNeeded();
}
