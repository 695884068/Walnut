#include <Walnut.h>


class Sanbox : public Walnut::Application
{
public:
	Sanbox()
	{
	}

	~Sanbox()
	{
	}
};

Walnut::Application* Walnut::CreateApplication()
{
	return new Sanbox();
}