#ifndef GETCONFIG_H
#define GETCONFIG_H

class TestDesktopConfig
{
public:
    int TaskBarHeight = 40;
    int StartMenuHeight = 400;
};

extern const TestDesktopConfig* GetConfig();

#endif // GETCONFIG_H
