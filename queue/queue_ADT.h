#pragma once
template <typename Elem>
class Queue {
public:
	virtual void clear() = 0;

	virtual bool enqueue(const Elem&) = 0;
	virtual bool dequeue(Elem&) = 0;
	virtual bool frontValue(Elem&) = 0;

	virtual int length() const = 0;
};
