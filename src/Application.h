#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <HikAlarmApplication.h>

class Application : public HikAlarmApplication {
public:
    Application(int argc, char* argv[]);
    ~Application();

protected:
    void onNewClient(AlarmClient*) override final;
};

#endif /* APPLICATION_HPP */
