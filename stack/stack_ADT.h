#pragma once
template <typename Elem>
class Stack {
public:
	virtual void clear() = 0;
	virtual bool push(const Elem&) = 0;
	virtual bool pop(Elem&) = 0;
	virtual bool topValue(Elem&) = 0;
	virtual int length() const = 0;
};
