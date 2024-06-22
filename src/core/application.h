#pragma once

class application
{
public:
    application();
    virtual ~application();

    application(const application &) = delete;
    application(application &&) = delete;
    application &operator=(const application &) = delete;
    application &operator=(application &&) = delete;

    static application &get() { return *s_instance; }

    virtual void on_create() = 0;
    virtual void on_update(float timestep) = 0;

private:
    static application *s_instance;
};