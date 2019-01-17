#ifndef SINGLETONWRAPPER_H
#define SINGLETONWRAPPER_H
#include <iostream>
namespace CoolEngine {

template <typename TYPE>
class SingletonWrapper
{
public:

	// This makes it a singleton
	static TYPE* getInstance()
	{
		if (static_instance == nullptr)
		{
			static_instance = new TYPE();
		}
		return static_instance;
	}

	void destroyInstance() {
		std::cout << "Deleting instance" << std::endl;
		delete static_instance;
	}

protected:
	SingletonWrapper() {};
	virtual ~SingletonWrapper() {};

private:
	static TYPE* static_instance;
	SingletonWrapper(const SingletonWrapper&) = delete;
	const SingletonWrapper& operator= (const SingletonWrapper&) = delete;
};

template <typename TYPE>
TYPE* SingletonWrapper<TYPE>::static_instance = 0;
}

#endif
