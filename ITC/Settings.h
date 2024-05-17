#pragma once

class Settings
{
public:
    static Settings& getInstance()
    {
        static Settings instance;
        return instance;
    }

    int ScreenWidth = 1280;
    int ScreenHeight = 960;

private:
    Settings() {}
};