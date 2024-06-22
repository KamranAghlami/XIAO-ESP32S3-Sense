#include "core/application.h"

class example : public application
{
public:
    example()
    {
    }

    ~example()
    {
    }

private:
    void on_create() override
    {
    }

    void on_update(float timestep) override
    {
    }
};

application *create_application()
{
    return new example();
}
